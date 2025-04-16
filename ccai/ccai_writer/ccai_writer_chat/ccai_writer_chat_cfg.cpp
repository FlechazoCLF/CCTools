
/****************************************************************************************************
* File ccai_writer_chat_cfg.c Start!
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
#include "ccai_writer_chat_cfg.h"
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

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_ccai_writer_chat_cfg */
cc_ccai_writer_chat_cfg_struct cc_ccai_writer_chat_cfg_t =
{
    .id = 0,
    .context = "\
一.文章背景\n\
1.文章用途:技术博客\n\
2.目标读者:嵌入式软件开发者\n\
3.预期结果:期望可以帮助开发学到一些有深度有用处的知识\n\
4.专业知识:精通C语言,CPP,Python,嵌入式等知识\n\
二.文章需求\n\
1.目录结构:目录,引言,文章xmind思维导图,实现对问题的分治拆解,深入解读技术原理,总结\n\
2.内容需求:需要包含具体的代码片段,代码要使用cc_result cc_ccai_writer_init(cc_void);这样的命名风格\n\
3.引申思考:要有一些延展性的,可以引发思考的结论\n\
4.文章内容:要包含的信息:作者:flechazo 网站:flechazo.mba\n\
5.文章格式:文章要使用markdown格式,方便后期的导出\n"
};

/* init flag */
cc_boolean cc_ccai_writer_chat_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_writer_chat_cfg_init()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* init object */

        /* register object */


        /* init ccai_writer_chat_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_cfg_buildmsg_build()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_cfg_buildmsg_build(QString *content,cc_ccai_writer_chat_cfg_msg_struct *msg)
{
    cc_result result = CC_E_OK;
    QString buildmsg;

    do
    {
        /* check */
        CHECK_PTR(result,content);
        CHECK_PTR(result,msg);
        /* impletement */
        buildmsg = cc_ccai_writer_chat_cfg_t.context;
        buildmsg += "6.文章标题:" + msg->title + "\n";
        buildmsg += "7.文章主题:" + msg->content + "\n";
        buildmsg += "8.文章包含:" + msg->usercontent + "\n";
        buildmsg += "请根据如上信息帮我生成一篇新文章\n";
        /* output */
        *content = buildmsg;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_cfg_buildmsg_optimize()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_cfg_buildmsg_optimize(QString *content,cc_ccai_writer_chat_cfg_msg_struct *msg)
{
    cc_result result = CC_E_OK;
    QString buildmsg;

    do
    {
        /* check */
        CHECK_PTR(result,content);
        CHECK_PTR(result,msg);
        /* impletement */
        buildmsg = cc_ccai_writer_chat_cfg_t.context;
        buildmsg += "6.文章主题:" + msg->title + "\n";
        buildmsg += "7.文章包含:" + msg->usercontent + "\n";
        buildmsg += "请结合之前生成的内容,以及上述这些要求,并按照以下的优化操作在原本的文章基础上进行修改\n";
        buildmsg += "优化:" + msg->optimizecontent +"\n";
        /* output */
        *content = buildmsg;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_cfg_buildmsg()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_cfg_buildmsg(QString *content,cc_ccai_writer_chat_cfg_msg_struct *msg,cc_ccai_writer_chat_cfg_msg_enum type)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,content);
        CHECK_PTR(result,msg);
        /* impletement */
        switch (type)
        {
        case CC_CCAI_WRITER_CHAT_CFG_MSG_BUILD:
            cc_ccai_writer_chat_cfg_buildmsg_build(content,msg);
            break;
        case CC_CCAI_WRITER_CHAT_CFG_MSG_OPTIMIZE:
            cc_ccai_writer_chat_cfg_buildmsg_optimize(content,msg);
            break;
        default:
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_chat_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_chat_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_writer_chat_cfg.c End!
****************************************************************************************************/

