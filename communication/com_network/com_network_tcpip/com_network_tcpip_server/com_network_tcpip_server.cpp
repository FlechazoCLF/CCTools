
/****************************************************************************************************
* File com_network_tcpip_server.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network.h"
#include "com_network_tcpip.h"
#include "com_network_tcpip_server.h"
#include "com_network_tcpip_server_cfg.h"
/* log */
/* sub module */
/* components */
#include "typeconvers.h"

/* ui */
#include "ui_com_network.h"
/* cpp */
#include <QNetworkInterface>
#include <QDateTime>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_com_network_tcpip_server_struct */
cc_com_network_tcpip_server_struct cc_com_network_tcpip_server_t;
/* init flag */
cc_boolean cc_com_network_tcpip_server_initflag = CC_FALSE;
/* rx buffer */
cc_com_network_tcpip_rxdata_struct cc_com_network_tcpip_server_rxdata_t;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_network_tcpip_server_init()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_init(cc_com_network_tcpip_server_struct *cfg)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg);
        CHECK_PTR(result,cfg->tcp_server);
        CHECK_PTR(result,cfg->udp_socket);
        CHECK_PTR(result,cfg->qpushbutton_open);
        CHECK_PTR(result,cfg->qcomboBox_ip);
        CHECK_PTR(result,cfg->qlineedit_port);
        CHECK_PTR(result,cfg->comboBox_type);
        CHECK_PTR(result,cfg->qcheckbox_hexrx);
        CHECK_PTR(result,cfg->qcheckbox_hextx);
        CHECK_PTR(result,cfg->qlineedit_send);
        CHECK_PTR(result,cfg->qtextbrower);
        CHECK_PTR(result,cfg->qtablewidget_client);
        CHECK_PTR(result,cfg->receive);

        /* impletement */
        COM_NETWORK_TCPIP_LOG_PRINT("tcpip server init start");

        this->cc_com_network_tcpip_server_t.tcp_server = cfg->tcp_server;
        this->cc_com_network_tcpip_server_t.udp_socket = cfg->udp_socket;
        this->cc_com_network_tcpip_server_t.qpushbutton_open = cfg->qpushbutton_open;
        this->cc_com_network_tcpip_server_t.qcomboBox_ip = cfg->qcomboBox_ip;
        this->cc_com_network_tcpip_server_t.qlineedit_port = cfg->qlineedit_port;
        this->cc_com_network_tcpip_server_t.qlineedit_send = cfg->qlineedit_send;
        this->cc_com_network_tcpip_server_t.comboBox_type = cfg->comboBox_type;
        this->cc_com_network_tcpip_server_t.qcheckbox_hexrx = cfg->qcheckbox_hexrx;
        this->cc_com_network_tcpip_server_t.qcheckbox_hextx = cfg->qcheckbox_hextx;
        this->cc_com_network_tcpip_server_t.qtextbrower = cfg->qtextbrower;
        this->cc_com_network_tcpip_server_t.receive = cfg->receive;
        this->cc_com_network_tcpip_server_t.qtablewidget_client = cfg->qtablewidget_client;

        /* init ip */
        cc_com_network_tcpip_server_init_ip(this->cc_com_network_tcpip_server_t.qcomboBox_ip);
        /* init type */
        this->cc_com_network_tcpip_server_t.comboBox_type->addItem("TCP");
        this->cc_com_network_tcpip_server_t.comboBox_type->addItem("UDP");

        /* TCP connect */
        connect(this->cc_com_network_tcpip_server_t.tcp_server,\
                &QTcpServer::newConnection,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_newconnection);
        /* UDP connect */
        connect(this->cc_com_network_tcpip_server_t.udp_socket,\
                &QUdpSocket::readyRead,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_udp_recv);

        /* init clienttable */
        cc_com_network_tcpip_server_cfg_init(this->cc_com_network_tcpip_server_t.qtablewidget_client);

        COM_NETWORK_TCPIP_LOG_PRINT("tcpip server init complete");
        cc_com_network_tcpip_server_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_init_ip()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_init_ip(QComboBox *comboBox_ip)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,comboBox_ip);

        /* impletement */
        for (int i = 0; i < QNetworkInterface().allAddresses().length(); ++i)
        {
            QHostAddress address = QNetworkInterface().allAddresses().at(i);
            if(address.protocol() != QAbstractSocket::IPv4Protocol)
            {
                continue;
            }
            /* add */
            QString ip = address.toString();
            comboBox_ip->addItem(ip);
            COM_NETWORK_TCPIP_LOG_PRINT("add ipv4:%x",address.toIPv4Address());
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_listen()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_listen(cc_com_network_tcpip_server_struct *server_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,server_t->tcp_server);
        CHECK_PTR(result,server_t->comboBox_type);
        CHECK_PTR(result,server_t->qcomboBox_ip);
        CHECK_PTR(result,server_t->qlineedit_port);
        CHECK_PTR(result,server_t->udp_socket);

        /* get ip */
        QString ip = server_t->qcomboBox_ip->currentText();
        /* get port */
        cc_uint16 port = server_t->qlineedit_port->text().toUInt();
        /* get type */
        if(server_t->comboBox_type->currentText() == "TCP")
        {
            /* TCP */
            /* impletement */
            server_t->tcp_server->listen(QHostAddress::Any, port);

            COM_NETWORK_TCPIP_LOG_PRINT("TCP server start listen");
        }
        else
        {
            /* UDP */
            /* impletement */
            server_t->udp_socket->bind(QHostAddress(ip),port);

            COM_NETWORK_TCPIP_LOG_PRINT("UDP server start listen");
        }


    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_stop()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_stop(cc_com_network_tcpip_server_struct *server_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,server_t->tcp_server);

        /* impletement */
        server_t->tcp_server->close();
        server_t->udp_socket->abort();

        COM_NETWORK_TCPIP_LOG_PRINT("TCP server stop listen");

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_trigger()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_trigger(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,this->cc_com_network_tcpip_server_t.qpushbutton_open);

        /* impletement */
        if (this->cc_com_network_tcpip_server_t.qpushbutton_open->text() == "侦听")
        {
            cc_com_network_tcpip_server_listen(&this->cc_com_network_tcpip_server_t);
            /* change button */
            this->cc_com_network_tcpip_server_t.qpushbutton_open->setText("停止");
        }
        else
        {
            cc_com_network_tcpip_server_stop(&this->cc_com_network_tcpip_server_t);
            /* change button */
            this->cc_com_network_tcpip_server_t.qpushbutton_open->setText("侦听");
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_tcp_recv_process()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_tcp_recv_process(cc_com_network_tcpip_rxdata_struct *rxdata_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,rxdata_t);
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        /* impletement */
        /* to string */
        TypeConvers_QByteArrayToQString(rxdata_t->rxqbytearray,&rxdata_t->rxqstring);
        /* to string hex */
        rxdata_t->rxqstringhex = rxdata_t->rxqbytearray.toHex().toUpper();
        /* to hex */
        QByteArray bytearray = QByteArray::fromHex(rxdata_t->rxqstringhex.toLatin1());
        rxdata_t->length = COM_NETWORK_TCPIP_BUFFER_SIZE;
        TypeConvers_QByteArrayToUint8(bytearray,rxdata_t->buffer,&rxdata_t->length);
        /* hex str */
        bytearray.clear();
        rxdata_t->rxqbytearrayhex = rxdata_t->rxqstringhex.toLatin1();
        for (int i = 0; i < rxdata_t->rxqbytearrayhex.size(); i++ )
        {
            bytearray.append(rxdata_t->rxqbytearrayhex.at(i));
            if (i % 2) bytearray.append(0x20);
        }
        rxdata_t->rxqstringhex = bytearray;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_display()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_display(QTextBrowser *qTextBrowser,cc_com_network_tcpip_direction_struct direction,QString content)
{
    cc_result result = CC_E_OK;
    QString prefix;
    QString color;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,qTextBrowser);
        CHECK_LOGIC(result,(content != ""));
        /* impletement */
        switch (direction)
        {
        case CC_COM_NETWORK_TCPIP_DIRECTION_NULL:
        {
            prefix = "[显示]:🚃";
            color = "black";
        }
        break;
        case CC_COM_NETWORK_TCPIP_DIRECTION_TX:
        {
            prefix = "[发送]:🚀";
            color = "red";
        }
        break;
        case CC_COM_NETWORK_TCPIP_DIRECTION_RX:
        {
            prefix = "[接收]:🐬 ";
            color = "blue";
        }
        break;
        default:
            break;
        }
        QString timeStrLine="["+QDateTime::currentDateTime().toString("hh:mm:ss")+"]" + prefix;
        QString displaycontent = "<span style=\" color:" + color + ";\">" +\
                                 timeStrLine +\
                                 content +\
                                 "</span>";
        qTextBrowser->append(displaycontent);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_tcp_recv()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_tcp_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,this->cc_com_network_tcpip_server_t.tcp_server);

        /* recv */
        for (int i = 0; i < this->cc_com_network_tcpip_server_t.clientlist.length(); ++i)
        {
            /* read buffer */
            cc_com_network_tcpip_server_rxdata_t.rxqbytearray = this->cc_com_network_tcpip_server_t.clientlist[i].socket->readAll();
            if(cc_com_network_tcpip_server_rxdata_t.rxqbytearray.isEmpty())
            {
                continue;
            }
            /* check port */

            /* process */
            cc_com_network_tcpip_server_tcp_recv_process(&cc_com_network_tcpip_server_rxdata_t);
            /* display */
            cc_com_network_tcpip_server_display(this->cc_com_network_tcpip_server_t.qtextbrower,\
                                                CC_COM_NETWORK_TCPIP_DIRECTION_RX,\
                                                (this->cc_com_network_tcpip_server_t.qcheckbox_hexrx->isChecked() ? cc_com_network_tcpip_server_rxdata_t.rxqstringhex : cc_com_network_tcpip_server_rxdata_t.rxqstring));
            /* callback */
            this->cc_com_network_tcpip_server_t.receive(CC_COM_NETWORK_TCPIP_ROLE_MASTER,&cc_com_network_tcpip_server_rxdata_t);
            /* clear */
            cc_com_network_tcpip_server_rxdata_t.rxqbytearray.clear();
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_udp_recv()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_udp_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_server_t.udp_socket->hasPendingDatagrams() == CC_TRUE));
        /* rx */
        cc_com_network_tcpip_server_rxdata_t.rxqbytearray.resize(this->cc_com_network_tcpip_server_t.udp_socket->pendingDatagramSize());
        this->cc_com_network_tcpip_server_t.udp_socket->readDatagram(cc_com_network_tcpip_server_rxdata_t.rxqbytearray.data(), cc_com_network_tcpip_server_rxdata_t.rxqbytearray.size());
        /* process */
        cc_com_network_tcpip_server_tcp_recv_process(&cc_com_network_tcpip_server_rxdata_t);
        /* insert client list */
        ____________________TO_DO____________________
        /* display */
        cc_com_network_tcpip_server_display(this->cc_com_network_tcpip_server_t.qtextbrower,\
                                            CC_COM_NETWORK_TCPIP_DIRECTION_RX,\
                                            (this->cc_com_network_tcpip_server_t.qcheckbox_hexrx->isChecked() ? cc_com_network_tcpip_server_rxdata_t.rxqstringhex : cc_com_network_tcpip_server_rxdata_t.rxqstring));
        /* callback */
        this->cc_com_network_tcpip_server_t.receive(CC_COM_NETWORK_TCPIP_ROLE_MASTER,&cc_com_network_tcpip_server_rxdata_t);
        /* clear */
        cc_com_network_tcpip_server_rxdata_t.rxqbytearray.clear();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_clienttable_append()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_clienttable_append(cc_com_network_tcpip_server_clientinfo_struct *clientinfo)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,clientinfo);

        /* impletement */
        cc_com_network_tcpip_server_cfg_clienttable_append(this->cc_com_network_tcpip_server_t.qtablewidget_client,clientinfo);

        COM_NETWORK_TCPIP_LOG_PRINT("TCP server find new client connection");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_client_disconnected_callback()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_client_disconnected_callback()
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
        CHECK_PTR(result,client);
        /* impletement */

        COM_NETWORK_TCPIP_LOG_PRINT("TCP server find client disconnection");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_client_connected_callback()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_client_connected_callback()
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
        CHECK_PTR(result,client);
        /* impletement */

        COM_NETWORK_TCPIP_LOG_PRINT("TCP server find client connection");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_client_erroroccurred_callback()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_client_erroroccurred_callback(QAbstractSocket::SocketError error)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
        CHECK_PTR(result,client);
        /* impletement */

        /* client -> server */
        COM_NETWORK_TCPIP_LOG_PRINT("TCP server find client error:%d!",error);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_newconnection()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_newconnection(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,this->cc_com_network_tcpip_server_t.tcp_server);

        /* get socket */
        QTcpSocket *qtcpsocket = this->cc_com_network_tcpip_server_t.tcp_server->nextPendingConnection();
        QString ip = qtcpsocket->peerAddress().toString().mid(7);
        QString port = QString::number(qtcpsocket->peerPort());
        /* add */
        cc_com_network_tcpip_server_clientinfo_struct clientinfo;
        clientinfo.ip = ip;
        clientinfo.port = port;
        clientinfo.socket = qtcpsocket;
        this->cc_com_network_tcpip_server_t.clientlist.append(clientinfo);
        /* add view */
        cc_com_network_tcpip_server_clienttable_append(&clientinfo);
        /* TCP connect */
        connect(qtcpsocket,\
                &QTcpSocket::connected,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_client_connected_callback);
        connect(qtcpsocket,\
                &QTcpSocket::errorOccurred,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_client_erroroccurred_callback);
        connect(qtcpsocket,\
                &QTcpSocket::readyRead,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_tcp_recv);
        connect(qtcpsocket,\
                &QTcpSocket::disconnected,\
                this,\
                &Com_Network::cc_com_network_tcpip_server_client_disconnected_callback);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_transmit_process()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_transmit_process(QByteArray *qbytearray,QString *displaymsg,QString content,cc_com_network_tcpip_mode_struct mode)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,qbytearray);
        CHECK_PTR(result,displaymsg);
        CHECK_LOGIC(result,(content != ""));
        /* convert */
        switch(mode)
        {
        case CC_COM_NETWORK_TCPIP_MODE_HEX:
        {
            /* clear ' ' */
            content.remove(QRegularExpression("\\s"));
            /* format */
            QByteArray tmp = QByteArray::fromHex(content.toLatin1());
            for (int i = 0; i < tmp.size(); i++)
            {
                qbytearray->append(tmp.at(i));
                if (i % 2)
                {
                    qbytearray->append(0x20);
                }
            }
            *displaymsg = content.toUpper().replace(QRegularExpression("(.{2})"), "\\1 ").trimmed();
        }
        break;
        case CC_COM_NETWORK_TCPIP_MODE_ASCII:
        {
            *qbytearray = content.toLatin1();
            *displaymsg = content;
        }
        break;
        default:
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_client_match()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_client_match(cc_com_network_tcpip_server_clientinfo_struct **client,QString ip,QString port)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,client);
        CHECK_LOGIC(result,(ip != ""));
        CHECK_LOGIC(result,(port != ""));
        /* impletement */
        for (int i = 0; i < this->cc_com_network_tcpip_server_t.clientlist.length(); ++i)
        {
            if((this->cc_com_network_tcpip_server_t.clientlist[i].ip == ip) && \
               (this->cc_com_network_tcpip_server_t.clientlist[i].port == port))
            {
                *client = &this->cc_com_network_tcpip_server_t.clientlist[i];
                result = CC_E_OK;
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_write_tcp()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_write_tcp(QTcpSocket *tcp_socket,QByteArray qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,tcp_socket);
        /* impletement */
        CHECK_LOGIC(result,(tcp_socket->isOpen() == CC_TRUE));
        CHECK_LOGIC(result,(tcp_socket->isWritable() == CC_TRUE));
        tcp_socket->write(qbytearray);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_write_udp()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_write_udp(QUdpSocket *udp_socket,QString ip,QString port,QByteArray qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_PTR(result,udp_socket);
        /* impletement */
        udp_socket->writeDatagram(qbytearray,QHostAddress(ip),port.toInt());
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_write()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_write(QString type,QByteArray qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_server_t.clientlist.length() > 0));
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_server_t.qtablewidget_client->rowCount() > 0));
        /* impletement */
        /* target */
        if(this->ui->comboBox_com_view_operate_sendmode->currentText() == "单播发送")
        {
            /* get current client */
            int row = this->cc_com_network_tcpip_server_t.qtablewidget_client->currentRow();
            CHECK_LOGIC(result,(row >= 0));
            QString ip = this->cc_com_network_tcpip_server_t.qtablewidget_client->item(row,CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_IP)->text();
            QString port = this->cc_com_network_tcpip_server_t.qtablewidget_client->item(row,CC_COM_NETWORK_TCPIP_SERVER_CLIENTINFO_INDEX_PORT)->text();
            if(type == "TCP")
            {
                /* get socket */
                cc_com_network_tcpip_server_clientinfo_struct *client;
                CHECK_FUNC(result,cc_com_network_tcpip_server_client_match(&client,ip,port));
                /* send */
                cc_com_network_tcpip_server_write_tcp(client->socket,qbytearray);
            }
            else if(type == "UDP")
            {
                /* send */
                CHECK_PTR(result,this->cc_com_network_tcpip_server_t.udp_socket);
                cc_com_network_tcpip_server_write_udp(this->cc_com_network_tcpip_server_t.udp_socket,ip,port,qbytearray);
            }
            else
            {

            }
        }
        else if(this->ui->comboBox_com_view_operate_sendmode->currentText() == "广播发送")
        {
            if(type == "TCP")
            {
                /* foreach client */
                for (int i = 0; i < this->cc_com_network_tcpip_server_t.clientlist.length(); ++i)
                {
                    /* send */
                    cc_com_network_tcpip_server_write_tcp(this->cc_com_network_tcpip_server_t.clientlist[i].socket,qbytearray);
                }
            }
            else if(type == "UDP")
            {
                CHECK_PTR(result,this->cc_com_network_tcpip_server_t.udp_socket);
                this->cc_com_network_tcpip_server_t.udp_socket->writeDatagram(qbytearray,QHostAddress::Broadcast,CC_NULL);
            }
            else
            {

            }
        }
        else
        {

        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_transmit()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_server_transmit(cc_void)
{
    cc_result result = CC_E_OK;
    QByteArray qbytearray;
    QString displaymsg;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_server_initflag == CC_TRUE));
        QString content = this->cc_com_network_tcpip_server_t.qlineedit_send->text();
        CHECK_LOGIC(result,(content != ""));
        /* convert */
        cc_com_network_tcpip_mode_struct mode = (this->cc_com_network_tcpip_server_t.qcheckbox_hextx->isChecked()) ? (CC_COM_NETWORK_TCPIP_MODE_HEX) : (CC_COM_NETWORK_TCPIP_MODE_ASCII) ;
        cc_com_network_tcpip_server_transmit_process(&qbytearray,&displaymsg,content,mode);
        /* send */
        cc_com_network_tcpip_server_write(this->cc_com_network_tcpip_server_t.comboBox_type->currentText(),qbytearray);
        /* display */
        cc_com_network_tcpip_server_display(this->cc_com_network_tcpip_server_t.qtextbrower,CC_COM_NETWORK_TCPIP_DIRECTION_TX,displaymsg);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_server_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_tcpip_server_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_network_tcpip_server.c End!
****************************************************************************************************/

