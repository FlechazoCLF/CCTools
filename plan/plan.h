
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef PLAN_H
#define PLAN_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include "ui_plan.h"
#include <QWidget>
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define PLAN_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_PLAN,cc_plan_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Plan;
}

class Plan : public QWidget
{
    Q_OBJECT

public:
    explicit Plan(QWidget *parent = nullptr);
    ~Plan();

private slots:
    void on_pushButton_pursuit_operate_path_clicked();
    void on_pushButton_pursuit_operate_flush_clicked();
    void on_pushButton_pursuit_operate_showdetail_clicked();
    void on_treeWidget_pursuit_view_table_overview_itemSelectionChanged();
    void on_pushButton_pursuit_operate_edit_clicked();
    void on_pushButton_pursuit_operate_new_clicked();
    void on_pushButton_pursuit_operate_delete_clicked();
    void on_lineEdit_pursuit_operate_path_editingFinished();

    void on_lineEdit_pursuit_operate_path_textChanged(const QString &arg1);

private:
    Ui::Plan *ui;

};

/* cc_plan_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_plan_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_plan_mainfunction(cc_void);


#endif // PLAN_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
