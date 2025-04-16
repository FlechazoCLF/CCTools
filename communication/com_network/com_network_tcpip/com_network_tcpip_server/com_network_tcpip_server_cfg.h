
/****************************************************************************************************
* File com_network_tcpip_server_cfg.h Start!
****************************************************************************************************/

#ifndef _COM_NETWORK_TCPIP_SERVER_CFG_H
#define _COM_NETWORK_TCPIP_SERVER_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "com_network_tcpip_server.h"
/* log */
/* sub module */
/* components */

/* ui */
#include "qtablewidget.h"
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_com_network_tcpip_server_cfg_clientinfo_index_enum */
typedef enum
{
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_IDX = 0,
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_IP,
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_PORT,
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_ID,
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_STATUS,
    CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_END
}cc_com_network_tcpip_server_cfg_clientinfo_index_enum;

/* cc_com_network_tcpip_server_cfg */
typedef struct
{
    QString index;
    QString ip;
    QString port;
    QString id;
    QString status;
}cc_com_network_tcpip_server_cfg_clientinfo_struct;

/* cc_com_network_tcpip_server_cfg */
typedef struct
{
    cc_uint8 id;
    cc_com_network_tcpip_server_cfg_clientinfo_struct clientinfoheader;
}cc_com_network_tcpip_server_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_com_network_tcpip_server_cfg_init(QTableWidget *qtablewidget);
cc_result cc_com_network_tcpip_server_cfg_mainfunction(cc_void);
cc_result cc_com_network_tcpip_server_cfg_clienttable_append(QTableWidget *qtablewidget,cc_com_network_tcpip_server_clientinfo_struct *clientinfo);

#endif /* _COM_NETWORK_TCPIP_SERVER_CFG_H */
/****************************************************************************************************
* File com_network_tcpip_server_cfg.h End!
****************************************************************************************************/

