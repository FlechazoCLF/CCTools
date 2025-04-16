
/****************************************************************************************************
* File codeexample_import.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "codeexample_import.h"
/* type */
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QFileDialog>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_codeexample_import */
cc_codeexample_import_struct cc_codeexample_import_t;
/* init flag */
cc_boolean cc_codeexample_import_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_codeexample_import_init()
****************************************************************************************************/
cc_result cc_codeexample_import_init(cc_codeexample_import_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->qtextbrower);
        /* init */
        cc_codeexample_import_t.qtextbrower = cfg_t->qtextbrower;
        /* log */
        CODEEXAMPLE_IMPORT_LOG_PRINT("Init Complete!");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_import_md()
****************************************************************************************************/
cc_result cc_codeexample_import_md(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* select src path */
        QString srcfile = QFileDialog::getOpenFileName(nullptr,
                                                       "请选择一个源文件进行导入哦🍔",
                                                       QDir::currentPath(),
                                                       "文件 (*.md)");
        CHECK_LOGIC(result,(srcfile != ""));
        QString dstpath = QFileDialog::getExistingDirectory(nullptr,
                                                            "请选择一个导入目录哦🍔",
                                                            QDir::currentPath(),
                                                            QFileDialog::ShowDirsOnly);
        CHECK_LOGIC(result,(dstpath != ""));
        /* file */
        QFile sourceFile(srcfile);
        CHECK_LOGIC(result,(sourceFile.exists() == CC_TRUE));
        /* dst */
        QString dstfile = dstpath + "/" + sourceFile.fileName().split("/").last();
        ____________________TO_DO____________________
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_import_mainfunction()
****************************************************************************************************/
cc_result cc_codeexample_import_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File codeexample_import.c End!
****************************************************************************************************/

