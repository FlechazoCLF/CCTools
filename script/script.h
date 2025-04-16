
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef SCRIPT_H
#define SCRIPT_H

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
#include <QProcess>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define SCRIPT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_SCRIPT,cc_script_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Script;
}

class Script : public QWidget
{
    Q_OBJECT

public:
    explicit Script(QWidget *parent = nullptr);
    ~Script();

    cc_result cc_script_cmd_init(cc_void);
    cc_result cc_script_cmd_create(QProcess *process);
    cc_result cc_script_cmd_start(QProcess *process);
    cc_void cc_script_cmd_recv(cc_void);
    cc_void cc_script_cmd_error_occurred(QProcess::ProcessError error);
    cc_void cc_script_cmd_finish(int exitCode);

private:
    Ui::Script *ui;
};

/* cc_script_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_script_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_script_mainfunction(cc_void);


#endif // SCRIPT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
