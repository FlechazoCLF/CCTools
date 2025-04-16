
/****************************************************************************************************
* File cc_mem.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "mem.h"

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type Define
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/
/* mem */
cc_mem_struct cc_mem_t;
/* init flag */
cc_boolean cc_mem_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_mem_internal_init()
****************************************************************************************************/
cc_result cc_mem_internal_init(cc_mem_struct *mem)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,mem);
        /* impletement */
        mem->func.init = cc_mem_init;
        mem->func.detach = cc_mem_detach;
        mem->func.memcpy = cc_mem_cpy;
        mem->func.memset = cc_mem_set;
        mem->func.memcmp = cc_mem_cmp;
        mem->func.strlen = cc_mem_strlen;
        mem->func.strnlen = cc_mem_strnlen;
        mem->func.strcpy = cc_mem_strcpy;
        mem->func.strncpy = cc_mem_strncpy;
        mem->func.strcmp = cc_mem_strcmp;
        mem->func.strncmp = cc_mem_strncmp;
        mem->func.strstr = cc_mem_strstr;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_init()
****************************************************************************************************/
cc_result cc_mem_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_mem_initflag != CC_TRUE));

        /* init mem */
        cc_mem_internal_init(&cc_mem_t);

        /* init flag */
        cc_mem_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_detach()
****************************************************************************************************/
cc_result cc_mem_detach(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_LOGIC(result,(cc_mem_initflag == CC_TRUE));

        /* detach mem */

        /* init flag */
        cc_mem_initflag = CC_FALSE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_cpy()
****************************************************************************************************/
cc_result cc_mem_cpy(cc_void *dst,cc_void *src,cc_uint32 len)
{
    cc_result result = CC_E_OK;
    cc_uint8 *pDst;
    cc_uint8 *pSrc;
    cc_uint32 l;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* get pointer */
        pDst = (cc_uint8 *)dst;
        pSrc = (cc_uint8 *)src;

        /* Copy Algorithm */
        /* 
         *      |    len     |               |    len     |
         * ------------------------ 1     ------------------------ 2
         *      ^              ^             ^              ^
         *     dst            src           src            dst
         * 
         *      |    len xxxx|               |    len xxxx|
         * ------------------------ 3     ------------------------ 4
         *      ^        ^                   ^        ^
         *     dst      src                 src      dst
         */
        if((pDst <= pSrc)||(pDst > (pSrc + len)))
        {
            /* branch1 (1,2,3) */
            while(len--)
            {
                *pDst++ = *pSrc++;
            }
        }
        else
        {
            /* branch2 (4) */
            for(l = len;l > 0; l--)
            {
                pDst[l-1] = pSrc[l-1];
            }
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_set()
****************************************************************************************************/
cc_result cc_mem_set(cc_void *dst,cc_uint32 value,cc_uint32 len)
{
    cc_result result = CC_E_OK;
    cc_uint8 *pDst;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);

        /* set */
        pDst = (cc_uint8 *)dst;
        while(len--)
        {
            *pDst++ = value;
        }
        
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_cmp()
****************************************************************************************************/
cc_result cc_mem_cmp(cc_void *dst,cc_void *src,cc_uint32 len)
{
    cc_result result = CC_E_OK;
    cc_uint8 *pDst;
    cc_uint8 *pSrc;
    
    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* get pointer */
        pDst = (cc_uint8 *)dst;
        pSrc = (cc_uint8 *)src;
        /* compare */
        while(len--)
        {
            CHECK_LOGIC(result,(*pDst++ == *pSrc++));
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strlen()
****************************************************************************************************/
cc_result cc_mem_strlen(cc_int8 *src,cc_uint32 *len)
{
    cc_result result = CC_E_OK;
    const char *str;

    do
    {
        /* check parameter */
        CHECK_PTR(result,src);
        CHECK_PTR(result,len);

        /* impletement */
        str = src;
        while((*str) != '\0')
        {
            str++;
        }
        /* len */
        *len = (str - src);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strnlen()
****************************************************************************************************/
cc_result cc_mem_strnlen(cc_int8 *src,cc_uint32 *len,cc_uint32 maxlen)
{
    cc_result result = CC_E_OK;
    const char *str;

    do
    {
        /* check parameter */
        CHECK_PTR(result,src);
        CHECK_PTR(result,len);

        /* impletement */
        str = src;
        while(((*str) != '\0') && ((str - src) < maxlen))
        {
            str++;
        }
        /* len */
        *len = (str - src);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strcpy()
****************************************************************************************************/
cc_result cc_mem_strcpy(cc_int8 *dst,cc_int8 *src)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* impletement */
        while((*src) != '\0')
        {
            (*dst++) = (*src++);
        }
        (*dst) = '\0';

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strncpy()
****************************************************************************************************/
cc_result cc_mem_strncpy(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* impletement */
        while(((*src) != '\0') && ((maxlen--) != 0))
        {
            (*dst++) = (*src++);
        }
        (*dst) = '\0';
        
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strcmp()
****************************************************************************************************/
cc_result cc_mem_strcmp(cc_int8 *dst,cc_int8 *src)
{
    cc_result result = CC_E_OK;
    cc_int32 value;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* impletement */
        while(((*src) != '\0') && ( (*src++) == (*dst++) ))
        {
            /* code */
        }

        /* get diff */
        value = (*src) - (*dst);
        
        if(value == 0)
        {
            /* do nothing */
        }
        else if (value > 0)
        {
            result = CC_E_NOT_OK_BIGGER;
        }
        else
        {
            result = CC_E_NOT_OK_SMALLER;
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strncmp()
****************************************************************************************************/
cc_result cc_mem_strncmp(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen)
{
    cc_result result = CC_E_OK;
    cc_int32 value;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);

        /* impletement */
        while(((*src) != '\0') && ((maxlen--) != 0) && ( (*src++) == (*dst++) ))
        {
            /* code */
        }

        /* get diff */
        value = (*src) - (*dst);
        
        if(value == 0)
        {
            /* do nothing */
        }
        else if (value > 0)
        {
            result = CC_E_NOT_OK_BIGGER;
        }
        else
        {
            result = CC_E_NOT_OK_SMALLER;
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_strstr()
****************************************************************************************************/
cc_result cc_mem_strstr(cc_int8 *dst,cc_int8 *src,cc_int8 **findstr)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;
    cc_uint32 srclen;
    cc_uint32 dstlen;
    cc_int8 *str;

    do
    {
        /* check parameter */
        CHECK_PTR(result,dst);
        CHECK_PTR(result,src);
        CHECK_PTR(result,findstr);

        /* impletement */
        str = dst;
        *findstr = CC_NULL;
        /* get len */ 
        CHECK_FUNC(result,cc_mem_strlen(src,&srclen));
        CHECK_FUNC(result,cc_mem_strlen(dst,&dstlen));
        /* find */
        while(dstlen >= srclen)
        {
            if(cc_mem_strcmp(str,src) == CC_E_OK)
            {
                *findstr = str;
                result = CC_E_OK;
                break;
            }
            str++;
            dstlen--;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_mem_mainfunction()
****************************************************************************************************/
cc_result cc_mem_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File cc_mem.c End!
****************************************************************************************************/

