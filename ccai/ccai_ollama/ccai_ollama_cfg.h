
/****************************************************************************************************
* File ccai_ollama_cfg.h Start!
****************************************************************************************************/

#ifndef _CCAI_OLLAMA_CFG_H
#define _CCAI_OLLAMA_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
/* components */

/* ui */
#include "qcombobox.h"
#include <QLineEdit>
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* models */
#define CCAI_OLLAMA_CFG_MODELS_NUM (16u)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_ccai_ollama_cfg */
typedef struct
{
    cc_uint8 id;
    /* models */
    QString models[CCAI_OLLAMA_CFG_MODELS_NUM];
    /* str */
    QString downloadpath;
    QString installpath;
    QString model;
    /* ui */
    QLineEdit *qLineEdit_download;
    QLineEdit *qLineEdit_install;
    QComboBox *qComboBox_model;
}cc_ccai_ollama_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

/* init */
cc_result cc_ccai_ollama_cfg_init(cc_ccai_ollama_cfg_struct *cfg_t);

/* api */
cc_result cc_ccai_ollama_cfg_add_models(QComboBox *qComboBox_model);
cc_result cc_ccai_ollama_cfg_install(cc_void);

/* mainfunction */
cc_result cc_ccai_ollama_cfg_mainfunction(cc_void);

#endif /* _CCAI_OLLAMA_CFG_H */
/****************************************************************************************************
* File ccai_ollama_cfg.h End!
****************************************************************************************************/

