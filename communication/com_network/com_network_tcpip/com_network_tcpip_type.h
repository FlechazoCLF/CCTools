
/****************************************************************************************************
* File com_network_tcpip_type.h Start!
****************************************************************************************************/

#ifndef _COM_NETWORK_TCPIP_TYPE_H
#define _COM_NETWORK_TCPIP_TYPE_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QByteArray>
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* rx buffer */
#define COM_NETWORK_TCPIP_BUFFER_SIZE (2048)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* role */
typedef enum
{
    CC_COM_NETWORK_TCPIP_ROLE_MASTER = 0,
    CC_COM_NETWORK_TCPIP_ROLE_CLIENT,
    CC_COM_NETWORK_TCPIP_ROLE_END
}cc_com_network_tcpip_role_struct;

/* direction */
typedef enum
{
    CC_COM_NETWORK_TCPIP_DIRECTION_NULL = 0,
    CC_COM_NETWORK_TCPIP_DIRECTION_TX,
    CC_COM_NETWORK_TCPIP_DIRECTION_RX,
    CC_COM_NETWORK_TCPIP_DIRECTION_END
}cc_com_network_tcpip_direction_struct;

/* mode */
typedef enum
{
    CC_COM_NETWORK_TCPIP_MODE_HEX = 0,
    CC_COM_NETWORK_TCPIP_MODE_ASCII,
    CC_COM_NETWORK_TCPIP_MODE_END
}cc_com_network_tcpip_mode_struct;

/* cc_com_network_tcpip_rxdata_struct */
typedef struct
{
    /* data origin */
    cc_boolean rxflag;
    QByteArray rxqbytearray;
    /* to str */
    QString rxqstring;
    /* hex */
    QString rxqstringhex;
    QByteArray rxqbytearrayhex;
    cc_uint16 length;
    cc_uint8 buffer[COM_NETWORK_TCPIP_BUFFER_SIZE];
}cc_com_network_tcpip_rxdata_struct;

/* cc_com_network_tcpip_type */
typedef struct
{
    cc_uint8 id;
}cc_com_network_tcpip_type_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/


#endif /* _COM_NETWORK_TCPIP_TYPE_H */
/****************************************************************************************************
* File com_network_tcpip_type.h End!
****************************************************************************************************/

