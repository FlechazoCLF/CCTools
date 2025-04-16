
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network.h"
/* log */
#include "log.h"
/* sub module */
#include "com_network_tcpip.h"
#include "com_network_tcpip_cfg.h"
#include "com_network_tcpip_server.h"
#include "com_network_http.h"
#include "com_network_http_cfg.h"
/* components */

/* ui */
#include "ui_com_network.h"
/* cpp */

/****************************************************************************************************
* Global Variable
****************************************************************************************************/
cc_com_network_struct cc_com_network_t;

/****************************************************************************************************
* Com_Network()
****************************************************************************************************/
Com_Network::Com_Network(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Com_Network)
{
    ui->setupUi(this);

    /* init tcpip */
    cc_com_network_tcpip_struct cfg;
    /* server */
    cfg.server_t.tcp_server = new QTcpServer();
    cfg.server_t.udp_socket = new QUdpSocket();
    cfg.server_t.qpushbutton_open = this->ui->pushButton_config_tcpip_server;
    cfg.server_t.qcomboBox_ip = this->ui->comboBox_config_tcpip_server_ip;
    cfg.server_t.qlineedit_port = this->ui->lineEdit_config_tcpip_server_port;
    cfg.server_t.comboBox_type = this->ui->comboBox_config_tcpip_server_type;
    cfg.server_t.qlineedit_send = this->ui->lineEdit_com_view_operate_send;
    cfg.server_t.qcheckbox_hexrx = this->ui->checkBox_com_view_operate_hexrecv;
    cfg.server_t.qcheckbox_hextx = this->ui->checkBox_com_view_operate_hexsend;
    cfg.server_t.qtablewidget_client = this->ui->tableWidget_config_tcpip_server_device_view;
    cfg.server_t.qtextbrower = this->ui->textBrowser_com_view;
    /* client */
    cfg.client_t.tcp_socket = new QTcpSocket();
    cfg.client_t.udp_socket = new QUdpSocket();
    cfg.client_t.qpushbutton_open = this->ui->pushButton_config_tcpip_client;
    cfg.client_t.qcomboBox_ip = this->ui->comboBox_config_tcpip_client_ip;
    cfg.client_t.qlineedit_port = this->ui->lineEdit_config_tcpip_client_port;
    cfg.client_t.comboBox_type = this->ui->comboBox_config_tcpip_client_type;
    cfg.client_t.qlineedit_send = this->ui->lineEdit_com_view_operate_send;
    cfg.client_t.qcheckbox_hexrx = this->ui->checkBox_com_view_operate_hexrecv;
    cfg.client_t.qcheckbox_hextx = this->ui->checkBox_com_view_operate_hexsend;
    cfg.client_t.qtextbrower = this->ui->textBrowser_com_view;
    /* view */
    cfg.textbrowser = this->ui->textBrowser_com_view;
    cc_com_network_t.qtextbrower = this->ui->textBrowser_com_view;

    this->cc_com_network_tcpip_init(&cfg);
}

Com_Network::~Com_Network()
{
    delete ui;
}

/****************************************************************************************************
* cc_com_network_print()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_print(QString info)
{
    cc_result result = CC_E_OK;

    do
    {
        this->ui->textBrowser_com_view->append(info);
    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_config_tcpip_server_clicked()
****************************************************************************************************/
void Com_Network::on_pushButton_config_tcpip_server_clicked()
{
    this->cc_com_network_tcpip_server_trigger();
}

/****************************************************************************************************
* on_pushButton_config_tcpip_client_clicked()
****************************************************************************************************/
void Com_Network::on_pushButton_config_tcpip_client_clicked()
{
    this->cc_com_network_tcpip_client_trigger();
}

/****************************************************************************************************
* on_pushButton_com_view_operate_send_clicked()
****************************************************************************************************/
void Com_Network::on_pushButton_com_view_operate_send_clicked()
{
    this->cc_com_network_tcpip_server_transmit();
    this->cc_com_network_tcpip_client_transmit();
}

/****************************************************************************************************
* cc_com_network_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_com_network_tcpip_mainfunction();
        cc_com_network_tcpip_cfg_mainfunction();
        cc_com_network_http_mainfunction();
        cc_com_network_http_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
