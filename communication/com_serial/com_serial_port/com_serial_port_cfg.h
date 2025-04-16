
/****************************************************************************************************
* File com_serial_port_cfg.h Start!
****************************************************************************************************/

#ifndef _COM_SERIAL_PORT_CFG_H
#define _COM_SERIAL_PORT_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "cc_type.h"
/* cpp */
#include "qserialport.h"

/****************************************************************************************************
* Define
****************************************************************************************************/

/* get cfg */
#define COM_SERIAL_PORT_CFG_GET(value,type) /* todo */
/* BaudRate */
#define COM_SERIAL_PORT_CFG_BAUDRATE_MAP_NUM (8u)
/* DataBits */
#define COM_SERIAL_PORT_CFG_DATABITS_MAP_NUM (4u)
/* Parity */
#define COM_SERIAL_PORT_CFG_PARITY_MAP_NUM (5u)
/* StopBits */
#define COM_SERIAL_PORT_CFG_STOPBITS_MAP_NUM (3u)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* BaudRate */
typedef struct
{
    QString name;
    QSerialPort::BaudRate baudrate;
}com_serial_port_cfg_baudrate_map_struct;

/* DataBits */
typedef struct
{
    QString name;
    QSerialPort::DataBits databits;
}com_serial_port_cfg_databits_map_struct;

/* Parity */
typedef struct
{
    QString name;
    QSerialPort::Parity parity;
}com_serial_port_cfg_parity_map_struct;

/* StopBits */
typedef struct
{
    QString name;
    QSerialPort::StopBits stopbits;
}com_serial_port_cfg_stopbits_map_struct;

/* com_serial_port_cfg */
typedef struct
{
    cc_uint8 id;
    com_serial_port_cfg_baudrate_map_struct baudrate_map[COM_SERIAL_PORT_CFG_BAUDRATE_MAP_NUM];
    com_serial_port_cfg_databits_map_struct databits_map[COM_SERIAL_PORT_CFG_DATABITS_MAP_NUM];
    com_serial_port_cfg_parity_map_struct parity_map[COM_SERIAL_PORT_CFG_PARITY_MAP_NUM];
    com_serial_port_cfg_stopbits_map_struct stopbits_map[COM_SERIAL_PORT_CFG_STOPBITS_MAP_NUM];
}com_serial_port_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result com_serial_port_cfg_init(cc_void);
cc_result cc_com_serial_port_cfg_mainfunction(cc_void);
cc_result com_serial_port_cfg_getcfg(com_serial_port_cfg_struct **cfg_t);

cc_result com_serial_port_cfg_get_baudrate(QSerialPort::BaudRate *baudrate_dst,QString baudrate_src);
cc_result com_serial_port_cfg_get_databits(QSerialPort::DataBits *databits_dst,QString databits_src);
cc_result com_serial_port_cfg_get_parity(QSerialPort::Parity *parity_dst,QString parity_src);
cc_result com_serial_port_cfg_get_stopbits(QSerialPort::StopBits *stopbits_dst,QString stopbits_src);

#endif /* _COM_SERIAL_PORT_CFG_H */
/****************************************************************************************************
* File com_serial_port_cfg.h End!
****************************************************************************************************/

