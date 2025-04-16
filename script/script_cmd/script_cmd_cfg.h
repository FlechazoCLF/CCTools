
/****************************************************************************************************
* File script_cmd_cfg.h Start!
****************************************************************************************************/

#ifndef _SCRIPT_CMD_CFG_H
#define _SCRIPT_CMD_CFG_H

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

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_script_cmd_cfg */
typedef struct
{
    cc_uint8 id;
}cc_script_cmd_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_script_cmd_cfg_init(cc_void);
cc_result cc_script_cmd_cfg_mainfunction(cc_void);

#endif /* _SCRIPT_CMD_CFG_H */
/****************************************************************************************************
* File script_cmd_cfg.h End!
****************************************************************************************************/

