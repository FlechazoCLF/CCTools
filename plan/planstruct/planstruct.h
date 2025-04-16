
/****************************************************************************************************
* File planstruct.h Start!
****************************************************************************************************/
#ifndef _PLANSTRUCT_H
#define _PLANSTRUCT_H

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
#include <QTextBrowser>
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define PLAN_STRUCT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_PLAN,planstruct_init_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
/* type */
typedef enum
{
    PLANSTRUCT_TYPE_ITEM = 0,
    PLANSTRUCT_TYPE_CLASS,
    PLANSTRUCT_TYPE_END
}planstruct_type_enum;

/* planstruct */
typedef struct planstruct_struct_T
{
    /* parent */
    struct planstruct_struct_T *parent;
    /* type */
    planstruct_type_enum type;
    /* path */
    QString path;
    /* name */
    QString name;
    /* next */
    struct planstruct_struct_T *next;
    /* children */
    struct planstruct_struct_T *children;
}planstruct_struct;

/* init */
typedef struct
{
    QString directory;
    QTreeWidget *qTreeWidget;

    /* log */
    QTextBrowser *qtextbrower;
}planstruct_init_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result plan_struct_init(planstruct_init_struct *planstruct_init_cfg);
planstruct_struct *plan_struct_getroot(cc_void);
planstruct_init_struct *plan_struct_getinitcfg(cc_void);
cc_result plan_struct_read(QString directory,planstruct_struct *planstruct);
cc_result plan_struct_push(planstruct_struct *planstruct);
cc_result cc_plan_struct_mainfunction(cc_void);



#endif /* _PLANSTRUCT_H */
/****************************************************************************************************
* File planstruct.h End!
****************************************************************************************************/

