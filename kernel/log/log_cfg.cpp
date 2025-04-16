
/****************************************************************************************************
* File log_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "log_cfg.h"
/* log */
/* sub module */
/* components */

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

/* log_cfg */
log_cfg_struct log_cfg_t =
{
    .id = 0,
    .module =
    {
        {CC_KERNEL_MODULE_KERNEL,"Kernel"},
        {CC_KERNEL_MODULE_MAINWINDOW,"MainWindow"},
        {CC_KERNEL_MODULE_CCAI,"CCAI"},
        {CC_KERNEL_MODULE_CODEEXAMPLE,"CodeExample"},
        {CC_KERNEL_MODULE_COLLECT,"Collect"},
        {CC_KERNEL_MODULE_COMMUNICATION,"Communication"},
        {CC_KERNEL_MODULE_COMPONENTS,"Components"},
        {CC_KERNEL_MODULE_DRAFT,"Draft"},
        {CC_KERNEL_MODULE_FILE,"File"},
        {CC_KERNEL_MODULE_KNOWLEDGE,"Knowledge"},
        {CC_KERNEL_MODULE_MOMENT,"Moment"},
        {CC_KERNEL_MODULE_NAVIGATE,"Navigate"},
        {CC_KERNEL_MODULE_PLAN,"Plan"},
        {CC_KERNEL_MODULE_PROJECT,"Project"},
        {CC_KERNEL_MODULE_PROJECTCOLLECT,"ProjectCollect"},
        {CC_KERNEL_MODULE_SCRIPT,"Script"},
        {CC_KERNEL_MODULE_TOOLCOLLECT,"ToolCollect"},
    }
};
/* init flag */
cc_boolean log_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* log_cfg_init()
****************************************************************************************************/
cc_result log_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init log_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* log_cfg_module_info_get()
****************************************************************************************************/
cc_result log_cfg_module_info_get(cc_kernel_module_enum module,QString *info)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        for (int moduleIdx = 0; moduleIdx < CC_KERNEL_MODULE_END; ++moduleIdx)
        {
            if(log_cfg_t.module[moduleIdx].module != module)
            {
                continue;
            }
            *info = log_cfg_t.module[moduleIdx].info;
            result = CC_E_OK;
            break;
        }

    }while(0u);

    return result;
}


/****************************************************************************************************
* log_cfg_mainfunction()
****************************************************************************************************/
cc_result log_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File log_cfg.c End!
****************************************************************************************************/

