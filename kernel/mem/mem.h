
/****************************************************************************************************
* File cc_mem.h Start!
****************************************************************************************************/
#ifndef _CC_MEM_H
#define _CC_MEM_H

/****************************************************************************************************
* Include
****************************************************************************************************/
#include "cc_type.h"

/****************************************************************************************************
* Define
****************************************************************************************************/

/* mem func ctrlidx */
typedef enum
{
    CC_MEM_FUNCCTRLIDX_FREE = 0,
    CC_MEM_FUNCCTRLIDX_INIT,
    CC_MEM_FUNCCTRLIDX_DETACH,
    CC_MEM_FUNCCTRLIDX_MEMCPY,
    CC_MEM_FUNCCTRLIDX_MEMSET,
    CC_MEM_FUNCCTRLIDX_MEMCMP,
    CC_MEM_FUNCCTRLIDX_STRLEN,
    CC_MEM_FUNCCTRLIDX_STRNLEN,
    CC_MEM_FUNCCTRLIDX_STRCPY,
    CC_MEM_FUNCCTRLIDX_STRNCPY,
    CC_MEM_FUNCCTRLIDX_STRCMP,
    CC_MEM_FUNCCTRLIDX_STRNCMP,
    CC_MEM_FUNCCTRLIDX_STRSTR,
    CC_MEM_FUNCCTRLIDX_END
}cc_mem_funcctrlidx_enum;

/* number of func */
#define CC_MEM_CFG_FUNCTABLE_NUM (CC_MEM_FUNCCTRLIDX_END - 1)

/****************************************************************************************************
* Type Define
****************************************************************************************************/

/* mem func */
typedef struct
{
    /* init */
    cc_result (*init)(cc_void);
    /* detach */
    cc_result (*detach)(cc_void);
    /* memcpy */
    cc_result (*memcpy)(cc_void *dst,cc_void *src,cc_uint32 len);
    /* memset */
    cc_result (*memset)(cc_void *dst,cc_uint32 value,cc_uint32 len);
    /* memcmp */
    cc_result (*memcmp)(cc_void *dst,cc_void *src,cc_uint32 len);
    /* strlen */
    cc_result (*strlen)(cc_int8 *src,cc_uint32 *len);
    /* strnlen */
    cc_result (*strnlen)(cc_int8 *src,cc_uint32 *len,cc_uint32 maxlen);
    /* strcpy */
    cc_result (*strcpy)(cc_int8 *dst,cc_int8 *src);
    /* strncpy */
    cc_result (*strncpy)(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen);
    /* strcmp */
    cc_result (*strcmp)(cc_int8 *dst,cc_int8 *src);
    /* strncmp */
    cc_result (*strncmp)(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen);
    /* strstr */
    cc_result (*strstr)(cc_int8 *dst,cc_int8 *src,cc_int8 **findstr);
}cc_mem_func_struct;

/* mem */
typedef struct
{
    /* func */
    cc_mem_func_struct func;
}cc_mem_struct;

/****************************************************************************************************
* Function Interface
****************************************************************************************************/

/* mem */
cc_result cc_mem_init(cc_void);
cc_result cc_mem_detach(cc_void);
cc_result cc_mem_cpy(cc_void *dst,cc_void *src,cc_uint32 len);
cc_result cc_mem_set(cc_void *dst,cc_uint32 value,cc_uint32 len);
cc_result cc_mem_cmp(cc_void *dst,cc_void *src,cc_uint32 len);
/* str */
cc_result cc_mem_strlen(cc_int8 *src,cc_uint32 *len);
cc_result cc_mem_strnlen(cc_int8 *src,cc_uint32 *len,cc_uint32 maxlen);
cc_result cc_mem_strcpy(cc_int8 *dst,cc_int8 *src);
cc_result cc_mem_strncpy(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen);
cc_result cc_mem_strcmp(cc_int8 *dst,cc_int8 *src);
cc_result cc_mem_strncmp(cc_int8 *dst,cc_int8 *src,cc_uint32 maxlen);
cc_result cc_mem_strstr(cc_int8 *dst,cc_int8 *src,cc_int8 **findstr);

cc_result cc_mem_mainfunction(cc_void);

#endif /* _CC_MEM_H */
/****************************************************************************************************
* File cc_mem.h End!
****************************************************************************************************/

