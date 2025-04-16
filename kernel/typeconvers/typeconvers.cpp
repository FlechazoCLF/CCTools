
/****************************************************************************************************
* File typeconvers.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "typeconvers.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type Define
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* TypeConvers_ASCIICharToUint8()
****************************************************************************************************/
cc_result TypeConvers_ASCIICharToUint8(char inputData,cc_uint8 *outputData)
{
    cc_result resultValue = CC_E_OK;
    cc_uint8 value;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,outputData);

        if(inputData >= '0' && inputData <= '9')
        {
            value =  inputData - '0';
        }
        else if (inputData >= 'A' && inputData <= 'F')
        {
            value =  inputData - 'A' + 10;
        }
        else if (inputData >= 'a' && inputData <= 'f')
        {
            value =  inputData - 'a' + 10;
        }
        else
        {
            resultValue = CC_E_NOT_OK;
            continue;
        }

        /* output */
        *outputData = value;

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_Int8ToUint8_Byte()
****************************************************************************************************/
cc_result TypeConvers_Int8ToUint8_Byte(const cc_int8 *inputData,cc_uint8 *outputData)
{
    cc_result resultValue = CC_E_OK;
    cc_uint8 tempArr[2] = {0};
    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,inputData);
        CHECK_PTR(resultValue,outputData);

        /* output */
        CHECK_FUNC(resultValue,TypeConvers_ASCIICharToUint8(inputData[0],tempArr));
        CHECK_FUNC(resultValue,TypeConvers_ASCIICharToUint8(inputData[1],&tempArr[1]));
        *outputData = (tempArr[0]<<4)|tempArr[1];

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_Int8ToUint8_Bytes()
****************************************************************************************************/
cc_result TypeConvers_Int8ToUint8_Bytes(char *inputData,cc_uint8 *outputData,cc_uint16 length)
{
    cc_result resultValue = CC_E_OK;
    cc_uint16 i;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,inputData);
        CHECK_PTR(resultValue,outputData);

        /* impletement */
        for (i = 0; i < length; i += 2)
        {
            /* output */
            CHECK_FUNC(resultValue,TypeConvers_Int8ToUint8_Byte(&inputData[i],&outputData[i/2]));
        }

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_QByteArrayToUint8()
****************************************************************************************************/
cc_result TypeConvers_QByteArrayToUint8(QByteArray inputQByteArray,cc_uint8 *outputData,cc_uint16 *inoutputlength)
{
    cc_result resultValue = CC_E_OK;
    char *pTempChar;
    QByteArray tempArr;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,outputData);
        CHECK_PTR(resultValue,inoutputlength);

        /* QString To QByteArray */
        tempArr = inputQByteArray;
        /* process len */
        if(tempArr.size()%2)
        {
            tempArr.insert(0,'0');
        }
        /* QByteArray To char * */
        pTempChar = tempArr.data();
        /* get length */
        *inoutputlength = ((tempArr.size()/2) >= *inoutputlength) ? ((*inoutputlength) * 2) : tempArr.size();
        /* char * To uint8 * */
        CHECK_FUNC(resultValue,TypeConvers_Int8ToUint8_Bytes(pTempChar,outputData,*inoutputlength));
        /* char length to uint8 length */
        *inoutputlength /= 2;
    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_QByteArrayToQString()
****************************************************************************************************/
cc_result TypeConvers_QByteArrayToQString(QByteArray inputQByteArray,QString *outputQString)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check pointer */
        CHECK_PTR(result,outputQString);
        /* QByteArray To QString */
        *outputQString = inputQByteArray;
    }while(0u);

    return result;
}

/****************************************************************************************************
* TypeConvers_QStringToUint8()
****************************************************************************************************/
cc_result TypeConvers_QStringToUint8(QString inputQString,cc_uint8 *outputData,cc_uint16 *outputlength)
{
    cc_result resultValue = CC_E_OK;
    char *pTempChar;
    QByteArray tempArr;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,outputData);
        if(inputQString == "")
        {
            continue;
        }

        /* QString To QByteArray */
        tempArr = inputQString.toLatin1();
        /* process len */
        if(tempArr.size()%2)
        {
            tempArr.insert(0,'0');
        }
        /* QByteArray To char * */
        pTempChar = tempArr.data();
        /* get length */
        *outputlength = tempArr.size();
        /* char * To uint8 * */
        CHECK_FUNC(resultValue,TypeConvers_Int8ToUint8_Bytes(pTempChar,outputData,*outputlength));
        /* char length to uint8 length */
        *outputlength /= 2;
    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_RadixConvers()
****************************************************************************************************/
cc_result TypeConvers_RadixConvers(cc_uint32 inputData,cc_uint8 *outputData,cc_uint8 radix)
{
    cc_result resultValue = CC_E_OK;
    char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cc_uint32 tempInputData;
    cc_uint16 len = 0;
    cc_uint16 i;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,outputData);

        /* impletement */
        tempInputData = inputData;
        do{
            outputData[len++] = index[tempInputData % radix];
            tempInputData /= radix;
        }while(tempInputData);

        /* output */
        for(i=0;i<(len-1)/2;i++)
        {
            outputData[i] = outputData[i]^outputData[len-1-i];
            outputData[len-1-i] = outputData[i]^outputData[len-1-i];
            outputData[i] = outputData[i]^outputData[len-1-i];
        }

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_NumberToQString()
****************************************************************************************************/
cc_result TypeConvers_NumberToQString(cc_uint32 number,QString *string,cc_uint16 length)
{
    cc_result resultValue = CC_E_OK;
    cc_uint8 data[4]={0};

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,string);

        /* number to uint8 */
        CHECK_FUNC(resultValue,TypeConvers_RadixConvers(number,data,16));

        /* process string */
        *string = (char *)data;
        /* process len */
        while(((*string).length()<length))
        {
            (*string).insert(0,"0");
        }

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_Uint8ToQString()
****************************************************************************************************/
cc_result TypeConvers_Uint8ToQString(cc_uint8 *inputData,QString *outputString,cc_uint16 length)
{
    cc_result resultValue = CC_E_OK;
    cc_uint16 i;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,inputData);
        CHECK_PTR(resultValue,outputString);

        for(i = 0;i < length;i++)
        {
            /* depart inputdata */
            char s1 = char(inputData[i] >> 4);
            char s2 = char(inputData[i] & 0xf);
            /* convers to ASCII */
            s1 > 9 ? s1 += 55 : s1 += 48;
            s2 > 9 ? s2 += 55 : s2 += 48;
            /* output QString */
            (*outputString).append(s1);
            (*outputString).append(s2);
        }

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_NumberToQString_QT()
****************************************************************************************************/
QString TypeConvers_NumberToQString_QT(cc_uint32 number)
{
    return QString::number(number);
}

/****************************************************************************************************
* TypeConvers_CharToQString_QT()
****************************************************************************************************/
QString TypeConvers_CharToQString_QT(char c)
{
    return QChar(c);
}

/****************************************************************************************************
* TypeConvers_Uint8ToUint32()
****************************************************************************************************/
cc_result TypeConvers_Uint8ToUint32(cc_uint8 *inputData,cc_uint32 *outputData,cc_uint16 length)
{
    cc_result resultValue = CC_E_OK;
    cc_uint16 g;
    cc_uint16 group;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,inputData);
        CHECK_PTR(resultValue,outputData);

        /* get group */
        group = length/4;

        /* to uint32 */
        for(g = 0;g <= group;g++)
        {
            outputData[g] = (inputData[0]<<24)+\
                            (inputData[1]<<16)+\
                            (inputData[2]<<8)+\
                            (inputData[3]);
        }

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* TypeConvers_Uint8ToUint32()
****************************************************************************************************/
cc_result TypeConvers_Uint8ToNumber(cc_uint8 *inputData,cc_uint64 *outputData,cc_uint16 length)
{
    cc_result resultValue = CC_E_OK;
    cc_uint16 i;

    do
    {
        /* check pointer */
        CHECK_PTR(resultValue,inputData);
        CHECK_PTR(resultValue,outputData);

        /* to number */
        for(i = 0;i < length;i++)
        {
            *outputData += inputData[i];
            *outputData <<= 8;
        }
        *outputData >>= 8;

    }while(0u);

    return resultValue;
}

/****************************************************************************************************
* File typeconvers.c End!
****************************************************************************************************/

