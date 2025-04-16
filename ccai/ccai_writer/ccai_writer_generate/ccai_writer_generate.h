
/****************************************************************************************************
* File ccai_writer_generate.h Start!
****************************************************************************************************/

#ifndef _CCAI_WRITER_GENERATE_H
#define _CCAI_WRITER_GENERATE_H

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

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_ccai_writer_generate */
typedef struct
{
    cc_uint8 id;
}cc_ccai_writer_generate_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_ccai_writer_generate_init(cc_void);
cc_result cc_ccai_writer_generate_step4_markdown(cc_ccai_writer_struct *writer);
cc_result cc_ccai_writer_generate_step7_combine(cc_ccai_writer_struct *writer);

cc_result cc_ccai_writer_generate_mainfunction(cc_void);

#endif /* _CCAI_WRITER_GENERATE_H */
/****************************************************************************************************
* File ccai_writer_generate.h End!
****************************************************************************************************/

