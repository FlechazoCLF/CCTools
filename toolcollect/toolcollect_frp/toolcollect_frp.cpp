
/****************************************************************************************************
* File toolcollect_frp.c Start!
****************************************************************************************************/

/*
 *
 *  Copyright (c) 2024-2025 by flechazo. All rights reserved.
 *
 * Author : CarlChai LinFeng Chai flechazo
 * Website: flechazo.mba
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-03-26     cc          the first version
 *
*/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "toolcollect_frp.h"
/* log */
/* sub module */
/* components */
#include "toolcollect.h"
#include "toolcollect_frp_cfg.h"
#include "script_cmd.h"

/* ui */
/* cpp */
#include <QObject>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_toolcollect_frp */
cc_toolcollect_frp_struct cc_toolcollect_frp_t;
/* init flag */
cc_boolean cc_toolcollect_frp_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_toolcollect_frp_init()
****************************************************************************************************/
cc_result ToolCollect::cc_toolcollect_frp_init(cc_toolcollect_frp_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        CHECK_LOGIC(result,(cc_toolcollect_frp_initflag == CC_FALSE));
        /* init service */
        /* rx */
        QObject::connect(&cc_toolcollect_frp_t.service,&QProcess::readyRead,this,&ToolCollect::cc_toolcollect_frp_cmd_recv);
        QObject::connect(&cc_toolcollect_frp_t.service,&QProcess::readyReadStandardOutput,this,&ToolCollect::cc_toolcollect_frp_cmd_recv);
        /* error */
        QObject::connect(&cc_toolcollect_frp_t.service,QOverload<QProcess::ProcessError>::of(&QProcess::errorOccurred),this,&ToolCollect::cc_toolcollect_frp_cmd_error_occurred);
        /* finish */
        QObject::connect(&cc_toolcollect_frp_t.service,QOverload<int,QProcess::ExitStatus>::of(&QProcess::finished),this,&ToolCollect::cc_toolcollect_frp_cmd_finish);
        /* init client */
        /* rx */
        QObject::connect(&cc_toolcollect_frp_t.client,&QProcess::readyRead,this,&ToolCollect::cc_toolcollect_frp_cmd_recv);
        QObject::connect(&cc_toolcollect_frp_t.client,&QProcess::readyReadStandardOutput,this,&ToolCollect::cc_toolcollect_frp_cmd_recv);
        /* error */
        QObject::connect(&cc_toolcollect_frp_t.client,QOverload<QProcess::ProcessError>::of(&QProcess::errorOccurred),this,&ToolCollect::cc_toolcollect_frp_cmd_error_occurred);
        /* finish */
        QObject::connect(&cc_toolcollect_frp_t.client,QOverload<int,QProcess::ExitStatus>::of(&QProcess::finished),this,&ToolCollect::cc_toolcollect_frp_cmd_finish);
        
        /* init cfg */
        this->cc_toolcollect_frp_cfg_init();
        /* log */
        cc_toolcollect_frp_t.qtextbrower = cfg_t->qtextbrower;
        cc_toolcollect_frp_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_service_start()
****************************************************************************************************/
cc_result cc_toolcollect_frp_service_start(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_t.path != ""));
        /* impletemenmt */
        /* 1.generate config file */
        cc_toolcollect_frp_cfg_generate_service_config(cc_toolcollect_frp_t.path);
        /* 2.start cmd */
        cc_toolcollect_frp_t.service.start("cmd");
        if (cc_toolcollect_frp_t.service.waitForStarted() != CC_TRUE)
        {
            result = CC_E_NOT_OK;
            qDebug() << cc_toolcollect_frp_t.service.errorString();
            continue;
        }
        /* 3.input cmd */
        QString cmd_cd = "cd " + cc_toolcollect_frp_t.path;
        cc_script_cmd_send(&cc_toolcollect_frp_t.service,cmd_cd);
        QString cmd_start = "frps.exe -c frps.toml";
        cc_script_cmd_send(&cc_toolcollect_frp_t.service,cmd_start);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_service_stop()
****************************************************************************************************/
cc_result cc_toolcollect_frp_service_stop(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_t.path != ""));
        /* impletemenmt */
        cc_toolcollect_frp_t.service.close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_client_start()
****************************************************************************************************/
cc_result cc_toolcollect_frp_client_start(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_t.path != ""));
        /* impletemenmt */
        /* 1.generate config file */
        cc_toolcollect_frp_cfg_generate_client_config(cc_toolcollect_frp_t.path);
        /* 2.start */
        cc_toolcollect_frp_t.client.start("cmd");
        if (cc_toolcollect_frp_t.client.waitForStarted() != CC_TRUE)
        {
            result = CC_E_NOT_OK;
            qDebug() << cc_toolcollect_frp_t.client.errorString();
            continue;
        }
        /* 3.input cmd */
        QString cmd_cd = "cd " + cc_toolcollect_frp_t.path;
        cc_script_cmd_send(&cc_toolcollect_frp_t.client,cmd_cd);
        QString cmd_start = "frpc.exe -c frpc.toml";
        cc_script_cmd_send(&cc_toolcollect_frp_t.client,cmd_start);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_client_stop()
****************************************************************************************************/
cc_result cc_toolcollect_frp_client_stop(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_t.path != ""));
        /* impletemenmt */
        cc_toolcollect_frp_t.client.close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_setpath()
****************************************************************************************************/
cc_result cc_toolcollect_frp_setpath(QString path)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(path != ""));
        /* impletemenmt */
        cc_toolcollect_frp_t.path = path;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_script_cmd_recv()
****************************************************************************************************/
cc_void ToolCollect::cc_toolcollect_frp_cmd_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* get process */
        QProcess *currentProcess = qobject_cast<QProcess*>(QObject::sender());
        CHECK_PTR(result,currentProcess);
        /* get output */
        QByteArray output = currentProcess->readAllStandardOutput();
        QString text = QString::fromLocal8Bit(output);
        /* print */
        qDebug() << "cmd recv: " << text;
        TOOLCOLLECT_FRP_LOG_PRINT("cmd recv:" + output);

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
cc_void ToolCollect::cc_toolcollect_frp_cmd_error_occurred(QProcess::ProcessError error)
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
cc_void ToolCollect::cc_toolcollect_frp_cmd_finish(int exitCode)
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
* cc_toolcollect_frp_mainfunction()
****************************************************************************************************/
cc_result cc_toolcollect_frp_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File toolcollect_frp.c End!
****************************************************************************************************/

