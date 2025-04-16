
/****************************************************************************************************
* File task_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "task_cfg.h"
/* log */
/* sub module */
/* components */
#include "ccai.h"
#include "codeexample.h"
#include "collect.h"
#include "communication.h"
#include "components.h"
#include "draft.h"
#include "file.h"
#include "knowledge.h"
#include "moment.h"
#include "navigate.h"
#include "plan.h"
#include "project.h"
#include "projectcollect.h"
#include "script.h"
#include "toolcollect.h"

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

/* task_cfg */
task_cfg_struct task_cfg_t;
/* init flag */
cc_boolean task_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* task_cfg_init()
****************************************************************************************************/
cc_result task_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init task_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* task_cfg_mainfunction_1ms()
****************************************************************************************************/
cc_result task_cfg_mainfunction_1ms(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* 1ms */
        cc_ccai_mainfunction();
        cc_com_mainfunction();
        cc_script_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* task_cfg_mainfunction_5ms()
****************************************************************************************************/
cc_result task_cfg_mainfunction_5ms(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* 5ms */
        cc_file_mainfunction();
        cc_plan_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* task_cfg_mainfunction_10ms()
****************************************************************************************************/
cc_result task_cfg_mainfunction_10ms(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* 10ms */
        cc_codeexample_mainfunction();
        cc_collect_mainfunction();
        cc_components_mainfunction();
        cc_draft_mainfunction();
        cc_knowledge_mainfunction();
        cc_moment_mainfunction();
        cc_navigate_mainfunction();
        cc_project_mainfunction();
        cc_projectcollect_mainfunction();
        cc_toolcollect_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* task_cfg_mainfunction()
****************************************************************************************************/
cc_result task_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File task_cfg.c End!
****************************************************************************************************/

