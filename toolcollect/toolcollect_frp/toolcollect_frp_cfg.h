
/****************************************************************************************************
* File toolcollect_frp_cfg.h Start!
****************************************************************************************************/

#ifndef _TOOLCOLLECT_FRP_CFG_H
#define _TOOLCOLLECT_FRP_CFG_H

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
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/* item */
typedef enum
{
    CC_TOOLCOLLECT_FRP_CFG_ITEM_SSH = 0,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_WEB,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_END
}cc_toolcollect_frp_cfg_item_enum;

/* item type */
typedef enum
{
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_UDP = 0,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCP,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_STCP,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_XTCP,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCPMUX,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_HTTP,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_HTTPS,
    CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_END
}cc_toolcollect_frp_cfg_item_type_enum;

/* type */
typedef enum
{
    CC_TOOLCOLLECT_FRP_CFG_TYPE_SERVICE = 0,
    CC_TOOLCOLLECT_FRP_CFG_TYPE_CLIENT,
    CC_TOOLCOLLECT_FRP_CFG_TYPE_END
}cc_toolcollect_frp_cfg_type_enum;

/* cc_toolcollect_frp_cfg_item_map_struct */
typedef struct
{
    cc_toolcollect_frp_cfg_item_type_enum itemtype;
    cc_result (*func)(cc_uint32 idx,QString directory);
}cc_toolcollect_frp_cfg_item_map_struct;

/* cc_toolcollect_frp_cfg_item_struct */
typedef struct
{
    /* template */
    QString item;
    cc_toolcollect_frp_cfg_item_type_enum itemtype;
    /* config */
    QString name;
    QString type;
    QString localip;
    QString localport;
    QString remoteport;
    QString customDomains;
    QString subdomain;
}cc_toolcollect_frp_cfg_item_struct;

/* cc_toolcollect_frp_cfg_service_struct */
typedef struct
{
    /* template */
    QString frps;
    /* config */
    QString name;
    QString port;
    QString token;
}cc_toolcollect_frp_cfg_service_struct;

/* cc_toolcollect_frp_cfg_client_struct */
typedef struct
{
    /* template */
    QString frpc;
    QString frpcinclude;
    /* config */
    QString name;
    QString serviceip;
    QString serviceport;
    QString token;
    cc_toolcollect_frp_cfg_item_struct itemlist[CC_TOOLCOLLECT_FRP_CFG_ITEM_END];
}cc_toolcollect_frp_cfg_client_struct;

/* cc_toolcollect_frp_cfg */
typedef struct
{
    cc_toolcollect_frp_cfg_service_struct service;
    cc_toolcollect_frp_cfg_client_struct client;
}cc_toolcollect_frp_cfg_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_toolcollect_frp_cfg_mainfunction(cc_void);
/* generate */
cc_result cc_toolcollect_frp_cfg_generate_service_config(QString directory);
cc_result cc_toolcollect_frp_cfg_generate_client_config(QString directory);
/* item */
cc_result cc_toolcollect_frp_cfg_generate_client_item_udp_config(cc_uint32 idx,QString directory);
cc_result cc_toolcollect_frp_cfg_generate_client_item_tcp_config(cc_uint32 idx,QString directory);
cc_result cc_toolcollect_frp_cfg_generate_client_item_http_config(cc_uint32 idx,QString directory);
/* set */
cc_result cc_toolcollect_frp_cfg_service_set_serviceport(QString serviceport);
cc_result cc_toolcollect_frp_cfg_service_set_token(QString token);
cc_result cc_toolcollect_frp_cfg_client_set_name(QString name);
cc_result cc_toolcollect_frp_cfg_client_set_serviceip(QString serviceip);
cc_result cc_toolcollect_frp_cfg_client_set_serviceport(QString serviceport);
cc_result cc_toolcollect_frp_cfg_client_set_token(QString token);
cc_result cc_toolcollect_frp_cfg_client_item_set(cc_uint32 idx,cc_toolcollect_frp_cfg_item_struct *item);

#endif /* _TOOLCOLLECT_FRP_CFG_H */
/****************************************************************************************************
* File toolcollect_frp_cfg.h End!
****************************************************************************************************/

