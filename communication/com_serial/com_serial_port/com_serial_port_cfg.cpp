
/****************************************************************************************************
* File com_serial_port_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "com_serial_port_cfg.h"
/* cpp */
#include "qserialport.h"

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* com_serial_port_cfg */
com_serial_port_cfg_struct com_serial_port_cfg_t =
{
    .id = 0,
    .baudrate_map =
    {
        {"1200",QSerialPort::Baud1200},
        {"2400",QSerialPort::Baud2400},
        {"4800",QSerialPort::Baud4800},
        {"9600",QSerialPort::Baud9600},
        {"19200",QSerialPort::Baud19200},
        {"38400",QSerialPort::Baud38400},
        {"57600",QSerialPort::Baud57600},
        {"115200",QSerialPort::Baud115200}
    },
    .databits_map =
    {
        {"8位",QSerialPort::Data8},
        {"7位",QSerialPort::Data7},
        {"6位",QSerialPort::Data6},
        {"5位",QSerialPort::Data5}
    },
    .parity_map =
    {
        {"无校验",QSerialPort::NoParity},
        {"偶校验",QSerialPort::EvenParity},
        {"奇校验",QSerialPort::OddParity},
        {"空校验",QSerialPort::SpaceParity},
        {"标记校验",QSerialPort::MarkParity}
    },
    .stopbits_map =
    {
        {"1位",QSerialPort::OneStop},
        {"1.5位",QSerialPort::OneAndHalfStop},
        {"2位",QSerialPort::TwoStop},
    }
};
/* init flag */
cc_boolean com_serial_port_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* com_serial_port_cfg_init()
****************************************************************************************************/
cc_result com_serial_port_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init com_serial_port_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}


/****************************************************************************************************
* com_serial_port_cfg_getcfg()
****************************************************************************************************/
cc_result com_serial_port_cfg_getcfg(com_serial_port_cfg_struct **cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        /* output */
        *cfg_t = &com_serial_port_cfg_t;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_serial_port_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_com_serial_port_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_cfg_get_baudrate()
****************************************************************************************************/
cc_result com_serial_port_cfg_get_baudrate(QSerialPort::BaudRate *baudrate_dst,QString baudrate_src)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,baudrate_dst);
        /* seek */
        for (cc_uint32 i = 0; i < COM_SERIAL_PORT_CFG_BAUDRATE_MAP_NUM; ++i)
        {
            if (com_serial_port_cfg_t.baudrate_map[i].name != baudrate_src)
            {
                continue;
            }
            *baudrate_dst = com_serial_port_cfg_t.baudrate_map[i].baudrate;
            result = CC_E_OK;
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_cfg_get_databits()
****************************************************************************************************/
cc_result com_serial_port_cfg_get_databits(QSerialPort::DataBits *databits_dst,QString databits_src)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,databits_dst);
        /* seek */
        for (cc_uint32 i = 0; i < COM_SERIAL_PORT_CFG_DATABITS_MAP_NUM; ++i)
        {
            if (com_serial_port_cfg_t.databits_map[i].name != databits_src)
            {
                continue;
            }
            *databits_dst = com_serial_port_cfg_t.databits_map[i].databits;
            result = CC_E_OK;
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_cfg_get_parity()
****************************************************************************************************/
cc_result com_serial_port_cfg_get_parity(QSerialPort::Parity *parity_dst,QString parity_src)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,parity_dst);
        /* seek */
        for (cc_uint32 i = 0; i < COM_SERIAL_PORT_CFG_PARITY_MAP_NUM; ++i)
        {
            if (com_serial_port_cfg_t.parity_map[i].name != parity_src)
            {
                continue;
            }
            *parity_dst = com_serial_port_cfg_t.parity_map[i].parity;
            result = CC_E_OK;
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* com_serial_port_cfg_get_stopbits()
****************************************************************************************************/
cc_result com_serial_port_cfg_get_stopbits(QSerialPort::StopBits *stopbits_dst,QString stopbits_src)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,stopbits_dst);
        /* seek */
        for (cc_uint32 i = 0; i < COM_SERIAL_PORT_CFG_STOPBITS_MAP_NUM; ++i)
        {
            if (com_serial_port_cfg_t.stopbits_map[i].name != stopbits_src)
            {
                continue;
            }
            *stopbits_dst = com_serial_port_cfg_t.stopbits_map[i].stopbits;
            result = CC_E_OK;
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_serial_port_cfg.c End!
****************************************************************************************************/

