
/****************************************************************************************************
* File kernel_cfg.h Start!
****************************************************************************************************/

#ifndef _KERNEL_CFG_H
#define _KERNEL_CFG_H

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

/* module */
typedef enum
{
    CC_KERNEL_MODULE_KERNEL = 0,
    CC_KERNEL_MODULE_MAINWINDOW,
    CC_KERNEL_MODULE_CCAI,
    CC_KERNEL_MODULE_CODEEXAMPLE,
    CC_KERNEL_MODULE_COLLECT,
    CC_KERNEL_MODULE_COMMUNICATION,
    CC_KERNEL_MODULE_COMPONENTS,
    CC_KERNEL_MODULE_DRAFT,
    CC_KERNEL_MODULE_FILE,
    CC_KERNEL_MODULE_KNOWLEDGE,
    CC_KERNEL_MODULE_MOMENT,
    CC_KERNEL_MODULE_NAVIGATE,
    CC_KERNEL_MODULE_PLAN,
    CC_KERNEL_MODULE_PROJECT,
    CC_KERNEL_MODULE_PROJECTCOLLECT,
    CC_KERNEL_MODULE_SCRIPT,
    CC_KERNEL_MODULE_TOOLCOLLECT,
    CC_KERNEL_MODULE_END
}cc_kernel_module_enum;

/* kernel_cfg */
typedef struct
{
    cc_uint8 id;
}kernel_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result kernel_cfg_init(cc_void);
cc_result kernel_cfg_mainfunction(cc_void);

#endif /* _KERNEL_CFG_H */
/****************************************************************************************************
* File kernel_cfg.h End!
****************************************************************************************************/

