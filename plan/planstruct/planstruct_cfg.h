
/****************************************************************************************************
* File planstruct_cfg.h Start!
****************************************************************************************************/
#ifndef _PLANSTRUCT_CFG_H
#define _PLANSTRUCT_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* map */
typedef enum
{
    PLANSTRUCT_CFG_INFOINDEX_NUM = 0,
    PLANSTRUCT_CFG_INFOINDEX_PROJECT,
    PLANSTRUCT_CFG_INFOINDEX_PROGRESS,
    PLANSTRUCT_CFG_INFOINDEX_STARTTIME,
    PLANSTRUCT_CFG_INFOINDEX_ENDTIME,
    PLANSTRUCT_CFG_INFOINDEX_PATH,
    PLANSTRUCT_CFG_INFOINDEX_COMMENT,
    PLANSTRUCT_CFG_INFOINDEX_END,
}plantruct_cfg_infoindex_enum;

#define PLANSTRUCT_CFG_TABLE_COLUMN_NUM (PLANSTRUCT_CFG_INFOINDEX_END)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
/* planstruct table info cfg */
typedef struct
{
    cc_uint32 cloumn;
    QString name;
}plantruct_cfg_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result plan_struct_cfg_get(plantruct_cfg_struct **plantruct_cfg);

#endif /* _PLANSTRUCT_CFG_H */
/****************************************************************************************************
* File planstruct_cfg.h End!
****************************************************************************************************/

