
/****************************************************************************************************
* File ccai_cfg.c Start!
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
 * 2025-03-19     cc           the first version
 *
*/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "ccai_cfg.h"
/* log */
/* sub module */
/* components */
#include "ccai_writer_chat.h"

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

/* cc_ccai_cfg */
cc_ccai_cfg_struct cc_ccai_cfg_t =
{
    .id = 0,
    .toollist =
    {
        {CC_CCAI_CFG_TOOLS_CHAT,"默认聊天"},
        {CC_CCAI_CFG_TOOLS_WRITER,"生成文章"},
        {CC_CCAI_CFG_TOOLS_MUSIC,"生成音乐"},
        {CC_CCAI_CFG_TOOLS_VIDEO,"生成视频"},
        {CC_CCAI_CFG_TOOLS_FACE,"AI换脸"},
        {CC_CCAI_CFG_TOOLS_SOUND,"AI换声"},
    }
};

/* init flag */
cc_boolean cc_ccai_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_cfg_init()
****************************************************************************************************/
cc_result cc_ccai_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* init object */

        /* register object */


        /* init ccai_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_cfg_get_toolctrlidx()
****************************************************************************************************/
cc_result cc_ccai_cfg_get_toolctrlidx(cc_ccai_cfg_tools_enum *ctrlidx,QString name)
{
    cc_result result = CC_E_NOT_OK;

    do
    {
        /* check */
        CHECK_PTR(result,ctrlidx);
        /* impletement */
        for(cc_uint32 i = 0; i < CC_CCAI_CFG_TOOLS_END; ++i)
        {
            if(cc_ccai_cfg_t.toollist[i].name == name)
            {
                *ctrlidx = cc_ccai_cfg_t.toollist[i].ctrlidx;
                result = CC_E_OK;
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_cfg_recv()
****************************************************************************************************/
cc_result cc_ccai_cfg_recv(QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(content != ""));
        /* recv */
        cc_ccai_writer_chat_recv(content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_cfg.c End!
****************************************************************************************************/

