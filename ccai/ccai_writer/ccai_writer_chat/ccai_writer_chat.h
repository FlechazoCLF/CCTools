
/****************************************************************************************************
* File ccai_writer_chat.h Start!
****************************************************************************************************/

#ifndef _CCAI_WRITER_CHAT_H
#define _CCAI_WRITER_CHAT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */
#include "ccai_writer.h"

/* ui */
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_ccai_writer_chat */
typedef struct
{
    cc_uint8 id;
    QString recvbuffer;
    cc_boolean recvflag;
}cc_ccai_writer_chat_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_ccai_writer_chat_init(cc_void);

cc_result cc_ccai_writer_chat_input_step1_title(cc_ccai_writer_struct *writer,QString title);
cc_result cc_ccai_writer_chat_input_step1_content(cc_ccai_writer_struct *writer,QString content);
cc_result cc_ccai_writer_chat_input_step2_usercontent(cc_ccai_writer_struct *writer,QString content);
cc_result cc_ccai_writer_chat_step2_generate_article(cc_ccai_writer_struct *writer);
cc_result cc_ccai_writer_chat_step3_optimize_article(cc_ccai_writer_struct *writer,QString optimizecontent);
cc_result cc_ccai_writer_chat_recvbuffer_get(QString *buffer);
cc_result cc_ccai_writer_chat_recvbuffer_clear(cc_void);
cc_result cc_ccai_writer_chat_recv(QString content);

cc_result cc_ccai_writer_chat_mainfunction(cc_void);

#endif /* _CCAI_WRITER_CHAT_H */
/****************************************************************************************************
* File ccai_writer_chat.h End!
****************************************************************************************************/

