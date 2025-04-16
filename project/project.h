
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef PROJECT_H
#define PROJECT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
#include "project_codestruct_cfg.h"
/* components */

/* ui */
#include <QWidget>
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define PROJECT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_PROJECT,cc_project_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Project;
}

class Project : public QWidget
{
    Q_OBJECT

public:
    explicit Project(QWidget *parent = nullptr);
    ~Project();

private slots:
    void on_pushButton_projectcreate_path_clicked();
    void on_lineEdit_projectcreate_path_editingFinished();
    void on_pushButton_projectcreate_tool_operate_create_workstruct_clicked();
    void on_pushButton_projectcreate_tool_operate_create_codestruct_clicked();
    void on_pushButton_projectdoc_path_clicked();
    void on_pushButton_projectdoc_operate_add_clicked();
    void on_pushButton_projectdoc_operate_delete_clicked();
    void on_pushButton_projectdoc_operate_open_clicked();
    void on_pushButton_projectdoc_operate_read_clicked();
    void on_pushButton_projectimport_components_control_open_clicked();
    void on_pushButton_projectimport_components_control_read_clicked();
    void on_pushButton_projectimport_operate_import_clicked();
    void on_pushButton_projectimport_operate_delete_clicked();
    void on_pushButton_projectimport_operate_export_clicked();
    void on_pushButton_projectimport_project_control_open_clicked();
    void on_pushButton_projectimport_project_control_read_clicked();
    void on_pushButton_projectmanage_open_clicked();
    void on_pushButton_projectmanage_read_clicked();
    void on_pushButton_projectmanage_git_send_clicked();
    void on_pushButton_projectmanage_git_add_clicked();
    void on_pushButton_projectmanage_git_commit_clicked();
    void on_pushButton_projectmanage_git_push_clicked();

private:
    Ui::Project *ui;
    QString directory;
};

/* cc_project_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_project_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_project_mainfunction(cc_void);


#endif // PROJECT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
