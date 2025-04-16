
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef COM_SERIAL_H
#define COM_SERIAL_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include <QWidget>
#include "qcheckbox.h"
#include "qcombobox.h"
#include "qpushbutton.h"
#include <QTextBrowser>
/* cpp */
#include "qserialport.h"

/****************************************************************************************************
* Define
****************************************************************************************************/
#define COM_SERIAL_BUFFER_SIZE (2048u)
/* debug */
#define COM_SERIAL_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,com_serial_t.qTextBrowser,format,##__VA_ARGS__)

/****************************************************************************************************
* Type Define
****************************************************************************************************/
namespace Ui {
class Com_Serial;
}

/* serial */
typedef struct cc_com_serial_struct_T
{
    /* port */
    QSerialPort *serialport;

    /* ui */
    QPushButton *qpushbutton_open;
    QComboBox *comboBox_port;
    QComboBox *comboBox_baud;
    QComboBox *comboBox_data;
    QComboBox *comboBox_veriy;
    QComboBox *comboBox_stop;
    QTextBrowser *qTextBrowser;
    QCheckBox *qCheckBox_view;

    /* data origin */
    cc_boolean rxflag;
    QByteArray rxqbytearray;
    /* to str */
    QString rxqstring;
    /* hex */
    QString rxqstringhex;
    QByteArray rxqbytearrayhex;
    cc_uint16 length;
    cc_uint8 buffer[COM_SERIAL_BUFFER_SIZE];

    /* callback */
    cc_uint32 time;
    cc_uint32 timeout;
    cc_result (*receive)(struct cc_com_serial_struct_T *com_serial_t);
}cc_com_serial_struct;

/* list */
typedef struct
{
    cc_com_serial_struct *serial;
    ____________________TO_DO____________________
}cc_com_serial_list_struct;

class Com_Serial : public QWidget
{
    Q_OBJECT

public:
    explicit Com_Serial(QWidget *parent = nullptr);
    ~Com_Serial();

private slots:
    void on_pushButton_operate_clicked();

    void on_pushButton_com_view_config_send_clicked();

private:
    Ui::Com_Serial *ui;
    QSerialPort *serialPort;
    cc_com_serial_struct com_serial_t;
    /* init */
    cc_result com_serial_init(cc_void);
    /* port init */
    cc_result com_serial_port_trigger(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t);
    cc_result com_serial_port_open(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t);
    cc_result com_serial_port_close(QSerialPort *serialPort,cc_com_serial_struct *com_serial_t);

};

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
/* receive */
cc_result com_serial_receive(cc_com_serial_struct *com_serial_t);
cc_result cc_com_serial_mainfunction(cc_void);

#endif // COM_SERIAL_H
/****************************************************************************************************
* File End!
****************************************************************************************************/
