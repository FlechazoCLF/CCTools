
/****************************************************************************************************
* File file_dir.h Start!
****************************************************************************************************/

#ifndef _FILE_DIR_H
#define _FILE_DIR_H

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
#include "qtreewidget.h"
#include <QTextBrowser>
/* cpp */
#include <QString>

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define FILE_DIR_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_FILE,CC_NULL_PTR,format,##__VA_ARGS__)

/****************************************************************************************************
* Type
****************************************************************************************************/

/* item column */
typedef enum
{
    CC_FILE_DIR_ITEM_COLUMN_NUM = 0,
    CC_FILE_DIR_ITEM_COLUMN_NAME,
    CC_FILE_DIR_ITEM_COLUMN_END
}cc_file_dir_item_column_enum;

/* type */
typedef enum
{
    CC_FILE_DIR_TYPE_FILE = 0,
    CC_FILE_DIR_TYPE_DIR,
    CC_FILE_DIR_TYPE_END
}cc_file_dir_type_enum;

/* cc_file_dir */
typedef struct cc_file_dir_struct_T
{
    /* parent */
    struct cc_file_dir_struct_T *parent;
    /* type */
    cc_file_dir_type_enum type;
    /* path */
    QString path;
    /* name */
    QString name;
    /* next */
    struct cc_file_dir_struct_T *next;
    /* children */
    struct cc_file_dir_struct_T *children;
}cc_file_dir_struct;

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/

cc_result cc_file_dir_init(cc_void);
cc_result cc_file_dir_mainfunction(cc_void);
cc_result cc_file_dir_check(QString directory);
cc_result cc_file_dir_create(QString directory);
cc_result cc_file_dir_getinfo(cc_file_dir_struct *dirinfo_t,QString path,cc_uint32 deep);
cc_result cc_file_dir_getfilelist(QStringList *qstringlist,cc_file_dir_struct *dirinfo_t);
cc_result cc_file_dir_show(cc_file_dir_struct *dirinfo_t,QTreeWidget *qTreeWidget);
cc_result cc_file_dir_getpath(QString *path,cc_file_dir_struct *dirinfo_t,QString name);
cc_result cc_file_dir_open(QString folderPath);

#endif /* _FILE_DIR_H */
/****************************************************************************************************
* File file_dir.h End!
****************************************************************************************************/

