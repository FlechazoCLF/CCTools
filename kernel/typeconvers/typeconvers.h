
/****************************************************************************************************
* File typeconvers.h Start!
****************************************************************************************************/
#ifndef _TYPECONVERS_H
#define _TYPECONVERS_H

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
* Type Define
****************************************************************************************************/

/****************************************************************************************************
* Function Interface
****************************************************************************************************/
/* uint8 <-> QString */
cc_result TypeConvers_Uint8ToQString(cc_uint8 *inputData,QString *outputString,cc_uint16 length);
cc_result TypeConvers_QStringToUint8(QString inputQString,cc_uint8 *outputData,cc_uint16 *outputlength);
/* QByteArray -> uint8 */
cc_result TypeConvers_QByteArrayToUint8(QByteArray inputQByteArray,cc_uint8 *outputData,cc_uint16 *inoutputlength);
cc_result TypeConvers_QByteArrayToQString(QByteArray inputQByteArray,QString *outputQString);
/* int8 -> uint8 */
cc_result TypeConvers_Int8ToUint8_Bytes(char *inputData,cc_uint8 *outputData,cc_uint16 length);
/* 2 <> 10 <> 16 */
cc_result TypeConvers_RadixConvers(cc_uint32 inputData,cc_uint8 *outputData,cc_uint8 radix);
/* uint32 -> QString */
cc_result TypeConvers_NumberToQString(cc_uint32 number,QString *string,cc_uint16 length);
QString TypeConvers_NumberToQString_QT(cc_uint32 number);
/* char -> QString */
QString TypeConvers_CharToQString_QT(char c);
/* uint8 -> uint32 */
cc_result TypeConvers_Uint8ToUint32(cc_uint8 *inputData,cc_uint32 *outputData,cc_uint16 length);
cc_result TypeConvers_Uint8ToNumber(cc_uint8 *inputData,cc_uint64 *outputData,cc_uint16 length);

#endif /* _TYPECONVERS_H */
/****************************************************************************************************
* File typeconvers.h End!
****************************************************************************************************/

