
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef TOOLCOLLECT_H
#define TOOLCOLLECT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
#include "toolcollect_frp.h"

/* ui */
#include <QWidget>
#include <QTextBrowser>
/* cpp */
#include <QProcess>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define TOOLCOLLECT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_TOOLCOLLECT,cc_toolcollect_t.qtextbrower,format,##__VA_ARGS__)

/* cc_toolcollect_type_enum */
typedef enum
{
    CC_TOOLCOLLECT_NULL = 0,
    CC_TOOLCOLLECT_MARKMAP,
    CC_TOOLCOLLECT_END
}cc_toolcollect_enum;
/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class ToolCollect;
}

class ToolCollect : public QWidget
{
    Q_OBJECT

public:
    explicit ToolCollect(QWidget *parent = nullptr);
    ~ToolCollect();
    /* frp init */
    cc_result cc_toolcollect_frp_init(cc_toolcollect_frp_struct *cfg_t);
    cc_void cc_toolcollect_frp_cmd_recv(cc_void);
    cc_void cc_toolcollect_frp_cmd_error_occurred(QProcess::ProcessError error);
    cc_void cc_toolcollect_frp_cmd_finish(int exitCode);
    cc_result cc_toolcollect_frp_cfg_init(cc_void);

private slots:
    void on_lineEdit_toolcollect_frp_config_path_textChanged(const QString &arg1);
    void on_pushButton_toolcollect_frp_config_path_clicked();
    void on_pushButton_toolcollect_frp_config_read_clicked();
    void on_pushButton_toolcollect_frp_view_config_service_clicked();
    void on_pushButton_toolcollect_frp_view_client_clicked();

    void on_pushButton_toolcollect_web_path_open_clicked();

    void on_pushButton_toolcollect_web_path_read_clicked();

private:
    Ui::ToolCollect *ui;
};

/* cc_toolcollect_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_toolcollect_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_toolcollect_mainfunction(cc_void);


#endif // TOOLCOLLECT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
