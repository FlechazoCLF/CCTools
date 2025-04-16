/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef FILE_PDF_H
#define FILE_PDF_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QWidget>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class File_Pdf;
}

class File_Pdf : public QWidget
{
    Q_OBJECT

public:
    explicit File_Pdf(QWidget *parent = nullptr);
    ~File_Pdf();

private slots:
    void on_lineEdit_pdfium_editingFinished();

    void on_pushButton_pdfium_clicked();

    void on_pushButton_pdf_to_img_input_path_clicked();

    void on_pushButton_pdf_to_img_input_read_clicked();

    void on_lineEdit_pdf_to_img_input_path_editingFinished();

    void on_pushButton_pdf_to_img_output_operate_clicked();

    void on_pushButton_pdf_to_img_output_path_clicked();

    void on_spinBox_pdf_to_img_config_dpi_valueChanged(int arg1);

private:
    Ui::File_Pdf *ui;
};

/****************************************************************************************************
* Function Interface
****************************************************************************************************/

#endif // FILE_PDF_H
/****************************************************************************************************
* File End!
****************************************************************************************************/
