
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "file.h"
/* log */
/* sub module */
#include "file_dir.h"
#include "file_dir_cfg.h"
#include "file_md.h"
#include "file_md_cfg.h"
/* components */

/* ui */
#include "ui_file.h"
/* cpp */
#include <QFileInfo>
#include <QDesktopServices>
#include <QMessageBox>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_file_struct cc_file_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* File()
****************************************************************************************************/
File::File(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);

    cc_file_t.qtextbrower = this->ui->textBrowser_sidebar_log;
}

File::~File()
{
    delete ui;
}

/****************************************************************************************************
* cc_file_open()
****************************************************************************************************/
cc_result cc_file_open(QString filepath)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filepath != ""));
        /* impletement */
        QFileInfo fileInfo(filepath);
        CHECK_LOGIC(result,(fileInfo.exists() == CC_TRUE));
        CHECK_LOGIC(result,(fileInfo.isFile() == CC_TRUE));
        /* get url */
        QUrl fileUrl = QUrl::fromLocalFile(filepath);
        if(QDesktopServices::openUrl(fileUrl) == CC_TRUE)
        {
            /* open successful */
        }
        else
        {
            result = CC_E_NOT_OK;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_create()
****************************************************************************************************/
cc_result cc_file_create(QString filePath,QString fileContent)
{
    cc_result result = CC_E_OK;
    QFile *file;
    QTextStream *textStream;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filePath != ""));
        /* check path */
        if(cc_file_dir_check(filePath) != CC_E_OK)
        {
            cc_file_dir_create(filePath);
        }
        /* open file */
        file = new QFile(filePath);
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            result = CC_E_NOT_OK;
            continue;
        }
        /* write file */
        textStream = new QTextStream(file);
        (*textStream) << fileContent;
        /* close file */
        file->close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_delete()
****************************************************************************************************/
cc_result cc_file_delete(QString filepath)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filepath != ""));
        /* impletement */
        QFileInfo fileInfo(filepath);
        CHECK_LOGIC(result,(fileInfo.exists() == CC_TRUE));
        CHECK_LOGIC(result,(fileInfo.isFile() == CC_TRUE));
        /* delete */
        int ret = QMessageBox::question(nullptr,
                                        "delete confirm",
                                        "confirm?",
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::No
                                        );
        CHECK_LOGIC(result,(ret == QMessageBox::Yes));
        if (QFile::remove(filepath) == CC_TRUE)
        {
            qDebug() << "delete successful:" << filepath;
        }
        else
        {
            qDebug() << "delete fail:" << filepath;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_read()
****************************************************************************************************/
cc_result cc_file_read(QString *fileContent,QString filePath)
{
    cc_result result = CC_E_OK;
    QFile *file;
    QTextStream *textStream;

    do
    {
        /* check */
        CHECK_PTR(result,fileContent);
        CHECK_LOGIC(result,(filePath != ""));
        /* open file */
        file = new QFile(filePath);
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            continue;
        }
        /* read file */
        textStream = new QTextStream(file);
        *fileContent = textStream->readAll();
        /* close file */
        file->close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_write()
****************************************************************************************************/
cc_result cc_file_write(QString filePath,QString fileContent,cc_file_writemode_enum mode)
{
    cc_result result = CC_E_OK;
    QFile *file;
    QTextStream *textStream;

    do
    {
        /* check */
        CHECK_LOGIC(result,(filePath != ""));
        /* open file */
        file = new QFile(filePath);
        if(mode == CC_FILE_WRITEMODE_APPEND)
        {
            if(!file->open(QIODevice::Append | QIODevice::Text))
            {
                continue;
            }
        }
        else
        {
            if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                continue;
            }
        }
        /* write file */
        textStream = new QTextStream(file);
        (*textStream) << fileContent;
        /* close file */
        file->close();
    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_file_config_open_clicked()
****************************************************************************************************/
void File::on_pushButton_file_config_open_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* on_pushButton_file_config_read_clicked()
****************************************************************************************************/
void File::on_pushButton_file_config_read_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* cc_file_mainfunction()
****************************************************************************************************/
cc_result cc_file_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_file_dir_mainfunction();
        cc_file_dir_cfg_mainfunction();
        cc_file_md_mainfunction();
        cc_file_md_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
