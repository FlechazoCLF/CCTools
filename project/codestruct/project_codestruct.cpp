
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "project_codestruct.h"
#include "project_codestruct_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>

/****************************************************************************************************
* Variable
****************************************************************************************************/

/* init */
cc_project_codestruct_struct cc_project_codestruct_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* cc_project_codestruct_init()
****************************************************************************************************/
cc_result cc_project_codestruct_init(cc_project_codestruct_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->QTextEdit_Log);

        /* init log */
        cc_project_codestruct_t.QTextEdit_Log = cfg_t->QTextEdit_Log;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_codestruct_print()
****************************************************************************************************/
cc_result cc_project_codestruct_print(QString str)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cc_project_codestruct_t.QTextEdit_Log);

        /* init log */
        cc_project_codestruct_t.QTextEdit_Log->append(str);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_codestruct_writefile()
****************************************************************************************************/
cc_result cc_project_codestruct_writefile(QString filePath,QString fileContent)
{
    cc_result result = CC_E_OK;
    QFile *file;
    QTextStream *textStream;

    do
    {
        /* check */
        if(filePath == "")
        {
            continue;
        }
        /* open file */
        file = new QFile(filePath);
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            continue;
        }
        /* write file */
        textStream = new QTextStream(file);
        (*textStream) << fileContent;
        /* close file */
        file->close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_codestruct_createfile()
****************************************************************************************************/
cc_result cc_project_codestruct_createfile(cc_project_codestruct_filetype_enum type,QString filePath)
{
    cc_result result = CC_E_OK;
    QFileInfo fileInfo(filePath);
    QString create_filePath;
    QString create_cfgfilePath;
    cc_project_codestruct_cfg_struct *cfg_t = (cc_project_codestruct_cfg_struct *)CC_NULL_PTR;

    do
    {
        /* check */
        if(filePath == "")
        {
            continue;
        }
        if(!fileInfo.exists())
        {
            continue;
        }
        cc_project_codestruct_cfg_getcfg(&cfg_t);
        CHECK_PTR(result,cfg_t);
        /* get file path */
        create_filePath = filePath + "/" + fileInfo.fileName() + cc_project_codestruct_cfg_getpostfix(type);
        create_cfgfilePath = filePath + "/" + fileInfo.fileName() + "_cfg" + cc_project_codestruct_cfg_getpostfix(type);
        /* check */
        if(QFileInfo::exists(create_filePath) && (cfg_t->filetype == "跳过原文件"))
        {
            continue;
        }
        /* create file */
        cc_project_codestruct_writefile(create_filePath,cc_project_codestruct_cfg_content(type,fileInfo.fileName()));
        cc_project_codestruct_print("[信息🎃]创建了一个文件" + create_filePath + "✨");
        /* create cfg file */
        cc_project_codestruct_writefile(create_cfgfilePath,cc_project_codestruct_cfg_content(type,fileInfo.fileName() + "_cfg"));
        cc_project_codestruct_print("[信息🎃]创建了一个文件" + create_cfgfilePath + "✨");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_codestruct_create()
****************************************************************************************************/
cc_result cc_project_codestruct_create(QString path)
{
    cc_result result = CC_E_OK;
    QDir dir(path);
    cc_project_codestruct_filetype_enum type;
    cc_project_codestruct_cfg_struct *cfg_t = (cc_project_codestruct_cfg_struct *)CC_NULL_PTR;

    do
    {
        /* check */
        if(path == "")
        {
            continue;
        }
        if(!dir.exists())
        {
            continue;
        }
        /* get cfg */
        cc_project_codestruct_cfg_getcfg(&cfg_t);
        CHECK_PTR(result,cfg_t);
        /* create & write file */
        type = cc_project_codestruct_getfiletype(cfg_t->codetype);
        cc_project_codestruct_createfile(type,path);
        cc_project_codestruct_createfile(CC_PROJECT_CODESTRUCT_FILETYPE_H,path);
        /* iterator */
        QFileInfoList infolist = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
        for (const QFileInfo &info : infolist)
        {
            if(info.isDir())
            {
                /* is dir */
                cc_project_codestruct_create(info.filePath());
            }
            else if(info.isFile())
            {
                /* is file */
            }
            else
            {

            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* End File
****************************************************************************************************/
