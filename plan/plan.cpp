
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "plan.h"
/* log */
/* sub module */
#include "planstruct.h"
#include "plandetail.h"
#include "planstruct_cfg.h"
/* components */
#include "file.h"
#include "file_md.h"
#include "cctools_cfg.h"

/* ui */
#include "ui_plan.h"
/* cpp */
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_plan_struct cc_plan_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* Plan()
****************************************************************************************************/
Plan::Plan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Plan)
{
    ui->setupUi(this);

    /* default plan */
    this->ui->lineEdit_pursuit_operate_path->setText((QString)CCTOOLS_CFG_DATABASE_PATH + "/plan");
    /* init */
    planstruct_init_struct planstruct_init_t;
    planstruct_init_t.directory = this->ui->lineEdit_pursuit_operate_path->text();
    planstruct_init_t.qTreeWidget = this->ui->treeWidget_pursuit_view_table_overview;

    plan_struct_init(&planstruct_init_t);
    /* log */
    cc_plan_t.qtextbrower = this->ui->textBrowser_info;
}

Plan::~Plan()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_path_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_path_clicked()
{
    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(this,
                                                              tr("请选择一个目录读取计划哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        /* set path */
        qDebug() << "Selected directory:" << directory;
        /* show */
        this->ui->lineEdit_pursuit_operate_path->setText(directory);
        /* finish */
        on_lineEdit_pursuit_operate_path_editingFinished();
    }while(0u);
}

/****************************************************************************************************
* on_lineEdit_pursuit_operate_path_editingFinished()
****************************************************************************************************/
void Plan::on_lineEdit_pursuit_operate_path_editingFinished()
{
    /* init */
    planstruct_init_struct planstruct_init_t;
    planstruct_init_t.directory = this->ui->lineEdit_pursuit_operate_path->text();
    planstruct_init_t.qTreeWidget = this->ui->treeWidget_pursuit_view_table_overview;
    plan_struct_init(&planstruct_init_t);
}

/****************************************************************************************************
* on_lineEdit_pursuit_operate_path_textChanged()
****************************************************************************************************/
void Plan::on_lineEdit_pursuit_operate_path_textChanged(const QString &arg1)
{
    /* impletement */
    qDebug() << arg1;
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_flush_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_flush_clicked()
{
    do
    {
        /* read */
        plan_struct_read(plan_struct_getinitcfg()->directory,plan_struct_getroot());
        /* clear */
        this->ui->treeWidget_pursuit_view_table_overview->clear();
        /* push */
        plan_struct_push(plan_struct_getroot());
    }while(0u);
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_showdetail_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_showdetail_clicked()
{
    cc_plan_detail_struct plan_detail_t;

    do
    {
        /* get current path */
        plan_detail_t.filepath = this->ui->treeWidget_pursuit_view_table_overview->currentItem()?\
                                    this->ui->treeWidget_pursuit_view_table_overview->currentItem()->text(PLANSTRUCT_CFG_INFOINDEX_PATH):\
                                     "";
        plan_detail_t.qWidget = this->ui->widget_pursuit_view_table_detail;
        /* show */
        cc_plan_detail_show(&plan_detail_t);
    }while(0u);
}

/****************************************************************************************************
* on_treeWidget_pursuit_view_table_overview_itemSelectionChanged()
****************************************************************************************************/
void Plan::on_treeWidget_pursuit_view_table_overview_itemSelectionChanged()
{
    this->on_pushButton_pursuit_operate_showdetail_clicked();
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_edit_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_edit_clicked()
{
    QString filepath = this->ui->treeWidget_pursuit_view_table_overview->currentItem()?\
                        this->ui->treeWidget_pursuit_view_table_overview->currentItem()->text(PLANSTRUCT_CFG_INFOINDEX_PATH):\
                        "";
    cc_file_open(filepath);
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_new_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_new_clicked()
{
    cc_result result = CC_E_OK;
    QString path = this->ui->treeWidget_pursuit_view_table_overview->currentItem()?\
                    this->ui->treeWidget_pursuit_view_table_overview->currentItem()->text(PLANSTRUCT_CFG_INFOINDEX_PATH):\
                    QDir::currentPath();
    do
    {
        /* 1.path */
        QString directory = QFileDialog::getExistingDirectory(this,
                                                              tr("请选择一个目录创建计划哦🍔"),
                                                              path,
                                                              QFileDialog::ShowDirsOnly);
        /* check path */
        CHECK_LOGIC(result,(directory != ""));
        /* 2.name */
        bool flag;
        QString name = QInputDialog::getText(this,
                                             "plan create",
                                             "请输入计划的名称:",
                                             QLineEdit::Normal,
                                             "",
                                             &flag
                                             );
        /* check name */
        CHECK_LOGIC(result,(flag == CC_TRUE));
        CHECK_LOGIC(result,(directory != ""));
        /* 3.create */
        cc_file_md_plan_create(directory,name);
        /* info */
        int ret = QMessageBox::question(this,
                                        "创建完成啦",
                                        "是否立即打开该计划？",
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::No
                                        );
        if(ret == 0)
        {

        }
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

/****************************************************************************************************
* on_pushButton_pursuit_operate_delete_clicked()
****************************************************************************************************/
void Plan::on_pushButton_pursuit_operate_delete_clicked()
{
    QString filepath = this->ui->treeWidget_pursuit_view_table_overview->currentItem()?\
                       this->ui->treeWidget_pursuit_view_table_overview->currentItem()->text(PLANSTRUCT_CFG_INFOINDEX_PATH):\
                       "";
    cc_file_delete(filepath);
}

/****************************************************************************************************
* cc_plan_mainfunction()
****************************************************************************************************/
cc_result cc_plan_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_plan_struct_mainfunction();
        cc_plan_detail_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* End File
****************************************************************************************************/
