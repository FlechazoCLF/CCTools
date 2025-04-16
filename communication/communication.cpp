
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "communication.h"
/* log */
/* sub module */
#include "com_network.h"
/* components */
#include "mainwindow.h"

/* ui */
#include "ui_communication.h"
/* cpp */

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_communication_struct cc_communication_t;

/****************************************************************************************************
* Communication()
****************************************************************************************************/
Communication::Communication(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Communication)
{
    ui->setupUi(this);

    cc_communication_t.qtextbrower = this->ui->textBrowser_tool_view;
}

Communication::~Communication()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_tool_create_driect_serial_clicked()
****************************************************************************************************/
void Communication::on_pushButton_tool_create_driect_serial_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(Com_SerialWindow,Com_Serial);
}

/****************************************************************************************************
* on_pushButton_tool_create_driect_ethernet_clicked()
****************************************************************************************************/
void Communication::on_pushButton_tool_create_driect_ethernet_clicked()
{
    /* create network */
    CC_MAIN_WINDOWS_CTRL_SHOW(Com_NetworkWindow,Com_Network);
}

/****************************************************************************************************
* on_pushButton_tool_create_driect_socket_clicked()
****************************************************************************************************/
void Communication::on_pushButton_tool_create_driect_socket_clicked()
{
    /* create network */
    CC_MAIN_WINDOWS_CTRL_SHOW(Com_NetworkWindow,Com_Network);
}

/****************************************************************************************************
* on_pushButton_tool_create_driect_usb_clicked()
****************************************************************************************************/
void Communication::on_pushButton_tool_create_driect_usb_clicked()
{
    ____________________TO_DO____________________
}

/****************************************************************************************************
* cc_com_mainfunction()
****************************************************************************************************/
cc_result cc_com_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_com_network_mainfunction();
        cc_com_serial_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
