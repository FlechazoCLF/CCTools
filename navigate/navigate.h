
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef NAVIGATE_H
#define NAVIGATE_H

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
#define NAVIGATE_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_NAVIGATE,cc_navigate_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Navigate;
}

class Navigate : public QWidget
{
    Q_OBJECT

public:
    explicit Navigate(QWidget *parent = nullptr);
    ~Navigate();

private:
    Ui::Navigate *ui;
};

/* cc_navigate_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_navigate_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_navigate_mainfunction(cc_void);


#endif // NAVIGATE_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
