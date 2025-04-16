
/****************************************************************************************************
* File timer.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "timer.h"
/* log */
/* sub module */
/* components */
#include "task.h"
#include "mainwindow.h"

/* ui */
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* timer */
cc_timer_struct cc_timer_t;
/* init flag */
cc_boolean cc_timer_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* timer_init()
****************************************************************************************************/
cc_result MainWindow::cc_timer_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init timer */
        cc_timer_t.millisecond = 0;
        /* connect */
        connect(&cc_timer_t.timer, &QTimer::timeout,this,cc_timer_mainfunction);
        /* start service */
        cc_timer_t.timer.start(1);
        /* initflag */
        cc_timer_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_timer_getlocaltime_ms()
****************************************************************************************************/
cc_result cc_timer_getlocaltime_ms(cc_uint32 *time)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_timer_initflag == CC_TRUE));
        CHECK_PTR(result,time);

        /* impletement */
        *time = cc_timer_t.millisecond;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_timer_checktimeout_ms()
****************************************************************************************************/
cc_result cc_timer_checktimeout_ms(cc_uint32 *time,cc_uint32 timeout)
{
    cc_result result = CC_E_NOT_OK;
    cc_uint32 currenttime = 0;
    cc_uint32 temp = 0;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_timer_initflag == CC_TRUE));
        CHECK_PTR(result,time);

        /* impletement */
        cc_timer_getlocaltime_ms(&currenttime);
        temp = ((*time) <= currenttime) ? (currenttime - (*time)) : (temp - 1 - (*time) + currenttime);
        /* check timeout */
        if(temp >= timeout)
        {
            /* timeout */
            *time = currenttime;
            result = CC_E_OK;
        }
        else
        {
            /* delay */
            result = CC_E_NOT_OK;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_timer_dateupdateCarryBit()
****************************************************************************************************/
cc_result cc_timer_dateupdateCarryBit(cc_uint32 *dst,cc_uint32 *src,cc_uint32 span)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);
        /* impletement */
        if(((*src) % span) == 0)
        {
            *src = 0;
            *dst = *dst + 1;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* timer_mainfunction_time()
****************************************************************************************************/
cc_result timer_mainfunction_time(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_timer_initflag == CC_TRUE));
        /* 1ms */
        cc_timer_t.millisecond++;
        /* date update */
        cc_timer_t.date.nanosecond++;
        /* 1000 ns = 1 ms */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.millisecond,\
                                    &cc_timer_t.date.nanosecond,\
                                    1000);
        /* 1000 ms = 1 s */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.second,\
                                    &cc_timer_t.date.millisecond,\
                                    1000);
        /* 60 s = 1 m */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.minute,\
                                    &cc_timer_t.date.second,\
                                    60);
        /* 60 m = 1 h */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.hour,\
                                    &cc_timer_t.date.minute,\
                                    60);
        /* 24 h = 1 d */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.day,\
                                    &cc_timer_t.date.hour,\
                                    24);
        /* 30 d = 1 m */
        cc_timer_dateupdateCarryBit(&cc_timer_t.date.month,\
                                    &cc_timer_t.date.day,\
                                    30);
    }while(0u);

    return result;
}

/****************************************************************************************************
* timer_mainfunction()
****************************************************************************************************/
cc_result cc_timer_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_timer_initflag == CC_TRUE));
        /* time */
        timer_mainfunction_time();
        /* task */
        task_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File timer.c End!
****************************************************************************************************/

