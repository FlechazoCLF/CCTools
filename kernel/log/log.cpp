
/****************************************************************************************************
* File log.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "log.h"
#include "log_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include "qdatetime.h"

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* log */
log_struct log_t;
/* init flag */
cc_boolean log_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* log_init()
****************************************************************************************************/
cc_result log_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init log */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* log_print()
****************************************************************************************************/
cc_result log_print(cc_kernel_module_enum module,QTextBrowser *qTextBrowser,const char *format,...)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,qTextBrowser);
        CHECK_PTR(result,format);

        /* impletement */
        QString moduleinfo;
        log_cfg_module_info_get(module,&moduleinfo);
        /* timestamp */
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        QString logMessage = QString("[%1] [%2]:").arg(timestamp,moduleinfo);
        /* args */
        va_list args;
        va_start(args, format);

        QString formattedMessage = format;
        cc_int32 i = 0;
        while (formattedMessage.contains("%"))
        {
            if (formattedMessage.contains("%d"))
            {
                cc_int32 arg = va_arg(args, int);
                formattedMessage.replace(formattedMessage.indexOf("%d"), 2, QString::number(arg));
            }
            if (formattedMessage.contains("%x"))
            {
                cc_uint32 arg = va_arg(args, unsigned int);
                formattedMessage.replace(formattedMessage.indexOf("%x"), 2, QString::number(arg));
            }
            else if (formattedMessage.contains("%f"))
            {
                double arg = va_arg(args, double);
                formattedMessage.replace(formattedMessage.indexOf("%f"), 2, QString::number(arg));
            }
            else if (formattedMessage.contains("%s"))
            {
                const char* arg = va_arg(args, const char*);
                formattedMessage.replace(formattedMessage.indexOf("%s"), 2, QString(arg));
            }
            i++;
        }

        va_end(args);

        /* output */
        logMessage += formattedMessage;

        qTextBrowser->append(logMessage);
        qDebug() << logMessage;
    }while(0u);

    return result;
}

/****************************************************************************************************
* log_mainfunction()
****************************************************************************************************/
cc_result log_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File log.c End!
****************************************************************************************************/

