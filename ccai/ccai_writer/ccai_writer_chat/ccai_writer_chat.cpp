
/****************************************************************************************************
* File ccai_writer_chat.c Start!
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
#include "ccai_writer_chat.h"
/* log */
/* sub module */
/* components */
#include "ccai.h"
#include "ccai_writer_chat_cfg.h"

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

/* cc_ccai_writer_chat */
cc_ccai_writer_chat_struct cc_ccai_writer_chat_t;
/* init flag */
cc_boolean cc_ccai_writer_chat_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_writer_chat_init()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* init object */

        /* register object */


        /* init ccai_writer_chat */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_input_step1_title()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_input_step1_title(cc_ccai_writer_struct *writer,QString title)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        CHECK_LOGIC(result,(title != ""));
        /* impletement */
        writer->workflow.step1_title = title;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_input_step1_content()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_input_step1_content(cc_ccai_writer_struct *writer,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        CHECK_LOGIC(result,(content != ""));
        /* impletement */
        writer->workflow.step1_content = content;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_input_step2_usercontent()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_input_step2_usercontent(cc_ccai_writer_struct *writer,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        CHECK_LOGIC(result,(content != ""));
        /* impletement */
        writer->workflow.step2_usercontent = content;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_step2_generate_article()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_step2_generate_article(cc_ccai_writer_struct *writer)
{
    cc_result result = CC_E_OK;
    QString msg;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        /* build message */
        cc_ccai_writer_chat_cfg_msg_struct msgcfg;
        msgcfg.title = writer->workflow.step1_title;
        msgcfg.content = writer->workflow.step1_content;
        msgcfg.usercontent = writer->workflow.step2_usercontent;
        cc_ccai_writer_chat_cfg_buildmsg(&msg,&msgcfg,CC_CCAI_WRITER_CHAT_CFG_MSG_BUILD);
        /* send to AI */
        cc_ccai_send(msg);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_step3_optimize_article()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_step3_optimize_article(cc_ccai_writer_struct *writer,QString optimizecontent)
{
    cc_result result = CC_E_OK;
    QString msg;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        CHECK_LOGIC(result,(optimizecontent != ""));

        /* get optimize */
        writer->workflow.step3_optimizecontent = optimizecontent;
        /* build message */
        cc_ccai_writer_chat_cfg_msg_struct msgcfg;
        msgcfg.title = writer->workflow.step1_title;
        msgcfg.usercontent = writer->workflow.step2_usercontent;
        msgcfg.optimizecontent = writer->workflow.step3_optimizecontent;
        cc_ccai_writer_chat_cfg_buildmsg(&msg,&msgcfg,CC_CCAI_WRITER_CHAT_CFG_MSG_OPTIMIZE);
        /* send to AI */
        cc_ccai_send(msg);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_recvbuffer_get()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_recvbuffer_get(QString *buffer)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,buffer);
        /* impletement */
        *buffer = cc_ccai_writer_chat_t.recvbuffer;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_recvbuffer_clear()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_recvbuffer_clear(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_ccai_writer_chat_t.recvbuffer = "";
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_recv()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_recv(QString content)
{
    cc_result result = CC_E_OK;
    cc_ccai_writer_workflow_enum state;
    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(content != ""));
        /* recv */
        cc_ccai_writer_get_state(&state);
        cc_ccai_writer_chat_t.recvbuffer += content;
        switch (state)
        {
        case CC_CCAI_WRITER_WORKFLOW_FREE:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_1_INPUT_TITLE:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_2_INPUT_USERCONTENT:
            {

            }
            break;
            case CC_CCAI_WRITER_WORKFLOW_3_OPTIMIZE_CONTENT:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_4_CONVERT_MARKDOWN:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_5_CONVERT_XMIND:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_6_DISPLAY_XMIND:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_7_GENERATE_CREATE:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_8_GENERATE_MARKDOWN:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_9_RELEASE:
            {
                
            }
            break;
        case CC_CCAI_WRITER_WORKFLOW_10_COMPLETE:
            {
                
            }
            break;
        default:
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_writer_chat.c End!
****************************************************************************************************/

