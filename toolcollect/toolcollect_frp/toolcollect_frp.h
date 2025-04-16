
/****************************************************************************************************
* File toolcollect_frp.h Start!
****************************************************************************************************/

#ifndef _TOOLCOLLECT_FRP_H
#define _TOOLCOLLECT_FRP_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QProcess>
#include <QTextBrowser>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define TOOLCOLLECT_FRP_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_TOOLCOLLECT,cc_toolcollect_frp_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_toolcollect_frp */
typedef struct
{
    cc_uint8 id;
    QProcess service;
    QProcess client;
    QString path;
    /* log */
    QTextBrowser *qtextbrower;
}cc_toolcollect_frp_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_toolcollect_frp_mainfunction(cc_void);
cc_result cc_toolcollect_frp_setpath(QString path);
cc_result cc_toolcollect_frp_service_start(cc_void);
cc_result cc_toolcollect_frp_service_stop(cc_void);
cc_result cc_toolcollect_frp_client_start(cc_void);
cc_result cc_toolcollect_frp_client_stop(cc_void);

#endif /* _TOOLCOLLECT_FRP_H */
/****************************************************************************************************
* File toolcollect_frp.h End!
****************************************************************************************************/

