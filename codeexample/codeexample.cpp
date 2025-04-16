
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "codeexample.h"
/* log */
/* sub module */
#include "codeexample_import.h"
#include "codeexample_import_cfg.h"
#include "codeexample_export.h"
#include "codeexample_export_cfg.h"
#include "codeexample_view.h"
#include "codeexample_view_cfg.h"
/* components */
#include "file_dir.h"
#include "cctools_cfg.h"

/* ui */
#include "ui_codeexample.h"
/* cpp */
#include <QFileDialog>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_codeexample_struct cc_codeexample_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* CodeExample()
****************************************************************************************************/
CodeExample::CodeExample(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CodeExample)
{
    ui->setupUi(this);
    /* file info */
    this->dirinfo_t = new cc_file_dir_struct();
    /* init */
    cc_codeexample_t.qtextbrower = (QTextBrowser *)CC_NULL_PTR;
    this->ui->lineEdit_sidebar_config_path->setText((QString)CCTOOLS_CFG_DATABASE_PATH + "/codeexample");
    this->on_lineEdit_sidebar_config_path_editingFinished();
    /* export */
    cc_codeexample_export_struct cc_codeexample_export_t;
    cc_codeexample_export_t.qtextbrower = cc_codeexample_t.qtextbrower;
    cc_codeexample_export_init(&cc_codeexample_export_t);
    /* import */
    cc_codeexample_import_struct cc_codeexample_import_t;
    cc_codeexample_import_t.qtextbrower = cc_codeexample_t.qtextbrower;
    cc_codeexample_import_init(&cc_codeexample_import_t);
    /* view */
    cc_codeexample_view_struct cc_codeexample_view_t;
    cc_codeexample_view_t.qtextbrower = cc_codeexample_t.qtextbrower;
    cc_codeexample_view_init(&cc_codeexample_view_t);

    /* log */
    CODEEXAMPLE_LOG_PRINT("Init Complete!");
}

CodeExample::~CodeExample()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_sidebar_config_clicked()
****************************************************************************************************/
void CodeExample::on_pushButton_sidebar_config_clicked()
{
    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(this,
                                                              tr("请选择一个目录读取代码例子哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        this->ui->lineEdit_sidebar_config_path->setText(directory);
        /* display */
        cc_codeexample_view_display_list(this->ui->treeWidget_sidebar_codelist_my,this->dirinfo_t,directory);
    }while(0u);
}

/****************************************************************************************************
* on_lineEdit_sidebar_config_path_editingFinished()
****************************************************************************************************/
void CodeExample::on_lineEdit_sidebar_config_path_editingFinished()
{
    /* path change */
    QString directory = this->ui->lineEdit_sidebar_config_path->text();
    /* display */
    cc_codeexample_view_display_list(this->ui->treeWidget_sidebar_codelist_my,this->dirinfo_t,directory);
}

/****************************************************************************************************
* on_treeWidget_sidebar_codelist_my_itemSelectionChanged()
****************************************************************************************************/
void CodeExample::on_treeWidget_sidebar_codelist_my_itemSelectionChanged()
{
    cc_codeexample_view_display_detail(this->ui->textBrowser_view,\
                                       this->ui->treeWidget_sidebar_codelist_my->currentItem(),\
                                       this->dirinfo_t);
}

/****************************************************************************************************
* on_pushButton_sidebar_operate_openlocal_clicked()
****************************************************************************************************/
void CodeExample::on_pushButton_sidebar_operate_openlocal_clicked()
{
    cc_codeexample_view_openlocal(this->ui->treeWidget_sidebar_codelist_my->currentItem(),this->dirinfo_t);
}

/****************************************************************************************************
* on_pushButton_sidebar_operate_openurl_clicked()
****************************************************************************************************/
void CodeExample::on_pushButton_sidebar_operate_openurl_clicked()
{
    cc_codeexample_view_openurl(this->ui->treeWidget_sidebar_codelist_my->currentItem(),this->dirinfo_t);
}

/****************************************************************************************************
* on_pushButton_sidebar_operate_import_clicked()
****************************************************************************************************/
void CodeExample::on_pushButton_sidebar_operate_import_clicked()
{
    cc_codeexample_import_md();
}

/****************************************************************************************************
* on_pushButton_sidebar_operate_export_clicked()
****************************************************************************************************/
void CodeExample::on_pushButton_sidebar_operate_export_clicked()
{
    cc_codeexample_export_md();
}

/****************************************************************************************************
* cc_codeexample_mainfunction()
****************************************************************************************************/
cc_result cc_codeexample_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_codeexample_import_mainfunction();
        cc_codeexample_import_cfg_mainfunction();
        cc_codeexample_export_mainfunction();
        cc_codeexample_export_cfg_mainfunction();
        cc_codeexample_view_mainfunction();
        cc_codeexample_view_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
