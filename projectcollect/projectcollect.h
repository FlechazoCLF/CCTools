
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef PROJECTCOLLECT_H
#define PROJECTCOLLECT_H

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
#define PROJECTCOLLECT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_PROJECTCOLLECT,cc_projectcollect_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class ProjectCollect;
}

class ProjectCollect : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCollect(QWidget *parent = nullptr);
    ~ProjectCollect();

private:
    Ui::ProjectCollect *ui;
};

/* cc_projectcollect_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_projectcollect_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_projectcollect_mainfunction(cc_void);


#endif // PROJECTCOLLECT_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
