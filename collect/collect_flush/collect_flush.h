
/****************************************************************************************************
* File collect_flush.h Start!
****************************************************************************************************/

#ifndef _COLLECT_FLUSH_H
#define _COLLECT_FLUSH_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "collect_flush_cfg.h"
/* log */
/* sub module */
/* components */
#include "file_dir.h"

/* ui */
#include <QWidget>
/* cpp */
#include <QString>
/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COLLECT_FLUSH_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COLLECT,cc_collect_flush_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_collect_flush */
typedef struct
{
    cc_uint8 id;
    cc_file_dir_struct *dirinfo_root_t;
    /* collect info */
    QList<cc_collect_flush_cfg_info_struct> infolist;
    /* log */
    QTextBrowser *qtextbrower;
}cc_collect_flush_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_collect_flush_init(cc_collect_flush_struct *cfg);
cc_result cc_collect_flush_mainfunction(cc_void);
cc_result cc_collect_flush_show(QString directory,QWidget *qwidget);

#endif /* _COLLECT_FLUSH_H */
/****************************************************************************************************
* File collect_flush.h End!
****************************************************************************************************/

