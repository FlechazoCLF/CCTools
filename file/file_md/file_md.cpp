
/****************************************************************************************************
* File file_md.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "file_md.h"
#include "file_md_cfg.h"
/* log */
/* sub module */
/* components */
#include "file.h"

/* ui */
#include <QTextBrowser>
/* cpp */
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_file_md_struct */
cc_file_md_struct cc_file_md_t;
/* init flag */
cc_boolean cc_file_md_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_file_md_init()
****************************************************************************************************/
cc_result cc_file_md_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init file_md */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_read()
****************************************************************************************************/
cc_result cc_file_md_read(QString *content,QString filepath)
{
    cc_result result = CC_E_OK;
    QFile *file;
    QTextStream *textstream;

    do
    {
        /* check */
        CHECK_PTR(result,content);
        if(!filepath.endsWith(".md"))
        {
            continue;
        }
        /* read */
        file = new QFile(filepath);
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            result = CC_E_NOT_OK;
            continue;
        }
        /* output */
        textstream = new QTextStream(file);
        *content = textstream->readAll();
        /* close */
        file->close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_parse()
****************************************************************************************************/
cc_result cc_file_md_parse(QString *dstcontent,QString srccontent)
{
    cc_result result = CC_E_OK;
    QString html;

    do
    {
        /* check */
        CHECK_PTR(result,dstcontent);
        /* parse */
        cc_file_md_cfg_parse(&html,srccontent);
        /* outpur */
        *dstcontent = html;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_show()
****************************************************************************************************/
cc_result cc_file_md_show(QTextBrowser *textBrowser,QString html)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,textBrowser);
        /* show */
        textBrowser->setHtml(html);
        textBrowser->show();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_display()
****************************************************************************************************/
cc_result cc_file_md_display(QTextBrowser *textBrowser,QString filepath)
{
    cc_result result = CC_E_OK;
    QString content;
    QString html;

    do
    {
        /* check */
        CHECK_PTR(result,textBrowser);
        if(!filepath.endsWith(".md"))
        {
            continue;
        }
        /* read */
        cc_file_md_read(&content,filepath);
        /* parse */
        cc_file_md_parse(&html,content);
        /* show */
        cc_file_md_show(textBrowser,html);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_create()
****************************************************************************************************/
cc_result cc_file_md_create(QString directory,QString name)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(directory != ""));
        CHECK_LOGIC(result,(name != ""));

        /* filename */
        QString file = directory + "/" + name + ".md";
        /* create */
        cc_file_create(file,"");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_delete()
****************************************************************************************************/
cc_result cc_file_md_delete(QString filepath)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filepath != ""));
        /* delete */
        cc_file_delete(filepath);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_write()
****************************************************************************************************/
cc_result cc_file_md_write(QString filepath,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filepath != ""));
        CHECK_LOGIC(result,(content != ""));

        /* filename */
        cc_file_write(filepath,content,CC_FILE_WRITEMODE_WRITEONLY);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_plan_create()
****************************************************************************************************/
cc_result cc_file_md_plan_create(QString directory,QString name)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(directory != ""));
        CHECK_LOGIC(result,(name != ""));

        /* filename */
        QString file = directory + "/" + name + ".md";
        /* file content */
        QString content;
        cc_file_md_cfg_content(&content);
        content.replace("{file_title}",name);
        content.replace("{file_date}",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
        /* create */
        cc_file_create(file,content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_mainfunction()
****************************************************************************************************/
cc_result cc_file_md_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File file_md.c End!
****************************************************************************************************/

