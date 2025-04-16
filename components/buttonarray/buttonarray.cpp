
/****************************************************************************************************
* File buttonarray.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "buttonarray.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QGridLayout>
#include <QPushButton>
#include "qscrollarea.h"
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

/* cc_buttonarray */
cc_buttonarray_struct cc_buttonarray_t;
/* init flag */
cc_boolean cc_buttonarray_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_buttonarray_init()
****************************************************************************************************/
cc_result cc_buttonarray_init(cc_buttonarray_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->qtextbrower);
        /* init */
        cc_buttonarray_t.qtextbrower = cfg_t->qtextbrower;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_buttonarray_create()
****************************************************************************************************/
cc_result cc_buttonarray_create(QStringList *qstringlist,QWidget *qwidget,cc_uint8 rowcount,cc_result (*callback)(QPushButton *button,cc_uint32 idx,QString name))
{
    cc_result result = CC_E_OK;
    int row;
    int col;

    do
    {
        /* check */
        CHECK_PTR(result,qstringlist);
        CHECK_PTR(result,qwidget);
        CHECK_LOGIC(result,(qstringlist->count() > CC_NULL));
        CHECK_LOGIC(result,(rowcount > CC_NULL));
        /* impletement */
        CHECK_LOGIC(result,(qwidget->layout() == CC_NULL_PTR));
        QVBoxLayout *qvboxlayout = new QVBoxLayout(qwidget);
        QWidget *qwidgetbuttons = new QWidget(qwidget);
        /* layout */
        QGridLayout *gridLayout = new QGridLayout(qwidgetbuttons);
        for (int i = 0; i < qstringlist->count(); ++i)
        {
            QPushButton *button = new QPushButton(qwidgetbuttons);
            button->setText((*qstringlist)[i]);
            button->setMinimumHeight(40);
            button->setMinimumWidth(90);

            row = i / rowcount;
            col = i % rowcount;

            /* callback */
            if(callback != nullptr)
            {
                callback(button,i,(*qstringlist)[i]);
            }

            /* add */
            gridLayout->addWidget(button, row, col);
        }

        qvboxlayout->addWidget(qwidgetbuttons);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_buttonarray_mainfunction()
****************************************************************************************************/
cc_result cc_buttonarray_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File buttonarray.c End!
****************************************************************************************************/

