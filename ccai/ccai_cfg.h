
/****************************************************************************************************
* File ccai_cfg.h Start!
****************************************************************************************************/

#ifndef _CCAI_CFG_H
#define _CCAI_CFG_H

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

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_ccai_cfg_tools_enum */
typedef enum
{
    CC_CCAI_CFG_TOOLS_CHAT = 0,
    CC_CCAI_CFG_TOOLS_WRITER,
    CC_CCAI_CFG_TOOLS_MUSIC,
    CC_CCAI_CFG_TOOLS_VIDEO,
    CC_CCAI_CFG_TOOLS_FACE,
    CC_CCAI_CFG_TOOLS_SOUND,
    CC_CCAI_CFG_TOOLS_END
}cc_ccai_cfg_tools_enum;

/* cc_ccai_cfg_tools_struct */
typedef struct
{
    cc_ccai_cfg_tools_enum ctrlidx;
    QString name;
}cc_ccai_cfg_tools_struct;

/* cc_ccai_cfg */
typedef struct
{
    cc_uint8 id;
    cc_ccai_cfg_tools_struct toollist[CC_CCAI_CFG_TOOLS_END];
}cc_ccai_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_ccai_cfg_init(cc_void);
cc_result cc_ccai_cfg_mainfunction(cc_void);
cc_result cc_ccai_cfg_get_toolctrlidx(cc_ccai_cfg_tools_enum *ctrlidx,QString name);
cc_result cc_ccai_cfg_recv(QString content);

#endif /* _CCAI_CFG_H */
/****************************************************************************************************
* File ccai_cfg.h End!
****************************************************************************************************/

