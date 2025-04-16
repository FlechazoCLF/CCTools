
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef FILE_H
#define FILE_H

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
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define FILE_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_FILE,cc_file_t.qtextbrower,format,##__VA_ARGS__)

/* cc_file_writemode_enum */
typedef enum
{
    CC_FILE_WRITEMODE_APPEND = 0,
    CC_FILE_WRITEMODE_WRITEONLY,
    CC_FILE_WRITEMODE_END
}cc_file_writemode_enum;

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class File;
}

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();

private slots:
    void on_pushButton_file_config_open_clicked();

    void on_pushButton_file_config_read_clicked();

private:
    Ui::File *ui;
};

/* cc_file_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_file_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_file_mainfunction(cc_void);
cc_result cc_file_open(QString filepath);
cc_result cc_file_create(QString filePath,QString fileContent);
cc_result cc_file_delete(QString filepath);
cc_result cc_file_read(QString *fileContent,QString filePath);
cc_result cc_file_write(QString filePath,QString fileContent,cc_file_writemode_enum mode);


#endif // FILE_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
