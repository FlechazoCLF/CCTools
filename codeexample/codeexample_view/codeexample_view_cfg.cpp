
/****************************************************************************************************
* File codeexample_view_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "codeexample_view_cfg.h"
/* type */
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QStringList>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_codeexample_view_cfg */
cc_codeexample_view_cfg_struct cc_codeexample_view_cfg_t;
/* init flag */
cc_boolean cc_codeexample_view_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_codeexample_view_cfg_init()
****************************************************************************************************/
cc_result cc_codeexample_view_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init codeexample_view_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_cfg_geturl()
****************************************************************************************************/
cc_result cc_codeexample_view_cfg_geturl(QString *url,QString content)
{
    cc_result result = CC_E_OK;
    QStringList codeBlocks;
    int startPos = 0;

    do
    {
        /* check parameter */
        CHECK_PTR(result,url);

        /* get path */
        while ((startPos = content.indexOf("```", startPos)) != -1)
        {
            /* find ``` start */
            startPos += 3;

            /* find ``` end */
            int endPos = content.indexOf("```", startPos);
            CHECK_LOGIC(result,(endPos != -1));

            /* get content */
            QString code = content.mid(startPos, endPos - startPos).trimmed();
            codeBlocks << code;

            /* update startpos */
            startPos = endPos + 3;
        }

        /* output */
        CHECK_LOGIC(result,codeBlocks.count()>=2);
        *url = codeBlocks[1];
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_codeexample_view_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_codeexample_view_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File codeexample_view_cfg.c End!
****************************************************************************************************/

