
/****************************************************************************************************
* File script_cmd.h Start!
****************************************************************************************************/

#ifndef _SCRIPT_CMD_H
#define _SCRIPT_CMD_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QTextBrowser>
/* cpp */
#include <QStringList>
#include "qprocess.h"

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define SCRIPT_CMD_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_SCRIPT,cc_script_cmd_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_script_cmd_recv */
typedef struct
{
    cc_uint32 ownerid;
    cc_result (*func)(QProcess *process,QByteArray qbytearray);
}cc_script_cmd_recv_struct;

/* cc_script_cmd */
typedef struct
{
    cc_uint8 id;
    QProcess *process;
    QList<cc_script_cmd_recv_struct> recv;
    /* cc_projectcollect_struct*/

    /* log */
    QTextBrowser *qtextbrower;
}cc_script_cmd_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_script_cmd_get(QProcess **process);
cc_result cc_script_cmd_mainfunction(cc_void);
cc_result cc_script_cmd_send(QProcess *process,QString cmd);
cc_void cc_script_cmd_register_recv(cc_uint32 ownerid,cc_result (*func)(QProcess *process,QByteArray qbytearray));

#endif /* _SCRIPT_CMD_H */
/****************************************************************************************************
* File script_cmd.h End!
****************************************************************************************************/

