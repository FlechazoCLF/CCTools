
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef COMMUNICATION_H
#define COMMUNICATION_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
#include "com_serial.h"
#include "com_network.h"
/* components */

/* ui */
#include <QWidget>
#include <QTextBrowser>
/* cpp */


/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COMMUNICATION_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_communication_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Communication;
}

class Communication : public QWidget
{
    Q_OBJECT

public:
    explicit Communication(QWidget *parent = nullptr);
    ~Communication();

private slots:
    void on_pushButton_tool_create_driect_serial_clicked();
    void on_pushButton_tool_create_driect_ethernet_clicked();

    void on_pushButton_tool_create_driect_socket_clicked();

    void on_pushButton_tool_create_driect_usb_clicked();

private:
    Ui::Communication *ui;
    Com_Serial *Com_SerialWindow = nullptr;
    Com_Network *Com_NetworkWindow = nullptr;

};

/* cc_communication_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_communication_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_com_mainfunction(cc_void);


#endif // COMMUNICATION_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
