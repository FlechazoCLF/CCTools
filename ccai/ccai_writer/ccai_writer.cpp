/****************************************************************************************************
* File ccai_writer.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "ccai_writer.h"
/* sub module */
/* components */
#include "ccai.h"
#include "ccai_writer_cfg.h"
#include "ccai_writer_chat.h"
#include "ccai_writer_generate.h"
#include "ccai_writer_convert.h"

/* ui */
#include "ui_ccai_writer.h"
/* cpp */

/****************************************************************************************************
* Variable
****************************************************************************************************/

/* state */
cc_ccai_writer_workflow_enum *cc_ccai_writer_workflow_state;

/****************************************************************************************************
* CCAI()
****************************************************************************************************/
CCAI_Writer::CCAI_Writer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CCAI_Writer)
{
    ui->setupUi(this);
    /* init state */
    this->writer.state = CC_CCAI_WRITER_WORKFLOW_FREE;
    cc_ccai_writer_workflow_state = &this->writer.state;
    /* init view */
    this->ui->toolBox_ccai_writer->setCurrentIndex(CC_CCAI_WRITER_WORKFLOW_FREE);
}

CCAI_Writer::~CCAI_Writer()
{
    delete ui;
}

/****************************************************************************************************
* cc_ccai_writer_get_state()
****************************************************************************************************/
cc_result cc_ccai_writer_get_state(cc_ccai_writer_workflow_enum *state)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,state);
        CHECK_PTR(result,cc_ccai_writer_workflow_state);
        /* impletement */
        *state = *cc_ccai_writer_workflow_state;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_writer_enter_state()
****************************************************************************************************/
cc_result CCAI_Writer::cc_ccai_writer_enter_state(cc_ccai_writer_workflow_enum state)
{
    cc_result result = CC_E_OK;

    do
    {
        /* impletement */
        this->writer.state = state;
        this->ui->toolBox_ccai_writer->setCurrentIndex(state);
    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_1_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_1_confirm_clicked()
{
    /* 1.get input content */
    cc_ccai_writer_chat_input_step1_title(&this->writer,this->ui->textEdit_ccai_writer_1_title->toPlainText());
    cc_ccai_writer_chat_input_step1_content(&this->writer,this->ui->textEdit_ccai_writer_1_content->toPlainText());
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_1_INPUT_TITLE);
    /* callback */
    cc_ccai_writer_step1_to_step2();
}

void CCAI_Writer::on_pushButton_ccai_writer_1_random_clicked()
{
    /* 1.random content */
}

cc_result CCAI_Writer::cc_ccai_writer_step1_to_step2(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_2_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_2_confirm_clicked()
{
    /* 1.get input content */
    cc_ccai_writer_chat_input_step2_usercontent(&this->writer,this->ui->textEdit_ccai_writer_2->toPlainText());
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_2_INPUT_USERCONTENT);
    /* callback */
    cc_ccai_writer_step2_to_step3();
}

void CCAI_Writer::on_pushButton_ccai_writer_2_default_clicked()
{

}

cc_result CCAI_Writer::cc_ccai_writer_step2_to_step3(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* impletement */
        cc_ccai_writer_chat_step2_generate_article(&this->writer);

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_3_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_3_confirm_clicked()
{
    /* 1.get article */
    cc_ccai_writer_chat_recvbuffer_get(&this->writer.article);
    /* 2.get input content */
    this->writer.workflow.step3_optimizecontent = this->ui->textEdit_ccai_writer_3_optimize->toPlainText();
    /* 3.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_3_OPTIMIZE_CONTENT);
    /* callback */
    cc_ccai_writer_step3_to_step4();
}

void CCAI_Writer::on_pushButton_ccai_writer_3_regenerate_clicked()
{
    cc_ccai_writer_chat_recvbuffer_clear();
}

void CCAI_Writer::on_pushButton_ccai_writer_3_open_clicked()
{

}

void CCAI_Writer::on_pushButton_ccai_writer_3_optimize_clicked()
{
    /* clear */
    cc_ccai_writer_chat_recvbuffer_clear();
    /* optimize */
    cc_ccai_writer_chat_step3_optimize_article(&this->writer,this->ui->textEdit_ccai_writer_3_optimize->toPlainText());
}

cc_result CCAI_Writer::cc_ccai_writer_step3_to_step4(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_4_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_4_confirm_clicked()
{
    cc_result result = CC_E_OK;

    do
    {
        /* 1.get input content */
        this->writer.workflow.step4.generatepath = this->ui->lineEdit_ccai_writer_4_base_path->text();
        this->writer.workflow.step4.cover = this->ui->comboBox_ccai_writer_4_base_cover->currentText();
        this->writer.workflow.step4.catalogue = this->ui->comboBox_ccai_writer_4_base_catalogue->currentText();
        this->writer.workflow.step4.header = this->ui->comboBox_writer_4_base_articleheader->currentText();
        this->writer.workflow.step4.footer = this->ui->comboBox_writer_4_base_articlefooter->currentText();
        /* check */
        CHECK_LOGIC(result,(this->writer.workflow.step4.generatepath != ""));
        /* generate markdown */
        cc_ccai_writer_generate_step4_markdown(&this->writer);
        /* 3.next */
        cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_4_CONVERT_MARKDOWN);
        /* callback */
        cc_ccai_writer_step4_to_step5();
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

cc_result CCAI_Writer::cc_ccai_writer_step4_to_step5(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_5_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_5_confirm_clicked()
{
    cc_result result = CC_E_OK;
    QString markmap;

    do
    {
        /* 1.get input content */
        this->writer.workflow.step5_xmind_generatepath = this->ui->lineEdit_ccai_writer_5_path->text();
        /* check */
        CHECK_LOGIC(result,(this->writer.workflow.step5_xmind_generatepath != ""));
        /* covert md to xmind */
        cc_ccai_writer_convert_markdown_to_markmap(&markmap,this->writer.article);
        this->ui->textBrowser_ccai_writer_5->setHtml(markmap);
        /* 2.next */
        cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_5_CONVERT_XMIND);
        /* callback */
        cc_ccai_writer_step5_to_step6();
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

cc_result CCAI_Writer::cc_ccai_writer_step5_to_step6(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_6_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_6_confirm_clicked()
{
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_6_DISPLAY_XMIND);
    /* callback */
    cc_ccai_writer_step6_to_step7();
}

cc_result CCAI_Writer::cc_ccai_writer_step6_to_step7(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_7_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_7_confirm_clicked()
{
    /* 1.get input content */
    this->writer.workflow.step7.catalogue = this->ui->comboBox_ccai_writer_7_catalogue->currentText();
    this->writer.workflow.step7.xmind = this->ui->comboBox_ccai_writer_7_xmind->currentText();
    this->writer.workflow.step7.header = this->ui->comboBox_ccai_writer_7_articleheader->currentText();
    this->writer.workflow.step7.usercontent = this->ui->comboBox_ccai_writer_7_usercontent->currentText();
    this->writer.workflow.step7.article = this->ui->comboBox_ccai_writer_7_article->currentText();
    this->writer.workflow.step7.footer = this->ui->comboBox_ccai_writer_7_articlefooter->currentText();
    /* combine article */
    cc_ccai_writer_generate_step7_combine(&(this->writer));
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_7_GENERATE_CREATE);
    /* callback */
    cc_ccai_writer_step7_to_step8();
}

cc_result CCAI_Writer::cc_ccai_writer_step7_to_step8(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_8_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_8_confirm_clicked()
{
    /* 1.get input content */
    this->writer.workflow.step8_markdown_generatepath = this->ui->lineEdit_ccai_writer_8_path->text();
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_8_GENERATE_MARKDOWN);
    /* callback */
    cc_ccai_writer_step8_to_step9();
}

cc_result CCAI_Writer::cc_ccai_writer_step8_to_step9(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_9_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_9_confirm_clicked()
{
    /* 1.get input content */
    this->writer.workflow.step9_platform = this->ui->comboBox_ccai_writer_9_platform->currentText();
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_9_RELEASE);
    /* callback */
    cc_ccai_writer_step9_to_step10();
}

cc_result CCAI_Writer::cc_ccai_writer_step9_to_step10(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,CC_NULL_PTR);
        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_writer_10_confirm_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_10_confirm_clicked()
{
    /* 2.next */
    cc_ccai_writer_enter_state(CC_CCAI_WRITER_WORKFLOW_10_COMPLETE);
    /* callback */
}

/****************************************************************************************************
* on_pushButton_ccai_writer_4_base_path_clicked()
****************************************************************************************************/
void CCAI_Writer::on_pushButton_ccai_writer_4_base_path_clicked()
{

}

/****************************************************************************************************
* cc_ccai_writer_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_writer_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai_writer.c End!
****************************************************************************************************/
