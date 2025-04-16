
/****************************************************************************************************
* File ccai_writer_generate.c Start!
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
#include "ccai_writer_generate.h"
/* log */
/* sub module */
/* components */
#include "file_md.h"

/* ui */
/* cpp */
#include <QRegularExpression>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_ccai_writer_generate */
cc_ccai_writer_generate_struct cc_ccai_writer_generate_t;
/* init flag */
cc_boolean cc_ccai_writer_generate_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_writer_generate_init()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* init object */

        /* register object */


        /* init ccai_writer_generate */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_catalogue()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_catalogue(QString *catalogue,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,catalogue);
        CHECK_LOGIC(result,(article != ""));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_xmind()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_xmind(QString *xmind,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,xmind);
        CHECK_LOGIC(result,(article != ""));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_header()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_header(QString *header,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,header);
        CHECK_LOGIC(result,(article != ""));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_usercontent()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_usercontent(QString *usercontent,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,usercontent);
        CHECK_LOGIC(result,(article != ""));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_footer()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_footer(QString *footer,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,footer);
        CHECK_LOGIC(result,(article != ""));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_get_article()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_get_article(QString *newarticle,QString article)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,newarticle);
        /* impletement */
        QRegularExpression regex("<think>.*?</think>");
        article = article.remove(regex);
        *newarticle = article.remove("<think>\n\n</think>");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_step4_markdown(cc_ccai_writer_struct *writer)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        CHECK_LOGIC(result,(writer->workflow.step4.generatepath != ""));
        /* get article */
        cc_ccai_writer_generate_get_article(&(writer->article),writer->article);
        /* 2.markdown */
        cc_file_md_create(writer->workflow.step4.generatepath,writer->workflow.step1_title);
        cc_file_md_write(writer->workflow.step4.generatepath + "/" + writer->workflow.step1_title + ".md",\
                         writer->article);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_step7_combine()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_step7_combine(cc_ccai_writer_struct *writer)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,writer);
        /* impletement */
        if(writer->workflow.step7.catalogue == "目录")
        {
            cc_ccai_writer_generate_get_catalogue(&writer->workflow.step7.catalogue,writer->article);
        }
        if(writer->workflow.step7.xmind == "思维导图")
        {
            cc_ccai_writer_generate_get_xmind(&writer->workflow.step7.xmind,writer->article);
        }
        if(writer->workflow.step7.header == "文首")
        {
            cc_ccai_writer_generate_get_header(&writer->workflow.step7.header,writer->article);
        }
        if(writer->workflow.step7.usercontent == "用户自定义")
        {
            cc_ccai_writer_generate_get_usercontent(&writer->workflow.step7.usercontent,writer->article);
        }
        if(writer->workflow.step7.article == "文章")
        {
            cc_ccai_writer_generate_get_article(&writer->workflow.step7.article,writer->article);
        }
        if(writer->workflow.step7.footer == "文末")
        {
            cc_ccai_writer_generate_get_footer(&writer->workflow.step7.footer,writer->article);
        }
        /* combin article */
        writer->article = writer->workflow.step7.catalogue +\
                          writer->workflow.step7.xmind +\
                          writer->workflow.step7.header +\
                          writer->workflow.step7.usercontent +\
                          writer->workflow.step7.article +\
                          writer->workflow.step7.footer;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_generate_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_generate_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_writer_generate.c End!
****************************************************************************************************/

