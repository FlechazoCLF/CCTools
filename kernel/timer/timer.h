
/****************************************************************************************************
* File timer.h Start!
****************************************************************************************************/

#ifndef _TIMER_H
#define _TIMER_H

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
#include <QTimer>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* date */
typedef struct
{
    cc_uint32 year;/* 2025 */
    cc_uint32 month;/* 1~12 */
    cc_uint32 day;/* 1~31 */
    cc_uint32 hour;/* 0~24 */
    cc_uint32 minute;/* 0~60 */
    cc_uint32 second;
    cc_uint32 millisecond;
    cc_uint32 nanosecond;
    cc_uint64 tick;
}cc_timer_date_struct;

/* timer */
typedef struct
{
    cc_uint8 id;
    QTimer timer;
    cc_uint32 millisecond;
    cc_timer_date_struct date;
}cc_timer_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_timer_mainfunction(cc_void);
cc_result cc_timer_getlocaltime_ms(cc_uint32 *time);
cc_result cc_timer_checktimeout_ms(cc_uint32 *time,cc_uint32 timeout);

#endif /* _TIMER_H */
/****************************************************************************************************
* File timer.h End!
****************************************************************************************************/

