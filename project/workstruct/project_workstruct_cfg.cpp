
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "project_workstruct_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */

/****************************************************************************************************
* Variable
****************************************************************************************************/
/* dir list */
WorkStructDirList_Struct WorkStructDirList_t = {
    .name = "flechazo",
    .parent = 0,
    .next = 0,
    .children = &WorkStructDirList_t_0,
};

WorkStructDirList_Struct WorkStructDirList_t_0 = {
    .name = "00_backup",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_1,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_1 = {
    .name = "01_documents",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_2,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_2 = {
    .name = "02_input",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_3,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_3 = {
    .name = "03_plan",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_4,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_4 = {
    .name = "04_project",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_5,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_5 = {
    .name = "05_tools",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_6,
    .children = 0,
};

WorkStructDirList_Struct WorkStructDirList_t_6 = {
    .name = "06_test",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_7,
    .children = nullptr,
};

WorkStructDirList_Struct WorkStructDirList_t_7 = {
    .name = "07_output",
    .parent = &WorkStructDirList_t,
    .next = &WorkStructDirList_t_8,
    .children = nullptr,
};

WorkStructDirList_Struct WorkStructDirList_t_8 = {
    .name = "99_draft",
    .parent = &WorkStructDirList_t,
    .next = nullptr,
    .children = nullptr,
};

/****************************************************************************************************
* Function
****************************************************************************************************/


/****************************************************************************************************
* End File
****************************************************************************************************/
