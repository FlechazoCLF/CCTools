
/****************************************************************************************************
* File com_serial_port.h Start!
****************************************************************************************************/

#ifndef _COM_SERIAL_PORT_H
#define _COM_SERIAL_PORT_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "com_serial.h"

/* ui */
#include <QTextBrowser>
/* cpp */
#include "qcombobox.h"

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define COM_SERIAL_PORT_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_COMMUNICATION,cc_com_serial_port_t.qtextbrower,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* direction */
typedef enum
{
    CC_COM_SERIAL_PORT_DIRECTION_NULL = 0,
    CC_COM_SERIAL_PORT_DIRECTION_TX,
    CC_COM_SERIAL_PORT_DIRECTION_RX,
    CC_COM_SERIAL_PORT_DIRECTION_END
}cc_com_serial_port_direction_struct;

/* mode */
typedef enum
{
    CC_COM_SERIAL_PORT_MODE_HEX = 0,
    CC_COM_SERIAL_PORT_MODE_ASCII,
    CC_COM_SERIAL_PORT_MODE_END
}cc_com_serial_port_mode_struct;

/* com_serial_port */
typedef struct
{
    cc_uint8 id;

    /* log */
    QTextBrowser *qtextbrower;
}cc_com_serial_port_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_com_serial_port_init(cc_com_serial_struct *com_serial_t);
cc_result cc_com_serial_port_push(QComboBox *qComboBox);
cc_result cc_com_serial_port_data_read(cc_void);
/* timeout receive */
cc_result cc_com_serial_port_data_receive(cc_void);
cc_result cc_com_serial_port_send(QSerialPort *serialPort,QString content,cc_com_serial_port_mode_struct mode);
cc_result cc_com_serial_port_mainfunction(cc_void);

#endif /* _COM_SERIAL_PORT_H */
/****************************************************************************************************
* File com_serial_port.h End!
****************************************************************************************************/

