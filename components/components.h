
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef COMPONENTS_H
#define COMPONENTS_H

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
#define COMPONENTS_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMPONENTS,cc_components_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Components;
}

class Components : public QWidget
{
    Q_OBJECT

public:
    explicit Components(QWidget *parent = nullptr);
    ~Components();

private slots:
    void on_pushButton_components_config_open_clicked();

    void on_pushButton_components_config_flush_clicked();

    void on_pushButton_components_operate_import_clicked();

    void on_pushButton_components_operate_export_clicked();

    void on_pushButton_components_operate_openlocal_clicked();

    void on_pushButton_components_operate_openremote_clicked();

private:
    Ui::Components *ui;
};

/* cc_components_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_components_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_components_mainfunction(cc_void);


#endif // COMPONENTS_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
