
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef COM_NETWORK_H
#define COM_NETWORK_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
#include "com_network_tcpip.h"
#include "com_network_tcpip_server.h"
/* components */

/* ui */
#include <QWidget>
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COM_NETWORK_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_com_network_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Com_Network;
}

class Com_Network : public QWidget
{
    Q_OBJECT

public:
    explicit Com_Network(QWidget *parent = nullptr);
    ~Com_Network();

    /* print */
    cc_result cc_com_network_print(QString info);

    /* cc_com_network_tcpip */
    cc_com_network_tcpip_struct cc_com_network_tcpip_t;

    /* tcpip server */
    /* cc_com_network_tcpip_server */
    cc_com_network_tcpip_server_struct cc_com_network_tcpip_server_t;
    cc_result cc_com_network_tcpip_init(cc_com_network_tcpip_struct *cfg);
    cc_result cc_com_network_tcpip_server_init(cc_com_network_tcpip_server_struct *cfg);
    cc_result cc_com_network_tcpip_server_trigger(cc_void);
    cc_result cc_com_network_tcpip_server_newconnection(cc_void);
    cc_result cc_com_network_tcpip_server_tcp_recv(cc_void);
    cc_result cc_com_network_tcpip_server_udp_recv(cc_void);
    cc_result cc_com_network_tcpip_server_clienttable_append(cc_com_network_tcpip_server_clientinfo_struct *clientinfo);
    cc_result cc_com_network_tcpip_server_init_ip(QComboBox *comboBox_ip);
    cc_result cc_com_network_tcpip_server_listen(cc_com_network_tcpip_server_struct *server_t);
    cc_result cc_com_network_tcpip_server_stop(cc_com_network_tcpip_server_struct *server_t);
    cc_result cc_com_network_tcpip_server_transmit(cc_void);
    cc_result cc_com_network_tcpip_server_write(QString type,QByteArray qbytearray);
    cc_result cc_com_network_tcpip_server_client_match(cc_com_network_tcpip_server_clientinfo_struct **client,QString ip,QString port);
    cc_result cc_com_network_tcpip_server_client_disconnected_callback();
    cc_result cc_com_network_tcpip_server_client_connected_callback();
    cc_result cc_com_network_tcpip_server_client_erroroccurred_callback(QAbstractSocket::SocketError error);

    /* tcpip client */
    /* cc_com_network_tcpip_client */
    cc_com_network_tcpip_client_struct cc_com_network_tcpip_client_t;
    cc_result cc_com_network_tcpip_client_init(cc_com_network_tcpip_client_struct *cfg);
    cc_result cc_com_network_tcpip_client_trigger(cc_void);
    cc_result cc_com_network_tcpip_client_init_ip(QComboBox *comboBox_ip);
    cc_result cc_com_network_tcpip_client_connect(cc_com_network_tcpip_client_struct *client_t);
    cc_result cc_com_network_tcpip_client_disconnect(cc_com_network_tcpip_client_struct *client_t);
    cc_result cc_com_network_tcpip_client_connected(cc_void);
    cc_result cc_com_network_tcpip_client_disconnected(cc_void);
    cc_result cc_com_network_tcpip_client_erroroccurred(QAbstractSocket::SocketError error);
    cc_result cc_com_network_tcpip_client_tcp_recv(cc_void);
    cc_result cc_com_network_tcpip_client_udp_recv(cc_void);
    cc_result cc_com_network_tcpip_client_transmit(cc_void);
    cc_result cc_com_network_tcpip_client_write(QString type,QByteArray *qbytearray);

private slots:
    void on_pushButton_config_tcpip_server_clicked();
    void on_pushButton_config_tcpip_client_clicked();
    void on_pushButton_com_view_operate_send_clicked();

private:
    Ui::Com_Network *ui;

};

/* cc_com_network_struct*/
typedef struct
{
    /* log */
    QTextBrowser *qtextbrower;
}cc_com_network_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
cc_result cc_com_network_mainfunction(cc_void);

#endif // COM_NETWORK_H
