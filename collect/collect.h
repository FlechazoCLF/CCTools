
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef COLLECT_H
#define COLLECT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QWidget>
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COLLECT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COLLECT,cc_collect_t.qtextbrower,format,##__VA_ARGS__)
/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Collect;
}

class Collect : public QWidget
{
    Q_OBJECT

public:
    explicit Collect(QWidget *parent = nullptr);
    ~Collect();

private slots:
    void on_pushButton_collect_config_open_clicked();
    void on_pushButton_collect_config_flush_clicked();
    void on_pushButton_collect_operate_add_clicked();
    void on_pushButton_collect_operate_delete_clicked();
    void on_pushButton_collect_operate_openlocal_clicked();
    void on_pushButton_collect_operate_openremote_clicked();
    void on_lineEdit_collect_config_path_editingFinished();
    void on_lineEdit_collect_config_path_textChanged(const QString &arg1);

private:
    Ui::Collect *ui;
    /* path */
    QString directory;
};

/* cc_collect*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_collect_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_collect_mainfunction(cc_void);


#endif // COLLECT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
