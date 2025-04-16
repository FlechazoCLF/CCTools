
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "collect.h"
/* log */
/* sub module */
#include "collect_flush.h"
#include "collect_flush_cfg.h"
/* components */
#include "buttonarray.h"
#include "cctools_cfg.h"

/* ui */
#include "ui_collect.h"
/* cpp */
#include <QFileDialog>
#include <QString>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_collect_struct cc_collect_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* Collect()
****************************************************************************************************/
Collect::Collect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Collect)
{
    ui->setupUi(this);
    /* init */
    cc_collect_t.qtextbrower = this->ui->textBrowser_sidebar_log;
    this->ui->lineEdit_collect_config_path->setText((QString)CCTOOLS_CFG_DATABASE_PATH + "/collect");

    /* init collect flush */
    cc_collect_flush_struct cc_collect_flush_t;
    cc_collect_flush_t.qtextbrower = cc_collect_t.qtextbrower;
    cc_collect_flush_init(&cc_collect_flush_t);
}

Collect::~Collect()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_collect_config_open_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_config_open_clicked()
{
    cc_result result = CC_E_OK;

    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(nullptr,
                                                              QObject::tr("请选择一个目录读取哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            result = CC_E_NOT_OK;
            continue;
        }
        /* set path */
        this->directory = directory;
        qDebug() << "Selected directory:" << directory;
        this->ui->lineEdit_collect_config_path->setText(directory);

    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* on_lineEdit_collect_config_path_editingFinished()
****************************************************************************************************/
void Collect::on_lineEdit_collect_config_path_editingFinished()
{
    this->directory = this->ui->lineEdit_collect_config_path->text();
}

/****************************************************************************************************
* on_lineEdit_collect_config_path_textChanged()
****************************************************************************************************/
void Collect::on_lineEdit_collect_config_path_textChanged(const QString &arg1)
{
    qDebug() << arg1;
    this->directory = this->ui->lineEdit_collect_config_path->text();
}

/****************************************************************************************************
* on_pushButton_collect_config_flush_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_config_flush_clicked()
{
    /* show */
    cc_collect_flush_show(this->directory,this->ui->tab_collect_list_website);
}

/****************************************************************************************************
* on_pushButton_collect_operate_add_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_operate_add_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_collect_operate_delete_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_operate_delete_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_collect_operate_openlocal_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_operate_openlocal_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_collect_operate_openremote_clicked()
****************************************************************************************************/
void Collect::on_pushButton_collect_operate_openremote_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* cc_collect_mainfunction()
****************************************************************************************************/
cc_result cc_collect_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_collect_flush_mainfunction();
        cc_collect_flush_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/

