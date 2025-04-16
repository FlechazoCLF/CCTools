
/****************************************************************************************************
* Start File
****************************************************************************************************/
#ifndef _PROJECT_WORKSTRUCT_CFG_H
#define _PROJECT_WORKSTRUCT_CFG_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
/****************************************************************************************************
* Define
****************************************************************************************************/
#define WORKSTRUCT_NAMELEN_MAX 32

/****************************************************************************************************
* Type
****************************************************************************************************/
/* WorkStructDirList_Struct */
typedef struct WorkStructDirList_T
{
    char name[WORKSTRUCT_NAMELEN_MAX];

    WorkStructDirList_T *parent;
    WorkStructDirList_T *next;
    WorkStructDirList_T *children;
}WorkStructDirList_Struct;

/* WorkStruct_Struct */
typedef struct
{
    WorkStructDirList_Struct *dirList;
}WorkStruct_Struct;

extern WorkStructDirList_Struct WorkStructDirList_t;
extern WorkStructDirList_Struct WorkStructDirList_t_0;
extern WorkStructDirList_Struct WorkStructDirList_t_1;
extern WorkStructDirList_Struct WorkStructDirList_t_2;
extern WorkStructDirList_Struct WorkStructDirList_t_3;
extern WorkStructDirList_Struct WorkStructDirList_t_4;
extern WorkStructDirList_Struct WorkStructDirList_t_5;
extern WorkStructDirList_Struct WorkStructDirList_t_6;
extern WorkStructDirList_Struct WorkStructDirList_t_7;
extern WorkStructDirList_Struct WorkStructDirList_t_8;
extern WorkStructDirList_Struct WorkStructDirList_t_9;
extern WorkStructDirList_Struct WorkStructDirList_t_10;

/****************************************************************************************************
* Function
****************************************************************************************************/


#endif
/****************************************************************************************************
* End File
****************************************************************************************************/
