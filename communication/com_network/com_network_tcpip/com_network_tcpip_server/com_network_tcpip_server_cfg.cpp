
/****************************************************************************************************
* File com_network_tcpip_server_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network_tcpip_server_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_com_network_tcpip_server_cfg */
cc_com_network_tcpip_server_cfg_struct cc_com_network_tcpip_server_cfg_t =
{
    .id = 0,
    .clientinfoheader =
    {
        .index = "序号",
        .ip = "IP地址",
        .port = "端口",
        .id = "客户端ID",
        .status = "状态"
    }
};

/* init flag */
cc_boolean cc_com_network_tcpip_server_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_network_tcpip_server_cfg_init()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_cfg_init(QTableWidget *qtablewidget)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,qtablewidget);

        /* impletement */
        qtablewidget->setColumnCount(CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_END);
        /* set header */
        QStringList headers;
        headers << cc_com_network_tcpip_server_cfg_t.clientinfoheader.index\
                << cc_com_network_tcpip_server_cfg_t.clientinfoheader.ip\
                << cc_com_network_tcpip_server_cfg_t.clientinfoheader.port\
                << cc_com_network_tcpip_server_cfg_t.clientinfoheader.id\
                << cc_com_network_tcpip_server_cfg_t.clientinfoheader.status;
        qtablewidget->setHorizontalHeaderLabels(headers);

        cc_com_network_tcpip_server_cfg_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_cfg_clienttable_append()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_cfg_clienttable_append(QTableWidget *qtablewidget,cc_com_network_tcpip_server_clientinfo_struct *clientinfo)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,qtablewidget);
        CHECK_PTR(result,clientinfo);

        /* impletement */
        int currentRow = qtablewidget->rowCount();
        qtablewidget->insertRow(currentRow);
        /* item */
        QTableWidgetItem *item_idx = new QTableWidgetItem();
        QTableWidgetItem *item_ip = new QTableWidgetItem();
        QTableWidgetItem *item_port = new QTableWidgetItem();
        QTableWidgetItem *item_id = new QTableWidgetItem();
        QTableWidgetItem *item_status = new QTableWidgetItem();
        item_idx->setText(QString::number(currentRow));
        item_ip->setText(clientinfo->ip);
        item_port->setText(clientinfo->port);
        item_id->setText("00000000");
        item_status->setText("在线");
        qtablewidget->setItem(currentRow, CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_IDX, item_idx);
        qtablewidget->setItem(currentRow, CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_IP, item_ip);
        qtablewidget->setItem(currentRow, CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_PORT, item_port);
        qtablewidget->setItem(currentRow, CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_ID, item_id);
        qtablewidget->setItem(currentRow, CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_STATUS, item_status);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_network_tcpip_server_cfg.c End!
****************************************************************************************************/

