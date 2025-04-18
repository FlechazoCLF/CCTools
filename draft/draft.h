
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef DRAFT_H
#define DRAFT_H

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
#define DRAFT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_DRAFT,cc_draft_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Draft;
}

class Draft : public QWidget
{
    Q_OBJECT

public:
    explicit Draft(QWidget *parent = nullptr);
    ~Draft();

private:
    Ui::Draft *ui;
};

/* cc_draft_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_draft_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_draft_mainfunction(cc_void);


#endif // DRAFT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
