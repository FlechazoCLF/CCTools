
/****************************************************************************************************
* File ccai_ollama_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "ccai_ollama_cfg.h"
/* log */
/* sub module */
/* components */
#include "script_cmd.h"

/* ui */
/* cpp */
#include <QProcess>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_ccai_ollama_cfg */
cc_ccai_ollama_cfg_struct cc_ccai_ollama_cfg_t =
{
    .id = 0,
    .models =
    {
        /* deepseek */
        "deepseek-r1:1.5b",
        "deepseek-r1:7b",
        "deepseek-r1:8b",
        "deepseek-r1:14b",
        "deepseek-r1:32b",
        "deepseek-r1:70b",
        "deepseek-r1:671b",
        /* Qwen */
        "qwq",
        /* llama */
        "llama3.3:70b",
        /* nomic */
        "nomic-embed-text",
        /* llava */
        "llava:7b",
        "llava:13b",
        "llava:34b",
        /* llama3.2-vision */
        "llama3.2-vision:11b",
        "llama3.2-vision:90b",
        /* llama3.2 */
        "llama3.2:1b",
    },
    .downloadpath = "",
    .installpath = "",
    .model = "",
    .qLineEdit_download = (QLineEdit *)CC_NULL_PTR,
    .qLineEdit_install = (QLineEdit *)CC_NULL_PTR,
    .qComboBox_model = (QComboBox *)CC_NULL_PTR,
};
/* init flag */
cc_boolean cc_ccai_ollama_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_ccai_ollama_cfg_init()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_init(cc_ccai_ollama_cfg_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->qLineEdit_download);
        CHECK_PTR(result,cfg_t->qLineEdit_install);
        CHECK_PTR(result,cfg_t->qComboBox_model);
        CHECK_LOGIC(result,(cc_ccai_ollama_cfg_initflag == CC_FALSE));

        /* impletement */
        cc_ccai_ollama_cfg_t.qLineEdit_download = cfg_t->qLineEdit_download;
        cc_ccai_ollama_cfg_t.qLineEdit_install = cfg_t->qLineEdit_install;
        cc_ccai_ollama_cfg_t.qComboBox_model = cfg_t->qComboBox_model;
        cc_ccai_ollama_cfg_add_models(cc_ccai_ollama_cfg_t.qComboBox_model);

        /* init flag */
        cc_ccai_ollama_cfg_initflag = CC_TRUE;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_cfg_add_models()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_add_models(QComboBox *qComboBox_model)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,qComboBox_model);
        /* add */
        for (cc_uint32 modelIdx = 0; modelIdx < CCAI_OLLAMA_CFG_MODELS_NUM; ++modelIdx)
        {
            qComboBox_model->addItem(cc_ccai_ollama_cfg_t.models[modelIdx]);
        }
        /* set default model */
        qComboBox_model->setCurrentText("deepseek-r1:7b");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_cfg_install_model()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_install_model(QString model)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(model != ""));

        /* impletement */
        QString cmd;
        cmd = "ollama run " + model;
        /* cmd */
        QProcess *process;
        cc_script_cmd_get(&process);
        /* send */
        cc_script_cmd_send(process,cmd);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_cfg_install_pathset()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_install_pathset(QString path)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(path != ""));

        /* impletement */
        QString cmd;
        cmd = "setx OLLAMA_MODEL \"" + path + "\"";
        /* cmd */
        QProcess *process;
        cc_script_cmd_get(&process);
        /* send */
        cc_script_cmd_send(process,cmd);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_cfg_install()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_install(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_ccai_ollama_cfg_initflag == CC_TRUE));
        CHECK_PTR(result,cc_ccai_ollama_cfg_t.qLineEdit_download);
        CHECK_PTR(result,cc_ccai_ollama_cfg_t.qLineEdit_install);
        CHECK_PTR(result,cc_ccai_ollama_cfg_t.qComboBox_model);

        /* impletement */
        /* get config */
        cc_ccai_ollama_cfg_t.downloadpath = cc_ccai_ollama_cfg_t.qLineEdit_download->text();
        cc_ccai_ollama_cfg_t.installpath = cc_ccai_ollama_cfg_t.qLineEdit_install->text();
        cc_ccai_ollama_cfg_t.model = cc_ccai_ollama_cfg_t.qComboBox_model->currentText();
        /* install path set */
        cc_ccai_ollama_cfg_install_pathset(cc_ccai_ollama_cfg_t.installpath);
        /* install model */
        cc_ccai_ollama_cfg_install_model(cc_ccai_ollama_cfg_t.model);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_ollama_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_ccai_ollama_cfg_initflag == CC_TRUE));
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_ollama_cfg.c End!
****************************************************************************************************/

