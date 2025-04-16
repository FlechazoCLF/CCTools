
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef CODEEXAMPLE_H
#define CODEEXAMPLE_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
#include "file_dir.h"

/* ui */
#include <QWidget>
#include <QTextBrowser>
/****************************************************************************************************
* Define
****************************************************************************************************/
/* read deep */
#define CODEEXAMPLE_READDEEP_MAX (3u)
/* debug */
#define CODEEXAMPLE_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_CODEEXAMPLE,cc_codeexample_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class CodeExample;
}

class CodeExample : public QWidget
{
    Q_OBJECT

public:
    explicit CodeExample(QWidget *parent = nullptr);
    ~CodeExample();

private slots:
    void on_pushButton_sidebar_config_clicked();
    void on_pushButton_sidebar_operate_openlocal_clicked();
    void on_pushButton_sidebar_operate_openurl_clicked();
    void on_pushButton_sidebar_operate_import_clicked();
    void on_pushButton_sidebar_operate_export_clicked();
    void on_lineEdit_sidebar_config_path_editingFinished();
    void on_treeWidget_sidebar_codelist_my_itemSelectionChanged();

private:
    Ui::CodeExample *ui;

    /* dir info */
    cc_file_dir_struct *dirinfo_t;
};

/* cc_codeexample*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_codeexample_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_codeexample_mainfunction(cc_void);

#endif // CODEEXAMPLE_H
/****************************************************************************************************
* File End!
****************************************************************************************************/
