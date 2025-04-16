
/****************************************************************************************************
* Start File
****************************************************************************************************/

#ifndef _TYPE_H
#define _TYPE_H
/****************************************************************************************************
* Include
****************************************************************************************************/

/****************************************************************************************************
* Define
****************************************************************************************************/

/* true & false */
#define CC_TRUE (1u)
#define CC_FALSE (0u)
/* std_on & std_off */
#define CC_STD_ON (CC_TRUE)
#define CC_STD_OFF (CC_FALSE)
/* null & null_ptr */
#define CC_NULL (0u)
#define CC_NULL_PTR ((void *)0u)

/* len of name & log */
#define CC_NAME_MAX_LEN (16)
#define CC_LOG_MAX_LEN (32)
#define CC_PARAMETER_MAX_LEN (48)
#define CC_INFO_MAX_LEN (48)

#define ____________________TO_DO____________________

/****************************************************************************************************
* Type
****************************************************************************************************/

/* typedef base type of data */
typedef void cc_void;
typedef unsigned char cc_boolean;
typedef unsigned char cc_uint8;
typedef unsigned short cc_uint16;
typedef unsigned int cc_uint32;
typedef unsigned long long cc_uint64;
typedef char cc_int8;
typedef short cc_int16;
typedef int cc_int32;
typedef long long cc_int64;

/* type of return value */
typedef enum
{
    CC_E_OK = 0,
    CC_E_NOT_OK,
    CC_E_NOT_OK_UNINIT,
    CC_E_NOT_OK_NULL_VAR,
    CC_E_NOT_OK_NULL_POINTER,
    CC_E_NOT_OK_NOT_FIND,
    /* strcmp */
    CC_E_NOT_OK_SMALLER,
    CC_E_NOT_OK_BIGGER,
    CC_E_END
}cc_result;

/* check variable */
#define CHECK_VAR(r,v) \
{\
    if((v) == CC_NULL)\
    {\
        (r) = CC_E_NOT_OK_NULL_VAR;\
        continue;\
    }\
}

/* check pointer */
#define CHECK_PTR(r,p) \
{\
    if((p) == CC_NULL_PTR)\
    {\
        (r) = CC_E_NOT_OK_NULL_POINTER;\
        continue;\
    }\
}

/* check result */
#define CHECK_FUNC(r,func) \
{\
    (r) = (func);\
    if(CC_E_OK != (r))\
    {\
        continue;\
    }\
}

/* check logic */
#define CHECK_LOGIC(r,logic) \
    if(!(logic))\
    {\
        r = CC_E_NOT_OK;\
        continue;\
    }

/****************************************************************************************************
* Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/


#endif /* _TYPE_H */

/****************************************************************************************************
* End File
****************************************************************************************************/
