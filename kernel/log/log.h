
/****************************************************************************************************
* File log.h Start!
****************************************************************************************************/

#ifndef _LOG_H
#define _LOG_H
/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "kernel_cfg.h"
/* sub module */
/* components */

/* ui */
#include "qtextbrowser.h"
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* log */
typedef struct
{
    cc_uint8 id;
}log_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result log_init(cc_void);
cc_result log_mainfunction(cc_void);
cc_result log_print(cc_kernel_module_enum module,QTextBrowser *qTextBrowser,const char *format,...);

#endif /* _LOG_H */
/****************************************************************************************************
* File log.h End!
****************************************************************************************************/
