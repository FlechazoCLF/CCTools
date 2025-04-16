
/****************************************************************************************************
* File plandetail.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "plandetail.h"
/* log */
/* sub module */
/* components */
#include "file_md.h"

/* ui */
#include "qboxlayout.h"
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type Define
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_plan_detail_t */
cc_plan_detail_struct cc_plan_detail_t;
/* init flag */
cc_boolean cc_plan_detail_show_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_plan_detail_show_init()
****************************************************************************************************/
cc_result cc_plan_detail_show_init(QWidget *qWidget)
{
    cc_result result = CC_E_OK;
    QTextBrowser *textBrowser;
    QVBoxLayout *layout;

    do
    {
        /* check */
        CHECK_PTR(result,qWidget);

        /* layout */
        layout = new QVBoxLayout(qWidget);
        textBrowser = new QTextBrowser(qWidget);
        layout->addWidget(textBrowser);
        qWidget->setLayout(layout);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_plan_detail_show()
****************************************************************************************************/
cc_result cc_plan_detail_show(cc_plan_detail_struct *plan_detail_t)
{
    cc_result result = CC_E_OK;
    QTextBrowser *textBrowser = nullptr;

    do
    {
        /* check */
        CHECK_PTR(result,plan_detail_t);
        CHECK_LOGIC(result,(plan_detail_t->filepath != ""));
        CHECK_PTR(result,plan_detail_t->qWidget);

        /* layout init */
        if (cc_plan_detail_show_initflag != CC_TRUE)
        {
            cc_plan_detail_show_init(plan_detail_t->qWidget);
        }
        /* display md file */
        textBrowser = plan_detail_t->qWidget->findChild<QTextBrowser*>();
        if (textBrowser == nullptr)
        {
            continue;
        }
        cc_file_md_display(textBrowser,plan_detail_t->filepath);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_plan_detail_mainfunction()
****************************************************************************************************/
cc_result cc_plan_detail_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File plandetail.c End!
****************************************************************************************************/
