
/****************************************************************************************************
* File com_network_tcpip_client.h Start!
****************************************************************************************************/

#ifndef _COM_NETWORK_TCPIP_CLIENT_H
#define _COM_NETWORK_TCPIP_CLIENT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "com_network_tcpip_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include "qpushbutton.h"
#include "qcombobox.h"
#include "qlineedit.h"
#include "qtablewidget.h"
#include <QTextBrowser>
#include <QCheckBox>
/* cpp */
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <QUdpSocket>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COM_NETWORK_TCPIP_CLIENT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_com_network_tcpip_client_t->qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_com_network_tcpip_client */
typedef struct
{
    cc_uint8 id;

    /* server */
    QTcpSocket *tcp_socket;
    QUdpSocket *udp_socket;

    /* ui */
    QPushButton *qpushbutton_open;
    QComboBox *qcomboBox_ip;
    QLineEdit *qlineedit_port;
    QLineEdit *qlineedit_send;
    QComboBox *comboBox_type;
    QCheckBox *qcheckbox_hexrx;
    QCheckBox *qcheckbox_hextx;

    /* user callback */
    cc_result (*receive)(cc_com_network_tcpip_role_struct role,cc_com_network_tcpip_rxdata_struct *rxdata_t);

    /* log */
    QTextBrowser *qtextbrower;
}cc_com_network_tcpip_client_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_com_network_tcpip_client_mainfunction(cc_void);

#endif /* _COM_NETWORK_TCPIP_CLIENT_H */
/****************************************************************************************************
* File com_network_tcpip_client.h End!
****************************************************************************************************/

