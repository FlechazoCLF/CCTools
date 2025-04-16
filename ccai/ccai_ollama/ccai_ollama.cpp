
/****************************************************************************************************
* File ccai_ollama.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "ccai_ollama.h"
/* type */
/* log */
/* sub module */
/* components */
#include "com_network_http.h"

/* ui */
/* cpp */
#include <QJsonObject>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_ccai_ollama */
cc_ccai_ollama_struct cc_ccai_ollama_t;
/* init flag */
cc_boolean cc_ccai_ollama_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/
/* recv http */
cc_result cc_ccai_ollama_http_recv(cc_uint32 ctrlidx,QString content);

/****************************************************************************************************
* cc_ccai_ollama_init()
****************************************************************************************************/
cc_result cc_ccai_ollama_init(cc_ccai_ollama_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->recv);
        CHECK_PTR(result,cfg_t->qtextbrower);
        CHECK_PTR(result,cfg_t->qComboBox_model);
        CHECK_LOGIC(result,(cc_ccai_ollama_initflag == CC_FALSE));

        /* impletement */
        cc_ccai_ollama_t.url = "http://127.0.0.1:11434/api/generate";
        cc_ccai_ollama_t.qComboBox_model = cfg_t->qComboBox_model;
        cc_ccai_ollama_t.qtextbrower = cfg_t->qtextbrower;
        cc_ccai_ollama_t.recv = cfg_t->recv;

        /* create http */
        cc_com_network_http_create("ollama",&cc_ccai_ollama_t.com_http_ctrlidx,cc_ccai_ollama_http_recv);

        /* init flag */
        cc_ccai_ollama_initflag = CC_TRUE;

        /* log */
        CCAI_OLLAMA_LOG_PRINT("Init Complete!");

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_http_send()
****************************************************************************************************/
cc_result cc_ccai_ollama_http_send(QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_ccai_ollama_initflag == CC_TRUE));
        CHECK_LOGIC(result,(content != ""));
        CHECK_PTR(result,cc_ccai_ollama_t.qtextbrower);
        /* impletement */
        cc_ccai_ollama_t.qtextbrower->append(content);
        /* send */
        QJsonObject qjsonobject;
        qjsonobject["model"] = cc_ccai_ollama_t.qComboBox_model->currentText();
        qjsonobject["prompt"] = content;
        qjsonobject["stream"] = true;
        cc_com_network_http_send(cc_ccai_ollama_t.com_http_ctrlidx,\
                                 cc_ccai_ollama_t.url,\
                                 &qjsonobject);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_http_recv()
****************************************************************************************************/
cc_result cc_ccai_ollama_http_recv(cc_uint32 ctrlidx,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_ccai_ollama_initflag == CC_TRUE));
        CHECK_LOGIC(result,(ctrlidx == cc_ccai_ollama_t.com_http_ctrlidx));
        CHECK_LOGIC(result,(content != ""));
        CHECK_PTR(result,cc_ccai_ollama_t.qtextbrower);
        /* recv */
        cc_ccai_ollama_t.qtextbrower->moveCursor(QTextCursor::End);
        cc_ccai_ollama_t.qtextbrower->insertPlainText(content);
        /* upper layer */
        CHECK_PTR(result,cc_ccai_ollama_t.recv);
        cc_ccai_ollama_t.recv(content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_send_cmd_check()
****************************************************************************************************/
cc_result cc_ccai_ollama_send_cmd_check(QString *cmd)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cmd);
        /* impletement */
        /* check ollama cmd */
        if(cmd->contains("ollama run"))
        {
            if(*cmd == "ollama run")
            {
                /* add model */
                cmd->append(" " + cc_ccai_ollama_t.qComboBox_model->currentText());
            }
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_ollama_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_ccai_ollama_initflag == CC_TRUE));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_ollama.c End!
****************************************************************************************************/

