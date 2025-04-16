
/****************************************************************************************************
* File ccai_ollama.h Start!
****************************************************************************************************/

#ifndef _CCAI_OLLAMA_H
#define _CCAI_OLLAMA_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"

/* ui */
#include "qcombobox.h"
#include "qlineedit.h"
#include <QTextBrowser>
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define CCAI_OLLAMA_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_CCAI,cc_ccai_ollama_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_ccai_ollama */
typedef struct
{
    cc_uint8 id;
    /* http ctrl */
    cc_uint32 com_http_ctrlidx;
    /* model */
    QComboBox *qComboBox_model;
    /* display */
    QTextBrowser *qtextbrower;
    /* url */
    QString url;
    /* recv */
    cc_result (*recv)(QString content);
}cc_ccai_ollama_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

/* init */
cc_result cc_ccai_ollama_init(cc_ccai_ollama_struct *cfg_t);

/* api */
cc_result cc_ccai_ollama_http_send(QString content);
/* cc_result cc_ccai_ollama_http_recv(cc_uint32 ctrlidx,QString content); */
cc_result cc_ccai_ollama_send_cmd_check(QString *cmd);

/* mainfunction */
cc_result cc_ccai_ollama_mainfunction(cc_void);

#endif /* _CCAI_OLLAMA_H */
/****************************************************************************************************
* File ccai_ollama.h End!
****************************************************************************************************/

