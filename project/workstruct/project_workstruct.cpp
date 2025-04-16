
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "project_workstruct.h"
#include "project_workstruct_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QString>
#include <QFileDialog>

/****************************************************************************************************
* Variable
****************************************************************************************************/

/* dir list */
WorkStruct_Struct WorkStruct_t =
{
    .dirList = &WorkStructDirList_t,
};

/* init */
cc_project_workstruct_struct cc_project_workstruct_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* cc_project_workstruct_init()
****************************************************************************************************/
cc_result cc_project_workstruct_init(cc_project_workstruct_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        CHECK_PTR(result,cfg_t->QTextEdit_Log);

        /* init log */
        cc_project_workstruct_t.QTextEdit_Log = cfg_t->QTextEdit_Log;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_workstruct_print()
****************************************************************************************************/
cc_result cc_project_workstruct_print(QString str)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cc_project_workstruct_t.QTextEdit_Log);

        /* init log */
        cc_project_workstruct_t.QTextEdit_Log->append(str);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_workstruct_create()
****************************************************************************************************/
cc_result cc_project_workstruct_create(QString directory)
{
    cc_result result = CC_E_OK;
    QDir dir(directory);
    do
    {
        /* check */
        if (WorkStruct_t.dirList == NULL)
        {
            result = CC_E_NOT_OK;
            continue;
        }

        /* iterator */
        WorkStructDirList_Struct *item = WorkStruct_t.dirList;
        do
        {
            /* check */
            if(item->name == "")
            {
                break;
            }

            /* 1.create folder */
            dir.mkdir(item->name);
            cc_project_workstruct_print("[信息🎃]创建了一个文件" + QString(item->name) + "✨");
            dir.cd(item->name);

            /* 2.create sub folder */
            if(item->children != NULL)
            {
                /* child */
                item = item->children;
                continue;
            }

            /* 3.next */
            if(item->next != NULL)
            {
                dir.cdUp();
                item = item->next;
                continue;
            }
            /* break */
            break;
        }while(1);
    }while(0u);

    return result;
}

/****************************************************************************************************
* End File
****************************************************************************************************/
