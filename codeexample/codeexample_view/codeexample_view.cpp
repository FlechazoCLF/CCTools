
/****************************************************************************************************
* File codeexample_view.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "codeexample_view.h"
#include "codeexample.h"
#include "codeexample_view_cfg.h"
/* log */
/* sub module */
/* components */
#include "file_dir.h"
#include "file_md.h"

/* ui */
#include "qtextbrowser.h"
/* cpp */
#include <QString>
#include <QFileInfo>
#include <QDesktopServices>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_codeexample_view */
cc_codeexample_view_struct cc_codeexample_view_t;
/* init flag */
cc_boolean cc_codeexample_view_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_codeexample_view_init()
****************************************************************************************************/
cc_result cc_codeexample_view_init(cc_codeexample_view_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->qtextbrower);
        /* init */
        cc_codeexample_view_t.qtextbrower = cfg_t->qtextbrower;
        /* log */
        CODEEXAMPLE_VIEW_LOG_PRINT("Init Complete!");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_display_list()
****************************************************************************************************/
cc_result cc_codeexample_view_display_list(QTreeWidget *treeWidget,cc_file_dir_struct *dirinfo_t,QString path)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,treeWidget);
        CHECK_PTR(result,dirinfo_t);
        CHECK_LOGIC(result,(path != ""));
        /* clear */
        treeWidget->clear();
        /* get directory info */
        cc_file_dir_getinfo(dirinfo_t,path,CODEEXAMPLE_READDEEP_MAX);
        /* show */
        cc_file_dir_show(dirinfo_t,treeWidget);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_display()
****************************************************************************************************/
cc_result cc_codeexample_view_display_detail(QTextBrowser *textBrowser,QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t)
{
    cc_result result = CC_E_OK;
    QString filepath;

    do
    {
        /* check parameter */
        CHECK_PTR(result,item);
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,textBrowser);

        /* get path */
        cc_file_dir_getpath(&filepath,dirinfo_t,item->text(CC_FILE_DIR_ITEM_COLUMN_NAME));
        /* show detail */
        cc_file_md_display(textBrowser,filepath);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_openlocal()
****************************************************************************************************/
cc_result cc_codeexample_view_openlocal(QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t)
{
    cc_result result = CC_E_OK;
    QString folderpath;

    do
    {
        /* check parameter */
        CHECK_PTR(result,item);
        CHECK_PTR(result,dirinfo_t);

        /* get path */
        cc_file_dir_getpath(&folderpath,dirinfo_t,item->text(CC_FILE_DIR_ITEM_COLUMN_NAME));
        QFileInfo fileInfo(folderpath);
        folderpath = fileInfo.path();

        /* show detail */
        cc_file_dir_open(folderpath);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_geturl()
****************************************************************************************************/
cc_result cc_codeexample_view_geturl(QString *url,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,url);

        /* get path */
        cc_codeexample_view_cfg_geturl(url,content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_openurl()
****************************************************************************************************/
cc_result cc_codeexample_view_openurl(QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t)
{
    cc_result result = CC_E_OK;
    QString folderpath;
    QString content;
    QString strurl;

    do
    {
        /* check parameter */
        CHECK_PTR(result,item);
        CHECK_PTR(result,dirinfo_t);

        /* get path */
        cc_file_dir_getpath(&folderpath,dirinfo_t,item->text(CC_FILE_DIR_ITEM_COLUMN_NAME));
        /* read detail */
        cc_file_md_read(&content,folderpath);
        /* get url */
        cc_codeexample_view_geturl(&strurl,content);
        /* url */
        QUrl url(strurl);
        /* open url */
        if (QDesktopServices::openUrl(url) != CC_TRUE)
        {
            qDebug() << "open url error!";
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_mainfunction()
****************************************************************************************************/
cc_result cc_codeexample_view_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File codeexample_view.c End!
****************************************************************************************************/

