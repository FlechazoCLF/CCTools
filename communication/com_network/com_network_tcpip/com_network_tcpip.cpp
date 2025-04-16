
/****************************************************************************************************
* File com_network_tcpip.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "com_network.h"
#include "com_network_tcpip.h"
/* log */
/* sub module */
/* components */

/* ui */
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

/* cc_com_network_tcpip_struct */
cc_com_network_tcpip_struct cc_com_network_tcpip_t;
/* init flag */
cc_boolean cc_com_network_tcpip_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_com_network_tcpip_init()
****************************************************************************************************/
cc_result Com_Network::cc_com_network_tcpip_init(cc_com_network_tcpip_struct *cfg)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg);
        CHECK_PTR(result,cfg->textbrowser);

        /* view */
        this->cc_com_network_tcpip_t.textbrowser = cfg->textbrowser;

        COM_NETWORK_TCPIP_LOG_PRINT("tcpip start init");
        /* init server */
        cfg->server_t.receive = cc_com_network_tcpip_recv;
        cc_com_network_tcpip_server_init(&cfg->server_t);
        /* init client */
        cfg->client_t.receive = cc_com_network_tcpip_recv;
        cc_com_network_tcpip_client_init(&cfg->client_t);

        COM_NETWORK_TCPIP_LOG_PRINT("tcpip init complete");
        cc_com_network_tcpip_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_recv()
****************************************************************************************************/
cc_result cc_com_network_tcpip_recv(cc_com_network_tcpip_role_struct role,cc_com_network_tcpip_rxdata_struct *rxdata_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,rxdata_t);
        /* user code */
        switch (role)
        {
        case CC_COM_NETWORK_TCPIP_ROLE_MASTER:
            {
            }
            break;
        case CC_COM_NETWORK_TCPIP_ROLE_CLIENT:
            {
            }
            break;
        default:
            break;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_com_network_tcpip_mainfunction()
****************************************************************************************************/
cc_result cc_com_network_tcpip_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        cc_com_network_tcpip_server_mainfunction();
        cc_com_network_tcpip_client_mainfunction();
    }while(0u);

    return result;
}

/****************************************************************************************************
* File com_network_tcpip.c End!
****************************************************************************************************/

