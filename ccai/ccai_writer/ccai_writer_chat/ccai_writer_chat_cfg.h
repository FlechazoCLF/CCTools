
/****************************************************************************************************
* File ccai_writer_chat_cfg.h Start!
****************************************************************************************************/

#ifndef _CCAI_WRITER_CHAT_CFG_H
#define _CCAI_WRITER_CHAT_CFG_H

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

/* cc_ccai_writer_cfg_msg_enum */
typedef enum
{
    CC_CCAI_WRITER_CHAT_CFG_MSG_BUILD = 0,
    CC_CCAI_WRITER_CHAT_CFG_MSG_OPTIMIZE,
    CC_CCAI_WRITER_CHAT_CFG_MSG_END,
}cc_ccai_writer_chat_cfg_msg_enum;

/* cc_ccai_writer_chat_cfg_msg_struct */
typedef struct
{
    /* title */
    QString title;
    QString content;
    /* usercontent */
    QString usercontent;
    /* optimizecontent */
    QString optimizecontent;
}cc_ccai_writer_chat_cfg_msg_struct;

/* cc_ccai_writer_chat_cfg */
typedef struct
{
    cc_uint8 id;
    /* context */
    QString context;
}cc_ccai_writer_chat_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_ccai_writer_chat_cfg_init(cc_void);

cc_result cc_ccai_writer_chat_cfg_buildmsg(QString *content,cc_ccai_writer_chat_cfg_msg_struct *msg,cc_ccai_writer_chat_cfg_msg_enum type);

cc_result cc_ccai_writer_chat_cfg_mainfunction(cc_void);

#endif /* _CCAI_WRITER_CHAT_CFG_H */
/****************************************************************************************************
* File ccai_writer_chat_cfg.h End!
****************************************************************************************************/

