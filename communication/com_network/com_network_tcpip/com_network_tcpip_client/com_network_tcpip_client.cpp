
/****************************************************************************************************
* File com_network_tcpip_client.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network.h"
#include "com_network_tcpip_client.h"
/* log */
/* sub module */
/* components */
#include "typeconvers.h"

/* ui */
/* cpp */
#include <QNetworkInterface>
#include <QNetworkProxy>
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

/* cc_com_network_tcpip_client_struct */
cc_com_network_tcpip_client_struct cc_com_network_tcpip_client_t;
/* init flag */
cc_boolean cc_com_network_tcpip_client_initflag = CC_FALSE;
/* rx buffer */
cc_com_network_tcpip_rxdata_struct cc_com_network_tcpip_client_rxdata_t;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_network_tcpip_client_init()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_init(cc_com_network_tcpip_client_struct *cfg)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg);
        CHECK_PTR(result,cfg->tcp_socket);
        CHECK_PTR(result,cfg->udp_socket);
        CHECK_PTR(result,cfg->qpushbutton_open);
        CHECK_PTR(result,cfg->qcomboBox_ip);
        CHECK_PTR(result,cfg->qlineedit_port);
        CHECK_PTR(result,cfg->comboBox_type);
        CHECK_PTR(result,cfg->qcheckbox_hexrx);
        CHECK_PTR(result,cfg->qcheckbox_hextx);
        CHECK_PTR(result,cfg->qlineedit_send);
        CHECK_PTR(result,cfg->receive);

        /* impletement */
        COM_NETWORK_TCPIP_LOG_PRINT("tcpip client init start");
        /* input */
        this->cc_com_network_tcpip_client_t.tcp_socket = cfg->tcp_socket;
        this->cc_com_network_tcpip_client_t.udp_socket = cfg->udp_socket;
        this->cc_com_network_tcpip_client_t.qpushbutton_open = cfg->qpushbutton_open;
        this->cc_com_network_tcpip_client_t.qcomboBox_ip = cfg->qcomboBox_ip;
        this->cc_com_network_tcpip_client_t.qlineedit_port = cfg->qlineedit_port;
        this->cc_com_network_tcpip_client_t.comboBox_type = cfg->comboBox_type;
        this->cc_com_network_tcpip_client_t.qcheckbox_hexrx = cfg->qcheckbox_hexrx;
        this->cc_com_network_tcpip_client_t.qcheckbox_hextx = cfg->qcheckbox_hextx;
        this->cc_com_network_tcpip_client_t.qlineedit_send = cfg->qlineedit_send;
        this->cc_com_network_tcpip_client_t.qtextbrower = cfg->qtextbrower;
        this->cc_com_network_tcpip_client_t.receive = cfg->receive;

        /* init ip */
        cc_com_network_tcpip_client_init_ip(this->cc_com_network_tcpip_client_t.qcomboBox_ip);
        /* init type */
        this->cc_com_network_tcpip_client_t.comboBox_type->addItem("TCP");
        this->cc_com_network_tcpip_client_t.comboBox_type->addItem("UDP");
        /* init proxy */
        QNetworkProxy proxy;
        proxy.setType(QNetworkProxy::NoProxy);
        this->cc_com_network_tcpip_client_t.tcp_socket->setProxy(proxy);

        /* connect */
        connect(this->cc_com_network_tcpip_client_t.tcp_socket,\
                &QTcpSocket::connected,\
                this,\
                &Com_Network::cc_com_network_tcpip_client_connected);
        connect(this->cc_com_network_tcpip_client_t.tcp_socket,\
                &QTcpSocket::disconnected,\
                this,\
                &Com_Network::cc_com_network_tcpip_client_disconnected);
        connect(this->cc_com_network_tcpip_client_t.tcp_socket,\
                &QTcpSocket::errorOccurred,\
                this,\
                &Com_Network::cc_com_network_tcpip_client_erroroccurred);
        connect(this->cc_com_network_tcpip_client_t.tcp_socket,\
                &QTcpSocket::readyRead,\
                this,\
                &Com_Network::cc_com_network_tcpip_client_tcp_recv);
        connect(this->cc_com_network_tcpip_client_t.udp_socket,\
                &QUdpSocket::readyRead,\
                this,\
                &Com_Network::cc_com_network_tcpip_client_udp_recv);
        COM_NETWORK_TCPIP_LOG_PRINT("tcpip client init complete");
        cc_com_network_tcpip_client_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_init_ip()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_init_ip(QComboBox *comboBox_ip)
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
* cc_com_network_tcpip_client_connect()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_connect(cc_com_network_tcpip_client_struct *client_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,client_t->qcomboBox_ip);
        CHECK_PTR(result,client_t->qlineedit_port);
        CHECK_PTR(result,client_t->comboBox_type);

        /* get ip */
        QString ip = client_t->qcomboBox_ip->currentText();
        /* get port */
        cc_uint16 port = client_t->qlineedit_port->text().toUInt();
        /* get type */
        if(client_t->comboBox_type->currentText() == "TCP")
        {
            /* TCP */
            /* impletement */
            client_t->tcp_socket->connectToHost(ip,port);
            if(!client_t->tcp_socket->waitForConnected(3000))
            {
                COM_NETWORK_TCPIP_LOG_PRINT("TCP client connect fail");
                result = CC_E_NOT_OK;
                continue;
            }
            COM_NETWORK_TCPIP_LOG_PRINT("TCP client connect");
        }
        else
        {
            /* UDP */
            /* impletement */
            client_t->udp_socket->bind(QHostAddress::Any,CC_NULL);
            COM_NETWORK_TCPIP_LOG_PRINT("UDP client connect");
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_disconnect()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_disconnect(cc_com_network_tcpip_client_struct *client_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,client_t->comboBox_type);

        /* get type */
        if(client_t->comboBox_type->currentText() == "TCP")
        {
            /* TCP */
            /* impletement */
            client_t->tcp_socket->disconnectFromHost();
            COM_NETWORK_TCPIP_LOG_PRINT("TCP client disconnect");
        }
        else
        {
            /* UDP */
            /* impletement */
            COM_NETWORK_TCPIP_LOG_PRINT("UDP client disconnect");
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_trigger()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_trigger(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,this->cc_com_network_tcpip_client_t.qpushbutton_open);

        /* impletement */
        if (this->cc_com_network_tcpip_client_t.qpushbutton_open->text() == "连接")
        {
            cc_com_network_tcpip_client_connect(&this->cc_com_network_tcpip_client_t);
            /* change button */
            this->cc_com_network_tcpip_client_t.qpushbutton_open->setText("断开");
        }
        else
        {
            cc_com_network_tcpip_client_disconnect(&this->cc_com_network_tcpip_client_t);
            /* change button */
            this->cc_com_network_tcpip_client_t.qpushbutton_open->setText("连接");
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_connected()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_connected(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* client -> server */
        COM_NETWORK_TCPIP_LOG_PRINT("TCP client connect successful!");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_disconnected()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_disconnected(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* client -> server */
        COM_NETWORK_TCPIP_LOG_PRINT("TCP client disconnect successful!");
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_erroroccurred()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_erroroccurred(QAbstractSocket::SocketError error)
{
    cc_result result = CC_E_OK;

    do
    {
        /* client -> server */
        COM_NETWORK_TCPIP_LOG_PRINT("TCP client error:%d!",error);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_tcp_recv_process()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_tcp_recv_process(cc_com_network_tcpip_rxdata_struct *rxdata_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,rxdata_t);
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
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
* cc_com_network_tcpip_client_display()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_display(QTextBrowser *qTextBrowser,cc_com_network_tcpip_direction_struct direction,QString content)
{
    cc_result result = CC_E_OK;
    QString prefix;
    QString color;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
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
            prefix = "[接收]:🐬";
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
* cc_com_network_tcpip_client_tcp_recv()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_tcp_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_client_t.tcp_socket->isOpen() == CC_TRUE));
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_client_t.tcp_socket->isReadable() == CC_TRUE));
        /* rx */
        cc_com_network_tcpip_client_rxdata_t.rxqbytearray = this->cc_com_network_tcpip_client_t.tcp_socket->readAll();
        /* process */
        cc_com_network_tcpip_client_tcp_recv_process(&cc_com_network_tcpip_client_rxdata_t);
        /* display */
        cc_com_network_tcpip_client_display(this->cc_com_network_tcpip_client_t.qtextbrower,\
                                            CC_COM_NETWORK_TCPIP_DIRECTION_RX,\
                                            (this->cc_com_network_tcpip_client_t.qcheckbox_hexrx->isChecked() ? cc_com_network_tcpip_client_rxdata_t.rxqstringhex : cc_com_network_tcpip_client_rxdata_t.rxqstring));
        /* callback */
        this->cc_com_network_tcpip_client_t.receive(CC_COM_NETWORK_TCPIP_ROLE_CLIENT,&cc_com_network_tcpip_client_rxdata_t);
        /* clear */
        cc_com_network_tcpip_client_rxdata_t.rxqbytearray.clear();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_udp_recv()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_udp_recv(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(this->cc_com_network_tcpip_client_t.udp_socket->hasPendingDatagrams() == CC_TRUE));
        /* rx */
        cc_com_network_tcpip_client_rxdata_t.rxqbytearray.resize(this->cc_com_network_tcpip_client_t.udp_socket->pendingDatagramSize());
        this->cc_com_network_tcpip_client_t.udp_socket->readDatagram(cc_com_network_tcpip_client_rxdata_t.rxqbytearray.data(), cc_com_network_tcpip_client_rxdata_t.rxqbytearray.size());
        /* process */
        cc_com_network_tcpip_client_tcp_recv_process(&cc_com_network_tcpip_client_rxdata_t);
        /* display */
        cc_com_network_tcpip_client_display(this->cc_com_network_tcpip_client_t.qtextbrower,\
                                            CC_COM_NETWORK_TCPIP_DIRECTION_RX,\
                                            (this->cc_com_network_tcpip_client_t.qcheckbox_hexrx->isChecked() ? cc_com_network_tcpip_client_rxdata_t.rxqstringhex : cc_com_network_tcpip_client_rxdata_t.rxqstring));
        /* callback */
        this->cc_com_network_tcpip_client_t.receive(CC_COM_NETWORK_TCPIP_ROLE_CLIENT,&cc_com_network_tcpip_client_rxdata_t);
        /* clear */
        cc_com_network_tcpip_client_rxdata_t.rxqbytearray.clear();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_transmit_process()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_transmit_process(QByteArray *qbytearray,QString *displaymsg,QString content,cc_com_network_tcpip_mode_struct mode)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
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
* cc_com_network_tcpip_client_write_tcp()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_write_tcp(QTcpSocket *tcp_socket,QByteArray *qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,tcp_socket);
        CHECK_PTR(result,qbytearray);
        /* impletement */
        CHECK_LOGIC(result,(tcp_socket->isOpen() == CC_TRUE));
        CHECK_LOGIC(result,(tcp_socket->isWritable() == CC_TRUE));
        tcp_socket->write(*qbytearray);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_write_udp()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_write_udp(QUdpSocket *udp_socket,QString ip,QString port,QByteArray *qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,udp_socket);
        CHECK_PTR(result,qbytearray);
        /* impletement */
        udp_socket->writeDatagram(*qbytearray,QHostAddress(ip),port.toInt());
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_write()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_write(QString type,QByteArray *qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        CHECK_PTR(result,qbytearray);
        /* impletement */
        if(type == "TCP")
        {
            cc_com_network_tcpip_client_write_tcp(this->cc_com_network_tcpip_client_t.tcp_socket,qbytearray);
        }
        else if(type == "UDP")
        {
            cc_com_network_tcpip_client_write_udp(this->cc_com_network_tcpip_client_t.udp_socket,\
                                                  this->cc_com_network_tcpip_client_t.qcomboBox_ip->currentText(),\
                                                  this->cc_com_network_tcpip_client_t.qlineedit_port->text(),\
                                                  qbytearray);
        }
        else
        {

        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_transmit()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_client_transmit(cc_void)
{
    cc_result result = CC_E_OK;
    QByteArray qbytearray;
    QString displaymsg;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_network_tcpip_client_initflag == CC_TRUE));
        QString content = this->cc_com_network_tcpip_client_t.qlineedit_send->text();
        CHECK_LOGIC(result,(content != ""));
        /* convert */
        cc_com_network_tcpip_mode_struct mode = (this->cc_com_network_tcpip_client_t.qcheckbox_hextx->isChecked()) ? (CC_COM_NETWORK_TCPIP_MODE_HEX) : (CC_COM_NETWORK_TCPIP_MODE_ASCII) ;
        cc_com_network_tcpip_client_transmit_process(&qbytearray,&displaymsg,content,mode);
        /* send */
        cc_com_network_tcpip_client_write(this->cc_com_network_tcpip_client_t.comboBox_type->currentText(),&qbytearray);
        /* display */
        cc_com_network_tcpip_client_display(this->cc_com_network_tcpip_client_t.qtextbrower,CC_COM_NETWORK_TCPIP_DIRECTION_TX,displaymsg);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_client_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_tcpip_client_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_network_tcpip_client.c End!
****************************************************************************************************/

