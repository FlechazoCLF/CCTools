
/****************************************************************************************************
* File com_network_http.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network_http.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_com_network_http */
cc_com_network_http_struct cc_com_network_http_t;
QList<cc_com_network_http_struct> cc_com_network_http_t_list;
/* init flag */
cc_boolean cc_com_network_http_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_network_http_init()
****************************************************************************************************/
cc_result cc_com_network_http_init(cc_com_network_http_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->qtextbrower);
        /* impletement */
        cc_com_network_http_t.qtextbrower = cfg_t->qtextbrower;
        cc_com_network_http_t_list.clear();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_http_init()
****************************************************************************************************/
cc_result cc_com_network_http_create(QString name,cc_uint32 *ctrlidx,cc_result (*recv)(cc_uint32 ctrlidx,QString content))
{
    cc_result result = CC_E_OK;
    cc_com_network_http_struct new_network_http_t;

    do
    {
        /* check */
        CHECK_PTR(result,ctrlidx);
        CHECK_LOGIC(result,(name != ""));
        /* impletement */
        new_network_http_t.name = name;
        new_network_http_t.ctrlidx = cc_com_network_http_t_list.count();
        new_network_http_t.qnetworkaccessmanager = new QNetworkAccessManager();
        new_network_http_t.reply = (QNetworkReply *)CC_NULL_PTR;
        new_network_http_t.url = "";
        new_network_http_t.recv = recv;
        /* init */
        cc_com_network_http_t_list.append(new_network_http_t);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_http_send()
****************************************************************************************************/
cc_result cc_com_network_http_send(cc_uint32 ctrlidx,QString url,QJsonObject *qjsonobject)
{
    cc_result result = CC_E_OK;
    cc_com_network_http_struct *network_http_t;

    do
    {
        /* check */
        CHECK_PTR(result,qjsonobject);
        CHECK_LOGIC(result,(ctrlidx < cc_com_network_http_t_list.count()));
        CHECK_LOGIC(result,(url != ""));

        /* impletement */
        /* get ctrl */
        network_http_t = &cc_com_network_http_t_list[ctrlidx];
        /* build */
        QUrl qurl(url);
        QNetworkRequest request(qurl);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray postData = QJsonDocument(*qjsonobject).toJson();
        /* send */
        network_http_t->reply = network_http_t->qnetworkaccessmanager->post(request, postData);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_http_recv()
****************************************************************************************************/
cc_result cc_com_network_http_recv(cc_uint32 ctrlidx,QString content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(ctrlidx < cc_com_network_http_t_list.count()));
        CHECK_LOGIC(result,(content != ""));
        /* impletement */

    }while(0u);

    if (result != CC_E_OK)
    {
        /* error */
    }

    return result;
}

/****************************************************************************************************
* cc_com_network_http_mainfunction_reply()
****************************************************************************************************/
cc_result cc_com_network_http_mainfunction_reply(cc_com_network_http_struct *network_http_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,network_http_t);
        /* impletement */
        CHECK_PTR(result,network_http_t->reply);
        /* can read */
        CHECK_LOGIC(result,(network_http_t->reply->canReadLine() == CC_TRUE));
        /* to json */
        QByteArray chunk = network_http_t->reply->readLine();
        QJsonDocument doc = QJsonDocument::fromJson(chunk);
        CHECK_LOGIC(result,(doc.isNull() != CC_TRUE));
        QJsonObject json = doc.object();
        /* get response */
        CHECK_LOGIC(result,(json.contains("response") == CC_TRUE));
        QString response = json["response"].toString();
        /* output */
        CHECK_PTR(result,network_http_t->recv);
        network_http_t->recv(network_http_t->ctrlidx,response);
        qDebug().noquote() << "AI recv:" << response;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_http_mainfunction_ctrl()
****************************************************************************************************/
cc_result cc_com_network_http_mainfunction_ctrl(cc_uint32 ctrlidx)
{
    cc_result result = CC_E_OK;
    cc_com_network_http_struct *network_http_t;

    do
    {
        /* check */
        CHECK_LOGIC(result,(ctrlidx < cc_com_network_http_t_list.count()));
        /* impletement */
        network_http_t = &cc_com_network_http_t_list[ctrlidx];
        cc_com_network_http_mainfunction_reply(network_http_t);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_http_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_http_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* foreach list */
        for (cc_uint32 ctrlidx = 0; ctrlidx < cc_com_network_http_t_list.count(); ++ctrlidx)
        {
            cc_com_network_http_mainfunction_ctrl(ctrlidx);
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_network_http.c End!
****************************************************************************************************/

