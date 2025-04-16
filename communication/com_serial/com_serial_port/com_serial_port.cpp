
/****************************************************************************************************
* File com_serial_port.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "com_serial_port.h"
#include "com_serial_port_cfg.h"
#include "com_serial.h"
#include "timer.h"
#include "typeconvers.h"
/* cpp */
#include "qcombobox.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QRegularExpression>
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

/* com_serial_port */
cc_com_serial_port_struct cc_com_serial_port_t;
/* init flag */
cc_boolean cc_com_serial_port_initflag = CC_FALSE;
/* init cfg */
cc_com_serial_struct *cc_com_serial_init_t = nullptr;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_serial_port_init()
****************************************************************************************************/
cc_result cc_com_serial_port_init(cc_com_serial_struct *com_serial_t)
{
    cc_result result = CC_E_OK;
    com_serial_port_cfg_struct *port_cfg;

    do
    {
        /* check */
        CHECK_PTR(result,com_serial_t);
        CHECK_PTR(result,com_serial_t->serialport);
        CHECK_PTR(result,com_serial_t->qpushbutton_open);
        CHECK_PTR(result,com_serial_t->comboBox_port);
        CHECK_PTR(result,com_serial_t->comboBox_baud);
        CHECK_PTR(result,com_serial_t->comboBox_data);
        CHECK_PTR(result,com_serial_t->comboBox_veriy);
        CHECK_PTR(result,com_serial_t->comboBox_stop);
        CHECK_PTR(result,com_serial_t->qTextBrowser);
        CHECK_PTR(result,com_serial_t->qCheckBox_view);
        CHECK_PTR(result,com_serial_t->buffer);
        CHECK_PTR(result,com_serial_t->receive);

        /* store cfg */
        cc_com_serial_init_t = com_serial_t;
        cc_com_serial_port_t.qtextbrower = com_serial_t->qTextBrowser;
        /* get cfg */
        CHECK_FUNC(result,com_serial_port_cfg_getcfg(&port_cfg));
        /* port */
        cc_com_serial_port_push(com_serial_t->comboBox_port);
        /* baud */
        for (cc_uint32 baudrateidx = 0; baudrateidx < COM_SERIAL_PORT_CFG_BAUDRATE_MAP_NUM; ++baudrateidx)
        {
            com_serial_t->comboBox_baud->addItem(port_cfg->baudrate_map[baudrateidx].name);
        }
        com_serial_t->comboBox_baud->setCurrentText("115200");
        /* data */
        for (cc_uint32 databitsidx = 0; databitsidx < COM_SERIAL_PORT_CFG_DATABITS_MAP_NUM; ++databitsidx)
        {
            com_serial_t->comboBox_data->addItem(port_cfg->databits_map[databitsidx].name);
        }
        com_serial_t->comboBox_data->setCurrentText("8位");
        /* verify */
        for (cc_uint32 parityidx = 0; parityidx < COM_SERIAL_PORT_CFG_PARITY_MAP_NUM; ++parityidx)
        {
            com_serial_t->comboBox_veriy->addItem(port_cfg->parity_map[parityidx].name);
        }
        com_serial_t->comboBox_veriy->setCurrentText("无校验");
        /* stop */
        for (cc_uint32 stopbitsidx = 0; stopbitsidx < COM_SERIAL_PORT_CFG_STOPBITS_MAP_NUM; ++stopbitsidx)
        {
            com_serial_t->comboBox_stop->addItem(port_cfg->stopbits_map[stopbitsidx].name);
        }
        com_serial_t->comboBox_stop->setCurrentText("1位");
        /* FlowControl */
        /* todo */

        cc_com_serial_port_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_find()
****************************************************************************************************/
cc_result com_serial_port_find(QComboBox *qComboBox,QString name)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,qComboBox);

        /* find */
        for(int idx=0; idx<qComboBox->count(); idx++)
        {
            if(qComboBox->itemText(idx) == name)
            {
                result = CC_E_OK;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_push()
****************************************************************************************************/
cc_result cc_com_serial_port_push(QComboBox *qComboBox)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,qComboBox);

        /* add port */
        qComboBox->clear();
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            /* find */
            if (com_serial_port_find(qComboBox,info.portName()) == CC_E_OK)
            {
                continue;
            }
            /* add */
            qComboBox->addItem(info.portName() + " | " + info.description());
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_open()
****************************************************************************************************/
cc_result Com_Serial::com_serial_port_open(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,serialPort);
        CHECK_PTR(result,com_serial_t);
        CHECK_PTR(result,com_serial_t->qpushbutton_open);
        CHECK_PTR(result,com_serial_t->comboBox_port);
        CHECK_PTR(result,com_serial_t->comboBox_baud);
        CHECK_PTR(result,com_serial_t->comboBox_data);
        CHECK_PTR(result,com_serial_t->comboBox_veriy);
        CHECK_PTR(result,com_serial_t->comboBox_stop);

        /* open port */
        /* name */
        QStringList list = com_serial_t->comboBox_port->currentText().split(" | ");
        QString name = list.first();
        serialPort->setPortName(name);
        /* open */
        CHECK_LOGIC(result,(serialPort->open(QIODevice::ReadWrite) == true));
        /* baud */
        QSerialPort::BaudRate baudrate = QSerialPort::Baud9600;
        com_serial_port_cfg_get_baudrate(&baudrate,com_serial_t->comboBox_baud->currentText());
        serialPort->setBaudRate(baudrate);
        /* data */
        QSerialPort::DataBits databits = QSerialPort::Data8;
        com_serial_port_cfg_get_databits(&databits,com_serial_t->comboBox_data->currentText());
        serialPort->setDataBits(databits);
        /* verify */
        QSerialPort::Parity parity = QSerialPort::NoParity;
        com_serial_port_cfg_get_parity(&parity,com_serial_t->comboBox_veriy->currentText());
        serialPort->setParity(parity);
        /* stop */
        QSerialPort::StopBits stopbites = QSerialPort::OneStop;
        com_serial_port_cfg_get_stopbits(&stopbites,com_serial_t->comboBox_veriy->currentText());
        serialPort->setStopBits(stopbites);
        /* FlowControl */
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
        /* connect receive */
        connect(serialPort, &QSerialPort::readyRead,this, cc_com_serial_port_data_read);
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_close()
****************************************************************************************************/
cc_result Com_Serial::com_serial_port_close(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,serialPort);
        CHECK_PTR(result,com_serial_t);
        CHECK_PTR(result,com_serial_t->qpushbutton_open);
        CHECK_PTR(result,com_serial_t->comboBox_port);
        CHECK_PTR(result,com_serial_t->comboBox_baud);
        CHECK_PTR(result,com_serial_t->comboBox_data);
        CHECK_PTR(result,com_serial_t->comboBox_veriy);
        CHECK_PTR(result,com_serial_t->comboBox_stop);

        /* close */
        serialPort->clear();
        serialPort->close();

    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_trigger()
****************************************************************************************************/
cc_result Com_Serial::com_serial_port_trigger(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,serialPort);
        CHECK_PTR(result,com_serial_t);
        CHECK_PTR(result,com_serial_t->qpushbutton_open);
        CHECK_PTR(result,com_serial_t->comboBox_port);
        CHECK_PTR(result,com_serial_t->comboBox_baud);
        CHECK_PTR(result,com_serial_t->comboBox_data);
        CHECK_PTR(result,com_serial_t->comboBox_veriy);
        CHECK_PTR(result,com_serial_t->comboBox_stop);
        /* impletement */
        com_serial_t->rxqbytearray.clear();
        /* open / close */
        if (com_serial_t->qpushbutton_open->text() == "打开串口")
        {
            /* open */
            com_serial_port_open(serialPort,com_serial_t);
            /* change button */
            com_serial_t->qpushbutton_open->setText("关闭串口");
        }
        else
        {
            /* close */
            com_serial_port_close(serialPort,com_serial_t);
            /* change button */
            com_serial_t->qpushbutton_open->setText("打开串口");
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_data_read()
****************************************************************************************************/
cc_result cc_com_serial_port_data_read(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,cc_com_serial_init_t);
        CHECK_PTR(result,cc_com_serial_init_t->serialport);
        /* read */
        cc_com_serial_init_t->rxqbytearray += cc_com_serial_init_t->serialport->readAll();
        /* set flag */
        cc_timer_getlocaltime_ms(&cc_com_serial_init_t->time);
        /* get time */
        cc_com_serial_init_t->rxflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_data_receive_process()
****************************************************************************************************/
cc_result cc_com_serial_port_data_receive_process(cc_com_serial_struct *serial_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,serial_t);
        CHECK_PTR(result,serial_t->buffer);

        /* to string */
        TypeConvers_QByteArrayToQString(serial_t->rxqbytearray,&serial_t->rxqstring);
        /* to string hex */
        serial_t->rxqstringhex = serial_t->rxqbytearray.toHex().toUpper();
        /* to hex */
        QByteArray bytearray = QByteArray::fromHex(serial_t->rxqstringhex.toLatin1());
        serial_t->length = COM_SERIAL_BUFFER_SIZE;
        TypeConvers_QByteArrayToUint8(bytearray,serial_t->buffer,&serial_t->length);
        /* hex str */
        bytearray.clear();
        serial_t->rxqbytearrayhex = serial_t->rxqstringhex.toLatin1();
        for (int i = 0; i < serial_t->rxqbytearrayhex.size(); i++ )
        {
            bytearray.append(serial_t->rxqbytearrayhex.at(i));
            if (i % 2) bytearray.append(0x20);
        }
        serial_t->rxqstringhex = bytearray;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_display()
****************************************************************************************************/
cc_result cc_com_serial_port_display(QTextBrowser *qTextBrowser,cc_com_serial_port_direction_struct direction,QString content)
{
    cc_result result = CC_E_OK;
    QString prefix;
    QString color;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,qTextBrowser);
        CHECK_LOGIC(result,(content != ""));
        /* impletement */
        switch (direction)
        {
        case CC_COM_SERIAL_PORT_DIRECTION_NULL:
            {
                prefix = "[显示]:🚃";
                color = "black";
            }
            break;
        case CC_COM_SERIAL_PORT_DIRECTION_TX:
            {
                prefix = "[发送]:🚀";
                color = "red";
            }
            break;
        case CC_COM_SERIAL_PORT_DIRECTION_RX:
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
* cc_com_serial_port_data_receive()
****************************************************************************************************/
cc_result cc_com_serial_port_data_receive(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,cc_com_serial_init_t);
        CHECK_PTR(result,cc_com_serial_init_t->buffer);
        CHECK_PTR(result,cc_com_serial_init_t->receive);

        /* rxflag */
        CHECK_LOGIC(result,(cc_com_serial_init_t->rxflag == CC_TRUE));
        /* timeout || '\n' */
        CHECK_LOGIC(result,((cc_timer_checktimeout_ms(&cc_com_serial_init_t->time,cc_com_serial_init_t->timeout) == CC_E_OK) ||\
                            (cc_com_serial_init_t->rxqbytearray.contains('\n') == true)));

        /* receive */
        cc_com_serial_init_t->rxflag = CC_FALSE;

        /* to convert receives data */
        cc_com_serial_port_data_receive_process(cc_com_serial_init_t);

        /* display */
        cc_com_serial_port_display(cc_com_serial_init_t->qTextBrowser,\
                                   CC_COM_SERIAL_PORT_DIRECTION_RX,\
                                   (cc_com_serial_init_t->qCheckBox_view->isChecked() ? cc_com_serial_init_t->rxqstringhex : cc_com_serial_init_t->rxqstring));

        /* callback */
        cc_com_serial_init_t->receive(cc_com_serial_init_t);

        /* clear */
        cc_com_serial_init_t->rxqbytearray.clear();
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_send_process()
****************************************************************************************************/
cc_result cc_com_serial_port_send_process(QByteArray *qbytearray,QString *displaymsg,QString content,cc_com_serial_port_mode_struct mode)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,qbytearray);
        CHECK_PTR(result,displaymsg);
        CHECK_LOGIC(result,(content != ""));
        /* convert */
        switch(mode)
        {
        case CC_COM_SERIAL_PORT_MODE_HEX:
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
        case CC_COM_SERIAL_PORT_MODE_ASCII:
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
* cc_com_serial_port_write()
****************************************************************************************************/
cc_result cc_com_serial_port_write(QSerialPort *serialPort,QByteArray qbytearray)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,serialPort);
        CHECK_LOGIC(result,(serialPort->isOpen() == CC_TRUE));
        CHECK_LOGIC(result,(serialPort->isWritable() == CC_TRUE));
        /* send */
        serialPort->write(qbytearray);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_send()
****************************************************************************************************/
cc_result cc_com_serial_port_send(QSerialPort *serialPort,QString content,cc_com_serial_port_mode_struct mode)
{
    cc_result result = CC_E_OK;
    QByteArray qbytearray;
    QString displaymsg;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_com_serial_port_initflag == CC_TRUE));
        CHECK_PTR(result,serialPort);
        CHECK_LOGIC(result,(content != ""));
        /* convert */
        cc_com_serial_port_send_process(&qbytearray,&displaymsg,content,mode);
        /* send */
        cc_com_serial_port_write(serialPort,qbytearray);
        /* display */
        cc_com_serial_port_display(cc_com_serial_init_t->qTextBrowser,CC_COM_SERIAL_PORT_DIRECTION_TX,displaymsg);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_mainfunction()
****************************************************************************************************/
cc_result cc_com_serial_port_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* 1ms task */
        cc_com_serial_port_data_receive();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_serial_port.c End!
****************************************************************************************************/

