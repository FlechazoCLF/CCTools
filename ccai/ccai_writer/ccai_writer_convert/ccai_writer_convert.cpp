
/****************************************************************************************************
* File ccai_writer_convert.c Start!
****************************************************************************************************/

/*
 *
 *  Copyright (c) 2024-2025 by flechazo. All rights reserved.
 *
 * Author : CarlChai LinFeng Chai flechazo
 * Website: flechazo.mba
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-03-23     cc          the first version
 *
*/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "ccai_writer_convert.h"
/* log */
/* sub module */
/* components */
#include "toolcollect_markmap.h"

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

/* cc_ccai_writer_convert */
cc_ccai_writer_convert_struct cc_ccai_writer_convert_t;
/* init flag */
cc_boolean cc_ccai_writer_convert_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_writer_convert_init()
****************************************************************************************************/
cc_result cc_ccai_writer_convert_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* init object */

        /* register object */


        /* init ccai_writer_convert */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_convert_markdown_to_markmap()
****************************************************************************************************/
cc_result cc_ccai_writer_convert_markdown_to_markmap(QString *markmap,QString markdown)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,markmap);
        CHECK_LOGIC(result,(markdown != ""));
        /* impletement */
        cc_toolcollect_markmap_convert(markmap,markdown);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_convert_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_convert_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_writer_convert.c End!
****************************************************************************************************/

