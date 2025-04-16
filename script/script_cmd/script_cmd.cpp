
/****************************************************************************************************
* File script_cmd.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "script_cmd.h"
#include "script.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include "qdebug.h"
#include <QStringList>
#include <QProcess>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_script_cmd */
cc_script_cmd_struct cc_script_cmd_t;
/* init flag */
cc_boolean cc_script_cmd_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_script_cmd_init()
****************************************************************************************************/
cc_result Script::cc_script_cmd_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_script_cmd_initflag != CC_TRUE));
        /* impletement */
        cc_script_cmd_t.process = new QProcess();
        cc_script_cmd_t.process->setProcessChannelMode(QProcess::MergedChannels);
        cc_script_cmd_t.process->setProgram("cmd.exe");
        cc_script_cmd_t.process->setArguments({"/k"});
        /* connect */
        /* rx */
        QObject::connect(cc_script_cmd_t.process,&QProcess::readyRead,this,&Script::cc_script_cmd_recv);
        QObject::connect(cc_script_cmd_t.process,&QProcess::readyReadStandardOutput,this,&Script::cc_script_cmd_recv);
        /* error */
        QObject::connect(cc_script_cmd_t.process,QOverload<QProcess::ProcessError>::of(&QProcess::errorOccurred),this,&Script::cc_script_cmd_error_occurred);
        /* finish */
        QObject::connect(cc_script_cmd_t.process,QOverload<int,QProcess::ExitStatus>::of(&QProcess::finished),this,&Script::cc_script_cmd_finish);
        /* start */
        cc_script_cmd_t.process->start();
        /* flag */
        cc_script_cmd_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_init()
****************************************************************************************************/
cc_result Script::cc_script_cmd_create(QProcess *process)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,process);
        /* impletement */
        process->setProcessChannelMode(QProcess::MergedChannels);
        process->setProgram("cmd.exe");
        process->setArguments({"/k"});
        /* connect */
        /* rx */
        QObject::connect(process,&QProcess::readyRead,this,&Script::cc_script_cmd_recv);
        QObject::connect(process,&QProcess::readyReadStandardOutput,this,&Script::cc_script_cmd_recv);
        /* error */
        QObject::connect(process,QOverload<QProcess::ProcessError>::of(&QProcess::errorOccurred),this,&Script::cc_script_cmd_error_occurred);
        /* finish */
        QObject::connect(process,QOverload<int,QProcess::ExitStatus>::of(&QProcess::finished),this,&Script::cc_script_cmd_finish);
        /* start */
        process->start();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_get()
****************************************************************************************************/
cc_result cc_script_cmd_get(QProcess **process)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,process);
        /* impletement */
        *process = cc_script_cmd_t.process;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_start()
****************************************************************************************************/
cc_result Script::cc_script_cmd_start(QProcess *process)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,process);
        /* impletement */
        /* start */
        process->start("cc_script_cmd");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_send()
****************************************************************************************************/
cc_result cc_script_cmd_send(QProcess *process,QString cmd)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,process);
        CHECK_LOGIC(result,(cmd != ""));
        /* send */
        process->write((cmd + "\n").toUtf8());
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_register_recv()
****************************************************************************************************/
cc_void cc_script_cmd_register_recv(cc_uint32 ownerid,\
                                    cc_result (*func)(QProcess *process,QByteArray qbytearray))
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,func);
        /* register */
        cc_script_cmd_recv_struct cc_script_cmd_recv_t;
        cc_script_cmd_recv_t.ownerid = ownerid;
        cc_script_cmd_recv_t.func = func;
        cc_script_cmd_t.recv.append(cc_script_cmd_recv_t);
    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* cc_script_cmd_recv()
****************************************************************************************************/
cc_void Script::cc_script_cmd_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* get process */
        QProcess *currentProcess = qobject_cast<QProcess *>(QObject::sender());
        CHECK_PTR(result,currentProcess);
        /* get output */
        QByteArray output = currentProcess->readAllStandardOutput();
        QString text = QString::fromLocal8Bit(output);
        /* print */
        qDebug() << "cmd recv: " << text;
        for (cc_uint32 i = 0;i < cc_script_cmd_t.recv.count();i++)
        {
            CHECK_PTR(result,cc_script_cmd_t.recv.at(i).func);
            cc_script_cmd_t.recv.at(i).func(cc_script_cmd_t.process,output);
        }
    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* cc_script_cmd_error_occurred()
****************************************************************************************************/
cc_void Script::cc_script_cmd_error_occurred(QProcess::ProcessError error)
{
    cc_result result = CC_E_OK;

    do
    {
        /* get process */
        QProcess *currentProcess = qobject_cast<QProcess*>(QObject::sender());
        CHECK_PTR(result,currentProcess);
        /* get error */
        QString errorMsg = QString("error [%1]: %2").arg(error).arg(currentProcess->errorString());
        /* output */
        qDebug() << errorMsg;
    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* cc_script_cmd_finish()
****************************************************************************************************/
cc_void Script::cc_script_cmd_finish(int exitCode)
{
    cc_result result = CC_E_OK;

    do
    {
        /* get process */
        QProcess *currentProcess = qobject_cast<QProcess*>(QObject::sender());
        CHECK_PTR(result,currentProcess);
        /* exit code */
        QString msg = QString("process exit! error code:%1").arg(exitCode);
        /* output */
        qDebug() << msg;
    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* cc_script_cmd_mainfunction()
****************************************************************************************************/
cc_result cc_script_cmd_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File script_cmd.c End!
****************************************************************************************************/

