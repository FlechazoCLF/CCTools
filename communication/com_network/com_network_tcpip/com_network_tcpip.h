
/****************************************************************************************************
* File com_network_tcpip.h Start!
****************************************************************************************************/

#ifndef _COM_NETWORK_TCPIP_H
#define _COM_NETWORK_TCPIP_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "com_network_tcpip_type.h"
/* log */
#include "log.h"
#include "kernel_cfg.h"
/* sub module */
#include "com_network_tcpip_server.h"
#include "com_network_tcpip_client.h"
/* components */

/* ui */
#include <QTextBrowser>
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/* debug */
#define COM_NETWORK_TCPIP_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_com_network_tcpip_t.textbrowser,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_com_network_tcpip */
typedef struct
{
    cc_uint8 id;

    /* server */
    cc_com_network_tcpip_server_struct server_t;
    /* client */
    cc_com_network_tcpip_client_struct client_t;
    /* view */
    QTextBrowser *textbrowser;
}cc_com_network_tcpip_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_com_network_tcpip_recv(cc_com_network_tcpip_role_struct role,cc_com_network_tcpip_rxdata_struct *rxdata_t);
cc_result cc_com_network_tcpip_mainfunction(cc_void);

#endif /* _COM_NETWORK_TCPIP_H */
/****************************************************************************************************
* File com_network_tcpip.h End!
****************************************************************************************************/

