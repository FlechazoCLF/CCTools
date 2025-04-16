
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_serial.h"
/* sub module */
#include "com_serial_port.h"
#include "com_serial_port_cfg.h"

/* ui */
#include "ui_com_serial.h"
/* cpp */
#include "timer.h"

/****************************************************************************************************
* Com_Serial()
****************************************************************************************************/
Com_Serial::Com_Serial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Com_Serial)
{
    ui->setupUi(this);

    /* init */
    com_serial_init();
}

Com_Serial::~Com_Serial()
{
    delete ui;
}

/****************************************************************************************************
* com_serial_init()
****************************************************************************************************/
cc_result Com_Serial::com_serial_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,true);

        /* init */
        this->serialPort = new QSerialPort();
        /* port */
        this->com_serial_t.serialport = serialPort;
        /* ui */
        this->com_serial_t.qpushbutton_open = this->ui->pushButton_operate;
        this->com_serial_t.comboBox_port = this->ui->comboBox_config_port;
        this->com_serial_t.comboBox_baud = this->ui->comboBox_config_baud;
        this->com_serial_t.comboBox_data = this->ui->comboBox_config_data;
        this->com_serial_t.comboBox_veriy = this->ui->comboBox_config_veriy;
        this->com_serial_t.comboBox_stop = this->ui->comboBox_config_stop;
        this->com_serial_t.qTextBrowser = this->ui->textBrowser_com_view;
        this->com_serial_t.qCheckBox_view = this->ui->checkBox_com_view_config_hexrecv;
        /* receive */
        this->com_serial_t.rxflag = false;
        this->com_serial_t.rxqbytearray.clear();
        memset(this->com_serial_t.buffer,0,COM_SERIAL_BUFFER_SIZE);
        cc_timer_getlocaltime_ms(&this->com_serial_t.time);
        this->com_serial_t.timeout = 25;
        this->com_serial_t.receive = com_serial_receive;

        /* port */
        cc_com_serial_port_init(&this->com_serial_t);

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_operate_clicked()
****************************************************************************************************/
cc_result com_serial_receive(cc_com_serial_struct *com_serial_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,com_serial_t->qTextBrowser);
        CHECK_PTR(result,com_serial_t->buffer);
        CHECK_LOGIC(result,(com_serial_t->length != 0));
        /* user code */

    }while(0u);

    return result;
}

/****************************************************************************************************
* on_pushButton_operate_clicked()
****************************************************************************************************/
void Com_Serial::on_pushButton_operate_clicked()
{
    com_serial_port_trigger(this->serialPort,&this->com_serial_t);
}

/****************************************************************************************************
* on_pushButton_com_view_config_send_clicked()
****************************************************************************************************/
void Com_Serial::on_pushButton_com_view_config_send_clicked()
{
    QString content = this->ui->lineEdit_com_view_config_senddata->text();
    cc_com_serial_port_mode_struct mode = (this->ui->checkBox_com_view_config_hexsend->isChecked() == CC_TRUE) ? (CC_COM_SERIAL_PORT_MODE_HEX) : (CC_COM_SERIAL_PORT_MODE_ASCII) ;
    cc_com_serial_port_send(this->serialPort,content,mode);
}

/****************************************************************************************************
* cc_com_serial_mainfunction()
****************************************************************************************************/
cc_result cc_com_serial_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_com_serial_port_mainfunction();
        cc_com_serial_port_cfg_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
