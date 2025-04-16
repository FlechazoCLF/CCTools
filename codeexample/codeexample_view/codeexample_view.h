
/****************************************************************************************************
* File codeexample_view.h Start!
****************************************************************************************************/

#ifndef _CODEEXAMPLE_VIEW_H
#define _CODEEXAMPLE_VIEW_H

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
#include "file_dir.h"

/* ui */
#include <QTextBrowser>
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define CODEEXAMPLE_VIEW_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_CODEEXAMPLE,cc_codeexample_view_t.qtextbrower,format,##__VA_ARGS__)
/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_codeexample_view */
typedef struct
{
    cc_uint8 id;
    /* display */
    QTextBrowser *qtextbrower;
}cc_codeexample_view_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_codeexample_view_init(cc_codeexample_view_struct *cfg_t);
cc_result cc_codeexample_view_mainfunction(cc_void);
cc_result cc_codeexample_view_display_list(QTreeWidget *treeWidget,cc_file_dir_struct *dirinfo_t,QString path);
cc_result cc_codeexample_view_display_detail(QTextBrowser *textBrowser,QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t);
cc_result cc_codeexample_view_openlocal(QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t);
cc_result cc_codeexample_view_openurl(QTreeWidgetItem *item,cc_file_dir_struct *dirinfo_t);

#endif /* _CODEEXAMPLE_VIEW_H */
/****************************************************************************************************
* File codeexample_view.h End!
****************************************************************************************************/

