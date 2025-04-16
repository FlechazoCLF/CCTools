/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "file_pdf.h"
/* log */
/* sub module */
#include "file_pdf_pdfium.h"
/* components */

/* ui */
#include "ui_file_pdf.h"
/* cpp */
#include <QFileDialog>

/****************************************************************************************************
* Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* File_Pdf()
****************************************************************************************************/
File_Pdf::File_Pdf(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File_Pdf)
{
    ui->setupUi(this);
    /* init */
    cc_file_pdf_pdfium_init();
}

File_Pdf::~File_Pdf()
{
    /* unload pdfium */
    cc_file_pdf_pdfium_unloaddll();
    /* ui */
    delete ui;
}

/****************************************************************************************************
* on_lineEdit_pdfium_editingFinished()
****************************************************************************************************/
void File_Pdf::on_lineEdit_pdfium_editingFinished()
{
    /* load dll */
    cc_file_pdf_pdfium_loaddll(this->ui->lineEdit_pdfium->text());
}

/****************************************************************************************************
* on_pushButton_pdfium_clicked()
****************************************************************************************************/
void File_Pdf::on_pushButton_pdfium_clicked()
{
    cc_result result = CC_E_OK;

    do
    {
        /* select dll */
        QString dllPath = QFileDialog::getOpenFileName(nullptr,
                                                       "select dll file",
                                                       "",
                                                       "(*.dll)"
                                                       );
        /* check */
        CHECK_LOGIC(result,(dllPath != ""));
        /* display */
        this->ui->lineEdit_pdfium->setText(dllPath);
        /* load */
        this->on_lineEdit_pdfium_editingFinished();
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

/****************************************************************************************************
* on_pushButton_pdf_to_img_input_path_clicked()
****************************************************************************************************/
void File_Pdf::on_pushButton_pdf_to_img_input_path_clicked()
{
    cc_result result = CC_E_OK;

    do
    {
        /* select dll */
        QString pdfPath = QFileDialog::getOpenFileName(nullptr,
                                                       "select pdf file",
                                                       "",
                                                       "(*.pdf)"
                                                       );
        /* check */
        CHECK_LOGIC(result,(pdfPath != ""));
        /* display */
        this->ui->lineEdit_pdf_to_img_input_path->setText(pdfPath);
        /* load */
        this->on_lineEdit_pdf_to_img_input_path_editingFinished();
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

/****************************************************************************************************
* on_pushButton_pdf_to_img_input_read_clicked()
****************************************************************************************************/
void File_Pdf::on_pushButton_pdf_to_img_input_read_clicked()
{
    /* get pdf info */
}

/****************************************************************************************************
* on_lineEdit_pdf_to_img_input_path_editingFinished()
****************************************************************************************************/
void File_Pdf::on_lineEdit_pdf_to_img_input_path_editingFinished()
{
    /* selected pdf */
    this->on_pushButton_pdf_to_img_input_read_clicked();
}

/****************************************************************************************************
* on_pushButton_pdf_to_img_output_operate_clicked()
****************************************************************************************************/
void File_Pdf::on_pushButton_pdf_to_img_output_operate_clicked()
{
    cc_result result = CC_E_OK;
    QList<QImage> images;

    do
    {
        /* pdf path */
        QString pdfpath = this->ui->lineEdit_pdf_to_img_input_path->text();
        /* pdf -> img */
        cc_file_pdf_pdfium_convert_pdf_to_img(pdfpath,&images);
        /* save path */
        QString imgpath = this->ui->lineEdit_pdf_to_img_output_path->text();
        /* save img */
        cc_file_pdf_pdfium_output_img(&images,imgpath);
    }while(0u);

    if(result != CC_E_OK)
    {
        /* error */
    }
}

/****************************************************************************************************
* on_pushButton_pdf_to_img_output_path_clicked()
****************************************************************************************************/
void File_Pdf::on_pushButton_pdf_to_img_output_path_clicked()
{
    /* select path */
    QString directory = QFileDialog::getExistingDirectory(this,
                                                          tr("请选择一个目录输出图片哦🍔"),
                                                          QDir::currentPath(),
                                                          QFileDialog::ShowDirsOnly);
    /* set */
    this->ui->lineEdit_pdf_to_img_output_path->setText(directory);
}

/****************************************************************************************************
* on_spinBox_pdf_to_img_config_dpi_valueChanged()
****************************************************************************************************/
void File_Pdf::on_spinBox_pdf_to_img_config_dpi_valueChanged(int arg1)
{
    /* dpi */
}

/****************************************************************************************************
* cc_file_pdf_mainfunction()
****************************************************************************************************/
cc_result cc_file_pdf_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
