
/****************************************************************************************************
* File ccai.h Start!
****************************************************************************************************/
#ifndef CCAI_H
#define CCAI_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
#include "ccai_ollama.h"
#include "ccai_ollama_cfg.h"
#include "ccai_writer.h"

/* ui */
#include <QWidget>
#include "qlineedit.h"
#include <QTextBrowser>
/* cpp */
#include <QProcess>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* download path select */
#define CCAI_CONFIG_USE_URL (CC_TRUE)
/* debug */
#define CCAI_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_CCAI,cc_ccai_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class CCAI;
}

class CCAI : public QWidget
{
    Q_OBJECT

public:
    explicit CCAI(QWidget *parent = nullptr);
    ~CCAI();

private slots:
    void on_pushButton_ccai_chat_input_send_clicked();
    void on_pushButton_ccai_sidebar_newchat_clicked();
    void on_pushButton_ccai_sidebar_login_clicked();
    void on_pushButton_ccai_chat_input_enablethink_clicked();
    void on_pushButton_ccai_chat_input_enableweb_clicked();
    void on_pushButton_ccai_chat_input_file_clicked();
    void on_pushButton_ccai_chat_input_img_clicked();
    void on_comboBox_ccai_chat_tools_select_currentTextChanged(const QString &arg1);
    cc_result cc_ccai_send_cmd_check(QString *cmd);

private:
    Ui::CCAI *ui;

    CCAI_Writer *CCAI_WriterWindow;
};

/* cc_ccai_mode_enum*/
typedef enum
{
    CC_CCAI_MODEL_CMD = 0,
    CC_CCAI_MODEL_OLLAMA,
    CC_CCAI_MODEL_END
}cc_ccai_mode_enum;

/* cc_ccai*/
typedef struct
{
    cc_uint8 id;
    /* ollama */
    cc_ccai_ollama_struct ollama_t;
    cc_ccai_ollama_cfg_struct ollama_cfg_t;
    /* cmd rx display */
    QTextBrowser *qtextbrower;
    /* mode */
    cc_ccai_mode_enum mode;
}cc_ccai_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_ccai_init(cc_ccai_struct *cfg_t);
cc_result cc_ccai_install(cc_void);
cc_result cc_ccai_ollama_downloadpath_select(QLineEdit *qLineEdit);
cc_result cc_ccai_ollama_installpath_select(QLineEdit *qLineEdit);
cc_result cc_ccai_cmd_recv(QProcess *process,QByteArray qbytearray);
cc_result cc_ccai_mainfunction(cc_void);
cc_result cc_ccai_send(QString content);
cc_result cc_ccai_recv(QString content);

#endif // CCAI_H

/****************************************************************************************************
* End file
****************************************************************************************************/
