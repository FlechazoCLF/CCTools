
/****************************************************************************************************
* File ccai.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "ccai.h"
/* sub module */
#include "ccai_ollama.h"
#include "ccai_ollama_cfg.h"
#include "ccai_cfg.h"
/* components */
#include "script_cmd.h"
#include "mainwindow.h"
#include "ccai_writer_cfg.h"

/* ui */
#include "ui_ccai.h"
/* cpp */
#include <QFileDialog>
#include <QString>
#include <QDesktopServices>

/****************************************************************************************************
* Variable
****************************************************************************************************/
/* cc_ccai_t */
cc_ccai_struct cc_ccai_t;

/****************************************************************************************************
* CCAI()
****************************************************************************************************/
CCAI::CCAI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CCAI)
{
    ui->setupUi(this);

    /* add model */
    cc_ccai_ollama_cfg_add_models(this->ui->comboBox_ccai_chat_model_select);

    /* register cmd */
    cc_ccai_t.qtextbrower = this->ui->textBrowser_ccai_chat_output;
    cc_script_cmd_register_recv(1,cc_ccai_cmd_recv);

    /* init ollama */
    cc_ccai_ollama_struct cfg_t;
    cfg_t.qComboBox_model = this->ui->comboBox_ccai_chat_model_select;
    cfg_t.qtextbrower = cc_ccai_t.qtextbrower;
    cfg_t.recv = cc_ccai_recv;
    cc_ccai_ollama_init(&cfg_t);

    /* init ccai_writer */
    CCAI_WriterWindow = new CCAI_Writer();

    /* log */
    CCAI_LOG_PRINT("Init Complete!");
}

CCAI::~CCAI()
{
    delete ui;
}

/****************************************************************************************************
* cc_ccai_init()
****************************************************************************************************/
cc_result cc_ccai_init(cc_ccai_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cfg_t);

        /* impletement */
        cc_ccai_ollama_cfg_init(&cfg_t->ollama_cfg_t);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_install()
****************************************************************************************************/
cc_result cc_ccai_install(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* impletement */
        cc_ccai_ollama_cfg_install();

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_downloadpath_select()
****************************************************************************************************/
cc_result cc_ccai_ollama_downloadpath_select(QLineEdit *qLineEdit)
{
    cc_result result = CC_E_OK;

    do
    {
#if (CCAI_CONFIG_USE_URL == CC_TRUE)
        /* ollama url */
        QString downloadpath = "https://ollama.com/download";
        QUrl url(downloadpath);

        /* open url */
        if (QDesktopServices::openUrl(url) != CC_TRUE)
        {
            qDebug() << "open url error!";
        }
        qLineEdit->setText(downloadpath);
#else
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(nullptr,
                                                              QObject::tr("请选择一个目录下载ollama哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        /* set path */
        qDebug() << "Selected directory:" << directory;
        qLineEdit->setText(directory);
#endif /* CCAI_CONFIG_USE_URL == CC_TRUE */
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_ollama_installpath_select()
****************************************************************************************************/
cc_result cc_ccai_ollama_installpath_select(QLineEdit *qLineEdit)
{
    cc_result result = CC_E_OK;

    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(nullptr,
                                                              QObject::tr("请选择一个目录安装ollama哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        /* set path */
        qDebug() << "Selected directory:" << directory;
        qLineEdit->setText(directory);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_cmd_recv()
****************************************************************************************************/
cc_result cc_ccai_cmd_recv(QProcess *process,QByteArray qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,process);
        CHECK_PTR(result,cc_ccai_t.qtextbrower);
        /* rx */
        QString text = QString::fromLocal8Bit(qbytearray);
        cc_ccai_t.qtextbrower->append(text);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_send_cmd_check()
****************************************************************************************************/
cc_result CCAI::cc_ccai_send_cmd_check(QString *cmd)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,cmd);
        /* impletement */
        /* check ollama cmd */
        cc_ccai_ollama_send_cmd_check(cmd);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_send_mode_check()
****************************************************************************************************/
cc_result cc_ccai_send_mode_check(QString cmd)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        if (cmd.contains("ollama run") == CC_TRUE)
        {
            cc_ccai_t.mode = CC_CCAI_MODEL_OLLAMA;
            cc_ccai_t.qtextbrower->append("switch to ollama!");
        }
        else if (cmd.contains("cmd run") == CC_TRUE)
        {
            cc_ccai_t.mode = CC_CCAI_MODEL_CMD;
            cc_ccai_t.qtextbrower->append("switch to cmd!");
        }
        else
        {
            /* do nothing */
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_chat_input_send_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_chat_input_send_clicked()
{
    cc_result result = CC_E_OK;

    do
    {
        /* tx */
        QString cmd = this->ui->textEdit_ccai_chat_input->toPlainText();
        this->ui->textEdit_ccai_chat_input->clear();
        /* impletement */
        switch (cc_ccai_t.mode)
        {
        case CC_CCAI_MODEL_CMD:
            {
                /* cmd */
                QProcess *process;
                cc_script_cmd_get(&process);
                /* check cmd */
                this->cc_ccai_send_cmd_check(&cmd);
                /* send */
                cc_script_cmd_send(process,cmd);
            }
            break;
        case CC_CCAI_MODEL_OLLAMA:
            {
                cc_ccai_ollama_http_send(cmd);
            }
            break;
        default:
            break;
        }
        /* check */
        cc_ccai_send_mode_check(cmd);

    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return;
}

/****************************************************************************************************
* on_comboBox_ccai_chat_tools_select_currentTextChanged()
****************************************************************************************************/
void CCAI::on_comboBox_ccai_chat_tools_select_currentTextChanged(const QString &arg1)
{
    cc_ccai_cfg_tools_enum ctrlidx;
    /* get ctrlidx */
    cc_ccai_cfg_get_toolctrlidx(&ctrlidx,arg1);
    /* impletement */
    switch (ctrlidx)
    {
    case CC_CCAI_CFG_TOOLS_CHAT:
        {
        }
        break;
    case CC_CCAI_CFG_TOOLS_WRITER:
        {
            CC_MAIN_WINDOWS_CTRL_SHOW(CCAI_WriterWindow,CCAI_Writer);
        }
        break;
    case CC_CCAI_CFG_TOOLS_MUSIC:
        {
            ____________________TO_DO____________________
        }
        break;
    case CC_CCAI_CFG_TOOLS_VIDEO:
        {
            ____________________TO_DO____________________
        }
        break;
    case CC_CCAI_CFG_TOOLS_FACE:
        {
            ____________________TO_DO____________________
        }
        break;
    case CC_CCAI_CFG_TOOLS_SOUND:
        {
            ____________________TO_DO____________________
        }
        break;
    default:
        break;
    }
}

/****************************************************************************************************
* cc_ccai_send()
****************************************************************************************************/
cc_result cc_ccai_send(QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(content != ""));
        /* send */
        switch (cc_ccai_t.mode)
        {
        case CC_CCAI_MODEL_CMD:
            break;
        case CC_CCAI_MODEL_OLLAMA:
            {
                cc_ccai_ollama_http_send(content);
            }
            break;
        default:
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_ccai_recv()
****************************************************************************************************/
cc_result cc_ccai_recv(QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(content != ""));
        /* recv */
        cc_ccai_cfg_recv(content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_ccai_sidebar_newchat_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_sidebar_newchat_clicked()
{
    /* new chat */
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_ccai_sidebar_login_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_sidebar_login_clicked()
{
    /* login */
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_ccai_chat_input_enablethink_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_chat_input_enablethink_clicked()
{
    /* think */
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_ccai_chat_input_enableweb_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_chat_input_enableweb_clicked()
{
    /* web */
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_ccai_chat_input_file_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_chat_input_file_clicked()
{
    /* input file */
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_ccai_chat_input_img_clicked()
****************************************************************************************************/
void CCAI::on_pushButton_ccai_chat_input_img_clicked()
{
   /* input img */
   ____________________TO_DO____________________
}

/****************************************************************************************************
* cc_ccai_mainfunction()
****************************************************************************************************/
cc_result cc_ccai_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_ccai_ollama_mainfunction();
        cc_ccai_ollama_cfg_mainfunction();
        cc_ccai_writer_mainfunction();
        cc_ccai_writer_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File ccai.c End!
****************************************************************************************************/
