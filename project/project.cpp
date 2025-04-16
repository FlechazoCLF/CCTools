
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "project.h"
/* log */
/* sub module */
#include "project_workstruct.h"
#include "project_codestruct.h"
/* components */

/* ui */
#include "ui_project.h"
/* cpp */
#include <QFileDialog>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_project_struct cc_project_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* Project()
****************************************************************************************************/
Project::Project(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Project)
{
    ui->setupUi(this);
    /* init */
    cc_project_workstruct_struct project_workstruct_t;
    project_workstruct_t.QTextEdit_Log = this->ui->textEdit_projectcreate_tool_operate;
    cc_project_workstruct_init(&project_workstruct_t);
    cc_project_codestruct_struct project_codestruct_t;
    project_codestruct_t.QTextEdit_Log = this->ui->textEdit_projectcreate_tool_operate;
    cc_project_codestruct_init(&project_codestruct_t);

    cc_project_t.qtextbrower = this->ui->textBrowser_info;
}

Project::~Project()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_projectcreate_path_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectcreate_path_clicked()
{
    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(this,
                                                              tr("请选择一个目录存放项目哦🍔"),
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
        this->directory = directory;
        this->ui->lineEdit_projectcreate_path->setText(directory);
        this->ui->textEdit_projectcreate_tool_operate->append("[信息🎃]你选择了一个目录:" + directory);
    }while(0u);
}

/****************************************************************************************************
* on_pushButton_projectcreate_tool_operate_create_workstruct_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectcreate_tool_operate_create_workstruct_clicked()
{
    do
    {
        /* check path */
        if(this->directory.isEmpty())
        {
            this->ui->textEdit_projectcreate_tool_operate->append("[警告🤡]请先选择一个目录哦✨");
            continue;
        }
        /* impletement */
        /* create project struct */
        cc_project_workstruct_create(this->directory);

    }while(0u);
}

/****************************************************************************************************
* on_pushButton_projectcreate_tool_operate_create_codestruct_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectcreate_tool_operate_create_codestruct_clicked()
{
    do
    {
        /* check path */
        if(this->directory.isEmpty())
        {
            this->ui->textEdit_projectcreate_tool_operate->append("[警告🤡]请先选择一个目录哦✨");
            continue;
        }
        /* impletement */
        /* init cfg */
        cc_project_codestruct_cfg_struct cc_project_codestruct_cfg_t;
        cc_project_codestruct_cfg_t.codetype = this->ui->comboBox_projectcreate_tool_option_codetype->currentText();
        cc_project_codestruct_cfg_t.filetype = this->ui->comboBox_projectcreate_tool_option_file->currentText();
        cc_project_codestruct_cfg_t.codefilltype = this->ui->comboBox_projectcreate_tool_option_codefill->currentText();
        cc_project_codestruct_cfg_t.doctype = this->ui->comboBox_projectcreate_tool_option_doc->currentText();
        cc_project_codestruct_cfg_init(&cc_project_codestruct_cfg_t);
        /* create code struct */
        cc_project_codestruct_create(this->directory);
    }while(0u);
}

/****************************************************************************************************
* on_lineEdit_projectcreate_path_editingFinished()
****************************************************************************************************/
void Project::on_lineEdit_projectcreate_path_editingFinished()
{
    do
    {
        /* get path */
        QString directory = this->ui->lineEdit_projectcreate_path->text();
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        /* set path */
        qDebug() << "Selected directory:" << directory;
        this->directory = directory;
        this->ui->lineEdit_projectcreate_path->setText(directory);
        this->ui->textEdit_projectcreate_tool_operate->append("[信息🎃]你选择了一个目录:" + directory);
    }while(0u);
}

/****************************************************************************************************
* on_pushButton_projectdoc_path_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectdoc_path_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectdoc_operate_add_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectdoc_operate_add_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectdoc_operate_delete_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectdoc_operate_delete_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectdoc_operate_open_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectdoc_operate_open_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectdoc_operate_read_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectdoc_operate_read_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_components_control_open_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_components_control_open_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_components_control_read_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_components_control_read_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_operate_import_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_operate_import_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_operate_delete_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_operate_delete_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_operate_export_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_operate_export_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_project_control_open_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_project_control_open_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectimport_project_control_read_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectimport_project_control_read_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_open_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_open_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_read_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_read_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_git_send_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_git_send_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_git_add_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_git_add_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_git_commit_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_git_commit_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_projectmanage_git_push_clicked()
****************************************************************************************************/
void Project::on_pushButton_projectmanage_git_push_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* cc_project_mainfunction()
****************************************************************************************************/
cc_result cc_project_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* End File
****************************************************************************************************/

