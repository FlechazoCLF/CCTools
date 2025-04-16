
/****************************************************************************************************
* File collect_flush_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "collect_flush_cfg.h"
/* log */
/* sub module */
/* components */

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

/* cc_collect_flush_cfg */
cc_collect_flush_cfg_struct cc_collect_flush_cfg_t;
/* init flag */
cc_boolean cc_collect_flush_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_collect_flush_cfg_init()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init collect_flush_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_cfg_checkcomplete()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_checkcomplete(cc_uint32 *flag,QList<cc_collect_flush_cfg_info_struct> *infolist)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,flag);
        CHECK_PTR(result,infolist);
        /* impletement */
        if((*flag & (1<<CC_COLLECT_FLUSH_CFG_INFO_PARENT)) != CC_TRUE)
        {
            /* lose */
        }
        if((*flag & (1<<CC_COLLECT_FLUSH_CFG_INFO_NAME)) != CC_TRUE)
        {
            /* lose */
        }
        if((*flag & (1<<CC_COLLECT_FLUSH_CFG_INFO_URL)) != CC_TRUE)
        {
            /* lose */
        }
        if((*flag & (1<<CC_COLLECT_FLUSH_CFG_INFO_DESCRIPTION)) != CC_TRUE)
        {
            /* lose */
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_cfg_addcomplete()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_addcomplete(cc_uint32 *flag,cc_collect_flush_cfg_info_enum type)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,flag);
        /* impletement */
        (*flag) |= (1<<type);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_cfg_getcomplete()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_getcomplete(cc_uint32 *flag,cc_collect_flush_cfg_info_enum type)
{
    cc_result result = CC_E_NOT_OK;

    do
    {
        /* check */
        CHECK_PTR(result,flag);
        /* impletement */
        if(((*flag) & (1<<type)) != 0)
        {
            result = CC_E_OK;
        }
    }while(0u);

    return result;
}


/****************************************************************************************************
* cc_collect_flush_cfg_matchcontent()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_matchcontent(QString *dstcontent,QString srccontent,QString startcondition)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,dstcontent);
        /* impletement */
        QString regular = startcondition + "\\s*(\\S+)";
        QRegularExpression regex(regular);
        QRegularExpressionMatch match = regex.match(srccontent);
        if (match.hasMatch())
        {
            *dstcontent = match.captured(1).trimmed();
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_cfg_get_info()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_get_info(cc_file_dir_struct *dirinfo_t,QList<cc_collect_flush_cfg_info_struct> *infolist,QString content)
{
    cc_result result = CC_E_OK;
    QStringList linelist;
    QString line;
    cc_uint32 flag = 0;
    cc_collect_flush_cfg_info_struct info_t;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,infolist);
        /* impletement */
        /* parent */
        cc_collect_flush_cfg_addcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_PARENT);
        /* get info */
        linelist = content.split("\n",Qt::SkipEmptyParts);
        for(cc_uint32 i = 0; i < linelist.count(); i++)
        {
            /* get line */
            line = linelist[i];
            CHECK_LOGIC(result,(line != ""));
            /* fill */
            if(line.startsWith("## "))
            {
                /* check flag */
                cc_collect_flush_cfg_checkcomplete(&flag,infolist);
                flag = 0;
                cc_collect_flush_cfg_addcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_PARENT);
                /* append */
                infolist->append(info_t);
                /* parent */
                infolist->last().parent = dirinfo_t->parent->name;
                /* name */
                cc_collect_flush_cfg_matchcontent(&infolist->last().name,line,"## ");
                /* set flag */
                cc_collect_flush_cfg_addcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_NAME);
            }
            if(line.startsWith("官网"))
            {
                /* check */
                CHECK_LOGIC(result,(cc_collect_flush_cfg_getcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_URL) != CC_E_OK));
                /* url */
                cc_collect_flush_cfg_matchcontent(&infolist->last().url,line,"官网:");
                /* set flag */
                cc_collect_flush_cfg_addcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_URL);
            }
            if(line.startsWith("简介"))
            {
                /* check */
                CHECK_LOGIC(result,(cc_collect_flush_cfg_getcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_DESCRIPTION) != CC_E_OK));
                /* description */
                cc_collect_flush_cfg_matchcontent(&infolist->last().description,line,"简介:");
                /* set flag */
                cc_collect_flush_cfg_addcomplete(&flag,CC_COLLECT_FLUSH_CFG_INFO_DESCRIPTION);
            }
        }
        cc_collect_flush_cfg_checkcomplete(&flag,infolist);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_collect_flush_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File collect_flush_cfg.c End!
****************************************************************************************************/

