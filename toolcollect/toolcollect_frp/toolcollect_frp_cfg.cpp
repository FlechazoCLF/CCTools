
/****************************************************************************************************
* File toolcollect_frp_cfg.c Start!
****************************************************************************************************/

/*
 *
 *  Copyright (c) 2024-2025 by flechazo. All rights reserved.
 *
 * Author : CarlChai LinFeng Chai flechazo
 * Website: flechazo.mba
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-03-26     cc          the first version
 *
*/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "toolcollect_frp_cfg.h"
/* log */
/* sub module */
/* components */
#include "file.h"
#include "toolcollect.h"
#include "cctools_cfg.h"

/* ui */
#include "ui_toolcollect.h"
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* tcp/udp http */
QString cc_toolcollect_frp_cfg_item_tcpudp = "\
[[proxies]]\n\
name = \"{clientitem_name}\"\n\
type = \"{clientitem_type}\"\n\
localIP = \"{clientitem_localIP}\"\n\
localPort = {clientitem_localPort}\n\
remotePort = {clientitem_remotePort}\n";
QString cc_toolcollect_frp_cfg_item_http = "\
[[proxies]]\n\
name = \"{clientitem_name}\"\n\
type = \"{clientitem_type}\"\n\
localIP = \"{clientitem_localIP}\"\n\
localPort = {clientitem_localPort}\n\
customDomains = [\"{clientitem_customDomains}\"]\n\
subdomain = {clientitem_subdomain}\n";

/* cc_toolcollect_frp_cfg */
cc_toolcollect_frp_cfg_struct cc_toolcollect_frp_cfg_t =
{
    .service =
    {
        .frps = \
/* service port */
"# {name}\n\
bindPort = {port}\n\
auth.method = \"token\"\n\
auth.token = \"{token}\"\n",
        /* config */
        .name = "frps",
        .port = "7000",
        .token = "flechazo"
    },
    .client =
    {
        .frpc = \
/* client config */
"\
serverAddr = \"{serviceip}\"\n\
serverPort = {serviceport}\n\
auth.method = \"token\"\n\
auth.token = \"{token}\"\n\
\n",
        .frpcinclude = \
/* include */
"includes = [\"./{clientname}/{clientitem_path}/*.toml\"]\n",
        /* config */
        .name = "frpc",
        .serviceip = "frp.freefrp.net",
        .serviceport = "7000",
        .token = "freefrp.net",
        .itemlist =
        {
            [0] =
            {
                .item = "\
[[proxies]]\n\
name = \"{clientitem_name}\"\n\
type = \"{clientitem_type}\"\n\
localIP = \"{clientitem_localip}\"\n\
localPort = {clientitem_localport}\n\
remotePort = {clientitem_remoteport}\n",
                .itemtype = CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCP,
                /* config */
                .name = "ssh",
                .type = "tcp",
                .localip = "192.168.2.1",
                .localport = "2222",
                .remoteport = "40002",
            },
            [1] =
            {

            },
        }
    }
};

/* config map */
cc_toolcollect_frp_cfg_item_map_struct cc_toolcollect_frp_cfg_item_map_t[CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_END] = 
{
    /*               type                                           func                         */
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_UDP , cc_toolcollect_frp_cfg_generate_client_item_udp_config },
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCP , cc_toolcollect_frp_cfg_generate_client_item_tcp_config },
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_STCP , CC_NULL},
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_XTCP , CC_NULL},
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCPMUX , CC_NULL},
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_HTTP , cc_toolcollect_frp_cfg_generate_client_item_http_config },
    { CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_HTTPS , CC_NULL}
};

/* init flag */
cc_boolean cc_toolcollect_frp_cfg_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_toolcollect_frp_cfg_init()
****************************************************************************************************/
cc_result ToolCollect::cc_toolcollect_frp_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(CC_TOOLCOLLECT_FRP_CFG_ITEM_END > 0));
        /* init path */
        this->ui->lineEdit_toolcollect_frp_config_path->setText((QString)CCTOOLS_CFG_DATABASE_PATH + "/thirdtools/frp");
        /* init service */
        this->ui->lineEdit_toolcollect_frp_view_service_config_port->setText(cc_toolcollect_frp_cfg_t.service.port);
        this->ui->lineEdit_toolcollect_frp_view_service_config_token->setText(cc_toolcollect_frp_cfg_t.service.token);
        /* init client */
        this->ui->lineEdit_toolcollect_frp_view_client_service_ip->setText(cc_toolcollect_frp_cfg_t.client.serviceip);
        this->ui->lineEdit_toolcollect_frp_view_client_service_port->setText(cc_toolcollect_frp_cfg_t.client.serviceport);
        this->ui->lineEdit_toolcollect_frp_view_client_service_token->setText(cc_toolcollect_frp_cfg_t.client.token);
        this->ui->lineEdit_toolcollect_frp_view_client_config_name->setText(cc_toolcollect_frp_cfg_t.client.itemlist[0].name);
        this->ui->lineEdit_toolcollect_frp_view_client_config_localip->setText(cc_toolcollect_frp_cfg_t.client.itemlist[0].localip);
        this->ui->lineEdit_toolcollect_frp_view_client_config_localport->setText(cc_toolcollect_frp_cfg_t.client.itemlist[0].localport);
        this->ui->lineEdit_toolcollect_frp_view_client_config_token->setText(cc_toolcollect_frp_cfg_t.client.token);
        this->ui->lineEdit_toolcollect_frp_view_client_config_remoteport->setText(cc_toolcollect_frp_cfg_t.client.itemlist[0].remoteport);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_service_set_serviceport()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_service_set_serviceport(QString serviceport)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(serviceport != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.service.port = serviceport;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_service_set_token()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_service_set_token(QString token)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(token != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.service.token = token;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_client_set_name()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_client_set_name(QString name)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(name != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.client.name = name;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_client_set_serviceip()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_client_set_serviceip(QString serviceip)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(serviceip != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.client.serviceip = serviceip;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_client_set_serviceport()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_client_set_serviceport(QString serviceport)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(serviceport != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.client.serviceport = serviceport;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_client_set_token()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_client_set_token(QString token)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(token != ""));
        /* impletement */
        cc_toolcollect_frp_cfg_t.client.token = token;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_client_item_set()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_client_item_set(cc_uint32 idx,cc_toolcollect_frp_cfg_item_struct *item)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,item);
        CHECK_LOGIC(result,(idx < CC_TOOLCOLLECT_FRP_CFG_ITEM_END));
        /* impletement */
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].item = item->item;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].itemtype = item->itemtype;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].name = item->name;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].type = item->type;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].localip = item->localip;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].localport = item->localport;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].remoteport = item->remoteport;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].customDomains = item->customDomains;
        cc_toolcollect_frp_cfg_t.client.itemlist[idx].subdomain = item->subdomain;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_item_udp_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_item_udp_config(cc_uint32 idx,QString directory)
{
    cc_result result = CC_E_OK;
    cc_toolcollect_frp_cfg_item_struct *item;

    do
    {
        /* check */
        CHECK_PTR(result,cc_toolcollect_frp_cfg_t.client.itemlist);
        CHECK_LOGIC(result,(CC_TOOLCOLLECT_FRP_CFG_ITEM_END > 0));
        /* impletement */
        item = &cc_toolcollect_frp_cfg_t.client.itemlist[idx];
        /* check */
        CHECK_PTR(result,item);
        CHECK_LOGIC(result,(item->item != ""));
        CHECK_LOGIC(result,(item->itemtype == CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_UDP));
        CHECK_LOGIC(result,(item->name != ""));
        CHECK_LOGIC(result,(item->type != ""));
        CHECK_LOGIC(result,(item->localip != ""));
        CHECK_LOGIC(result,(item->localport != ""));
        CHECK_LOGIC(result,(item->remoteport != ""));
        /* content */
        QString itemcontent = item->item;
        itemcontent.replace("{clientitem_name}",item->name);
        itemcontent.replace("{clientitem_type}",item->type);
        itemcontent.replace("{clientitem_localip}",item->localip);
        itemcontent.replace("{clientitem_localport}",item->localport);
        itemcontent.replace("{clientitem_remoteport}",item->remoteport);
        /* file */
        QString frpcitemfile = directory + "/" + cc_toolcollect_frp_cfg_t.client.name + "/" + item->name + "/" + item->name + ".toml";
        cc_file_create(frpcitemfile,itemcontent);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_item_tcp_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_item_tcp_config(cc_uint32 idx,QString directory)
{
    cc_result result = CC_E_OK;
    cc_toolcollect_frp_cfg_item_struct *item;

    do
    {
        /* check */
        CHECK_PTR(result,cc_toolcollect_frp_cfg_t.client.itemlist);
        CHECK_LOGIC(result,(CC_TOOLCOLLECT_FRP_CFG_ITEM_END > 0));
        /* impletement */
        item = &cc_toolcollect_frp_cfg_t.client.itemlist[idx];
        /* check */
        CHECK_PTR(result,item);
        CHECK_LOGIC(result,(item->item != ""));
        CHECK_LOGIC(result,(item->itemtype == CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCP));
        CHECK_LOGIC(result,(item->name != ""));
        CHECK_LOGIC(result,(item->type != ""));
        CHECK_LOGIC(result,(item->localip != ""));
        CHECK_LOGIC(result,(item->localport != ""));
        CHECK_LOGIC(result,(item->remoteport != ""));
        /* content */
        QString itemcontent = item->item;
        itemcontent.replace("{clientitem_name}",item->name);
        itemcontent.replace("{clientitem_type}",item->type);
        itemcontent.replace("{clientitem_localip}",item->localip);
        itemcontent.replace("{clientitem_localport}",item->localport);
        itemcontent.replace("{clientitem_remoteport}",item->remoteport);
        /* file */
        QString frpcitemfile = directory + "/" + cc_toolcollect_frp_cfg_t.client.name + "/" + item->name + "/" + item->name + ".toml";
        cc_file_create(frpcitemfile,itemcontent);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_item_http_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_item_http_config(cc_uint32 idx,QString directory)
{
    cc_result result = CC_E_OK;
    cc_toolcollect_frp_cfg_item_struct *item;

    do
    {
        /* check */
        CHECK_PTR(result,cc_toolcollect_frp_cfg_t.client.itemlist);
        CHECK_LOGIC(result,(CC_TOOLCOLLECT_FRP_CFG_ITEM_END > 0));
        /* impletement */
        item = &cc_toolcollect_frp_cfg_t.client.itemlist[idx];
        /* check */
        CHECK_PTR(result,item);
        CHECK_LOGIC(result,(item->item != ""));
        CHECK_LOGIC(result,(item->itemtype == CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_HTTP));
        CHECK_LOGIC(result,(item->name != ""));
        CHECK_LOGIC(result,(item->type != ""));
        CHECK_LOGIC(result,(item->localip != ""));
        CHECK_LOGIC(result,(item->localport != ""));
        CHECK_LOGIC(result,(item->subdomain != ""));
        /* content */
        QString itemcontent = item->item;
        itemcontent.replace("{clientitem_name}",item->name);
        itemcontent.replace("{clientitem_type}",item->type);
        itemcontent.replace("{clientitem_localip}",item->localip);
        itemcontent.replace("{clientitem_localport}",item->localport);
        itemcontent.replace("{clientitem_customDomains}",item->customDomains);
        itemcontent.replace("{clientitem_subdomain}",item->subdomain);
        /* file */
        QString frpcitemfile = directory + "/" + cc_toolcollect_frp_cfg_t.client.name + "/" + item->name + "/" + item->name + ".toml";
        cc_file_create(frpcitemfile,itemcontent);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_item_config_getfunc()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_item_config_getfunc(cc_result (**func)(cc_uint32 idx,QString directory),cc_toolcollect_frp_cfg_item_type_enum type)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;

    do
    {
        /* check */
        CHECK_PTR(result,func);
        /* impletement */
        for (cc_uint32 i = 0; i < CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_END; i++)
        {
            /* check */
            if((cc_toolcollect_frp_cfg_item_map_t[i].itemtype == type) &&\
               (cc_toolcollect_frp_cfg_item_map_t[i].func != NULL))
            {
                *func = cc_toolcollect_frp_cfg_item_map_t[i].func;
                result = CC_E_OK;
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_item_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_item_config(QString directory)
{
    cc_result result = CC_E_OK;
    cc_result (*func)(cc_uint32 idx,QString directory) = NULL;

    do
    {
        /* check */
        CHECK_PTR(result,cc_toolcollect_frp_cfg_t.client.itemlist);
        CHECK_LOGIC(result,(CC_TOOLCOLLECT_FRP_CFG_ITEM_END > 0));
        /* impletement */
        for (cc_uint32 i = 0; i < CC_TOOLCOLLECT_FRP_CFG_ITEM_END; i++)
        {
            /* check item */
            CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.itemlist[i].item != ""));
            /* get func */
            cc_toolcollect_frp_cfg_generate_client_item_config_getfunc(&func,cc_toolcollect_frp_cfg_t.client.itemlist[i].itemtype);
            /* item */
            CHECK_PTR(result,func);
            /* generate */
            func(i,directory);
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_client_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_client_config(QString directory)
{
    cc_result result = CC_E_OK;
    QString frpc;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.frpc != ""));
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.frpcinclude != ""));
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.serviceip != ""));
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.serviceport != ""));
        /* impletement */
        /* 1.generate config */
        frpc = cc_toolcollect_frp_cfg_t.client.frpc;
        frpc.replace("{serviceip}",cc_toolcollect_frp_cfg_t.client.serviceip);
        frpc.replace("{serviceport}",cc_toolcollect_frp_cfg_t.client.serviceport);
        frpc.replace("{token}",cc_toolcollect_frp_cfg_t.client.token);
        for (cc_uint32 i = 0; i < CC_TOOLCOLLECT_FRP_CFG_ITEM_END; i++)
        {
            QString frpcinclude = cc_toolcollect_frp_cfg_t.client.frpcinclude;
            frpcinclude.replace("{clientname}",cc_toolcollect_frp_cfg_t.client.name);
            CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.client.itemlist[i].name != ""));
            frpcinclude.replace("{clientitem_path}",cc_toolcollect_frp_cfg_t.client.itemlist[i].name);
            frpc.append(frpcinclude);
        }
        QString frpcfile = directory + "/" + cc_toolcollect_frp_cfg_t.client.name + ".toml";
        cc_file_create(frpcfile,frpc);
        /* 2.generate item config */
        cc_toolcollect_frp_cfg_generate_client_item_config(directory);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_generate_service_config()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_generate_service_config(QString directory)
{
    cc_result result = CC_E_OK;
    QString frps;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.service.frps != ""));
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.service.name != ""));
        CHECK_LOGIC(result,(cc_toolcollect_frp_cfg_t.service.port != ""));
        /* impletement */
        /* 1.generate config */
        frps = cc_toolcollect_frp_cfg_t.service.frps;
        frps.replace("{name}",cc_toolcollect_frp_cfg_t.service.name);
        frps.replace("{port}",cc_toolcollect_frp_cfg_t.service.port);
        frps.replace("{token}",cc_toolcollect_frp_cfg_t.service.token);
        /* 2.write file */
        QString file = directory + "/" + cc_toolcollect_frp_cfg_t.service.name + ".toml";
        cc_file_create(file,frps);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_toolcollect_frp_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_toolcollect_frp_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File toolcollect_frp_cfg.c End!
****************************************************************************************************/

