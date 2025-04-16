
/****************************************************************************************************
* File com_network_http.h Start!
****************************************************************************************************/

#ifndef _COM_NETWORK_HTTP_H
#define _COM_NETWORK_HTTP_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QTextBrowser>
/* cpp */
#include <QNetworkAccessManager>
/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COMMUNICATION_NETWORK_HTTP_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_com_network_http_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* cc_com_network_http */
typedef struct
{
    /* id */
    QString name;
    cc_uint32 ctrlidx;
    /* log */
    QTextBrowser *qtextbrower;
    /* network */
    QNetworkAccessManager *qnetworkaccessmanager;
    QString url;
    QNetworkReply *reply;
    /* callback */
    cc_result (*recv)(cc_uint32 ctrlidx,QString content);
}cc_com_network_http_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_com_network_http_init(cc_com_network_http_struct *cfg_t);
cc_result cc_com_network_http_create(QString name,cc_uint32 *ctrlidx,cc_result (*recv)(cc_uint32 ctrlidx,QString content));
cc_result cc_com_network_http_send(cc_uint32 ctrlidx,QString url,QJsonObject *qjsonobject);
cc_result cc_com_network_http_recv(cc_uint32 ctrlidx,QString content);
cc_result cc_com_network_http_mainfunction(cc_void);

#endif /* _COM_NETWORK_HTTP_H */
/****************************************************************************************************
* File com_network_http.h End!
****************************************************************************************************/

