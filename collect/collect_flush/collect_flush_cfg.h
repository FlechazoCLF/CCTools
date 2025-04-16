
/****************************************************************************************************
* File collect_flush_cfg.h Start!
****************************************************************************************************/

#ifndef _COLLECT_FLUSH_CFG_H
#define _COLLECT_FLUSH_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"

/* log */
/* sub module */
/* components */
#include "file_dir.h"

/* ui */
/* cpp */
#include <QString>
#include <QStringList>

/****************************************************************************************************
* Define
****************************************************************************************************/

/* collect path deep */
#define CC_COLLECT_FLUSH_CFG_PATH_DEEP_MAX (3)
/* button num per row */
#define CC_COLLECT_FLUSH_CFG_BUTTON_ROW_NUM_MAX (4)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_collect_flush_cfg_info_enum */
typedef enum
{
    CC_COLLECT_FLUSH_CFG_INFO_PARENT = 0,
    CC_COLLECT_FLUSH_CFG_INFO_NAME,
    CC_COLLECT_FLUSH_CFG_INFO_URL,
    CC_COLLECT_FLUSH_CFG_INFO_DESCRIPTION,
    CC_COLLECT_FLUSH_CFG_INFO_END
}cc_collect_flush_cfg_info_enum;

/* cc_collect_flush_cfg_info_struct */
typedef struct
{
    /* parent */
    QString parent;
    /* name */
    QString name;
    /* url */
    QString url;
    /* description */
    QString description;
}cc_collect_flush_cfg_info_struct;

/* cc_collect_flush_cfg */
typedef struct
{
    cc_uint8 id;
}cc_collect_flush_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_collect_flush_cfg_init(cc_void);
cc_result cc_collect_flush_cfg_mainfunction(cc_void);
cc_result cc_collect_flush_cfg_get_info(cc_file_dir_struct *dirinfo_t,QList<cc_collect_flush_cfg_info_struct> *infolist,QString content);

#endif /* _COLLECT_FLUSH_CFG_H */
/****************************************************************************************************
* File collect_flush_cfg.h End!
****************************************************************************************************/

