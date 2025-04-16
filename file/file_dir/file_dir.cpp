
/****************************************************************************************************
* File file_dir.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
/* log */
/* sub module */
/* components */
#include "file_dir.h"

/* ui */
#include "qtreewidget.h"
/* cpp */
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_file_dir */
cc_file_dir_struct *cc_file_dir_t;
/* init flag */
cc_boolean cc_file_dir_initflag = CC_FALSE;
/* deep */
cc_uint32 cc_file_dir_readdeep = 0;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_file_dir_init()
****************************************************************************************************/
cc_result cc_file_dir_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(cc_file_dir_initflag != CC_TRUE));

        /* init flag */
        cc_file_dir_initflag = CC_TRUE;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_insertchild()
****************************************************************************************************/
cc_result cc_file_dir_insertchild(cc_file_dir_struct *dirinfo,cc_file_dir_struct *child_dirinfo)
{
    cc_result result = CC_E_OK;
    cc_file_dir_struct **iterator;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo);
        CHECK_PTR(result,child_dirinfo);
        /* firt child */
        if(dirinfo->children == nullptr)
        {
            dirinfo->children = child_dirinfo;
        }
        else
        {
            /* iterator */
            iterator = &dirinfo->children;
            while(((*iterator) != nullptr) && ((*iterator)->next != nullptr))
            {
                iterator = &(*iterator)->next;
            }
            /* insert */
            (*iterator)->next = child_dirinfo;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_read()
****************************************************************************************************/
cc_result cc_file_dir_read(cc_file_dir_struct *dirinfo_t,QString directory,cc_uint32 deep)
{
    cc_result result = CC_E_OK;
    QDir dir(directory);

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_LOGIC(result,(directory != ""));
        CHECK_LOGIC(result,dir.exists());
        CHECK_LOGIC(result,cc_file_dir_readdeep < deep);

        /* iterator read directory & file */
        QFileInfoList infolist = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
        for (const QFileInfo &info : infolist)
        {
            cc_file_dir_struct *new_file_dir_t = new cc_file_dir_struct;
            new_file_dir_t->parent = dirinfo_t;
            new_file_dir_t->type = CC_FILE_DIR_TYPE_FILE;
            new_file_dir_t->path = directory + "/" + info.fileName();
            new_file_dir_t->name = info.fileName();
            new_file_dir_t->next = nullptr;
            new_file_dir_t->children = nullptr;
            /* insert child */
            cc_file_dir_insertchild(dirinfo_t,new_file_dir_t);
            if(info.isDir())
            {
                /* is dir */
                /* type */
                new_file_dir_t->type = CC_FILE_DIR_TYPE_DIR;
                /* into */
                cc_file_dir_readdeep++;
                cc_file_dir_read(new_file_dir_t,info.filePath(),deep);
                cc_file_dir_readdeep = 0;
            }
            else if(info.isFile())
            {
                /* is file */
                new_file_dir_t->type = CC_FILE_DIR_TYPE_FILE;
            }
            else
            {

            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_initinfo()
****************************************************************************************************/
cc_result cc_file_dir_initinfo(cc_file_dir_struct *dirinfo_t,QString path)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_LOGIC(result,(path != ""));

        /* init root info */
        dirinfo_t->parent = nullptr;
        dirinfo_t->type = CC_FILE_DIR_TYPE_DIR;
        dirinfo_t->path = path;
        dirinfo_t->name = path.split("/").last();
        dirinfo_t->next = nullptr;
        dirinfo_t->children = nullptr;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_getinfo()
****************************************************************************************************/
cc_result cc_file_dir_getinfo(cc_file_dir_struct *dirinfo_t,QString path,cc_uint32 deep)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_LOGIC(result,(path != ""));

        /* impletement */
        /* init root info */
        cc_file_dir_initinfo(dirinfo_t,path);
        /* read dir */
        cc_file_dir_read(dirinfo_t,path,deep);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_getfilelist()
****************************************************************************************************/
cc_result cc_file_dir_getfilelist(QStringList *qstringlist,cc_file_dir_struct *dirinfo_t)
{
    cc_result result = CC_E_OK;
    cc_file_dir_struct *iterator;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,qstringlist);

        /* impletement */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_qtreewidgetitem_get()
****************************************************************************************************/
cc_result cc_file_dir_qtreewidgetitem_get(QTreeWidgetItem **item,QString name,QTreeWidget *qTreeWidget)
{
    cc_result result = CC_E_NOT_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(name != ""));

        /* find item */
        for (QTreeWidgetItemIterator it(qTreeWidget); *it; ++it)
        {
            *item = *it;
            if((*item)->text(CC_FILE_DIR_ITEM_COLUMN_NAME) == name)
            {
                result = CC_E_OK;
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_display_dir()
****************************************************************************************************/
cc_result cc_file_dir_display_dir(cc_file_dir_struct *dirinfo_t,QTreeWidget *qTreeWidget)
{
    cc_result result = CC_E_OK;
    QTreeWidgetItem *itemparent;
    QTreeWidgetItem *item;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,cc_file_dir_t);
        CHECK_PTR(result,qTreeWidget);

        /* get parent */
        if((dirinfo_t->parent == nullptr) || \
            (dirinfo_t->parent->name == cc_file_dir_t->name))
        {
            itemparent = new QTreeWidgetItem(qTreeWidget);
            item = itemparent;
        }
        else
        {
            CHECK_FUNC(result,cc_file_dir_qtreewidgetitem_get(&itemparent,dirinfo_t->parent->name,qTreeWidget));
            /* create new item */
            item = new QTreeWidgetItem(itemparent);
        }
        item->setText(CC_FILE_DIR_ITEM_COLUMN_NUM,QString::number(itemparent->childCount()));
        item->setText(CC_FILE_DIR_ITEM_COLUMN_NAME,dirinfo_t->name);
        /* user callback */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_display_file()
****************************************************************************************************/
cc_result cc_file_dir_display_file(cc_file_dir_struct *dirinfo_t,QTreeWidget *qTreeWidget)
{
    cc_result result = CC_E_OK;
    QTreeWidgetItem *itemparent;
    QTreeWidgetItem *item;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,cc_file_dir_t);
        CHECK_PTR(result,qTreeWidget);

        /* get parent */
        if((dirinfo_t->parent == nullptr) || \
            (dirinfo_t->parent->name == cc_file_dir_t->name))
        {
            itemparent = new QTreeWidgetItem(qTreeWidget);
            item = itemparent;
        }
        else
        {
            CHECK_FUNC(result,cc_file_dir_qtreewidgetitem_get(&itemparent,dirinfo_t->parent->name,qTreeWidget));
            /* create new item */
            item = new QTreeWidgetItem(itemparent);
        }
        item->setText(CC_FILE_DIR_ITEM_COLUMN_NUM,QString::number(itemparent->childCount()));
        item->setText(CC_FILE_DIR_ITEM_COLUMN_NAME,dirinfo_t->name);
        /* user callback */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_display()
****************************************************************************************************/
cc_result cc_file_dir_display(cc_file_dir_struct *dirinfo_t,QTreeWidget *qTreeWidget)
{
    cc_result result = CC_E_OK;
    cc_file_dir_struct *iterator;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,qTreeWidget);

        /* iterator */
        iterator = dirinfo_t->children;
        while(iterator != nullptr)
        {
            /* push base struct */
            switch (iterator->type)
            {
            case CC_FILE_DIR_TYPE_DIR:
            {
                cc_file_dir_display_dir(iterator,qTreeWidget);
            }
            break;
            case CC_FILE_DIR_TYPE_FILE:
            {
                cc_file_dir_display_file(iterator,qTreeWidget);
            }
            break;
            default:
                break;
            }
            /* children */
            if (iterator->children != nullptr)
            {
                cc_file_dir_display(iterator,qTreeWidget);
            }
            /* next */
            if (iterator->next == nullptr)
            {
                break;
            }
            iterator = iterator->next;
        }

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_show()
****************************************************************************************************/
cc_result cc_file_dir_show(cc_file_dir_struct *dirinfo_t,QTreeWidget *qTreeWidget)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,qTreeWidget);

        /* impletement */
        /* init header */
        QStringList headers;
        headers << "序号" << "名称";
        qTreeWidget->setHeaderLabels(headers);

        /* record root */
        cc_file_dir_t = dirinfo_t;
        /* display */
        cc_file_dir_display(dirinfo_t,qTreeWidget);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_seek()
****************************************************************************************************/
cc_result cc_file_dir_seek(cc_file_dir_struct **dirinfo_t,cc_file_dir_struct *dirinfo_root_t,QString name)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;
    cc_file_dir_struct *iterator;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,dirinfo_root_t);
        CHECK_LOGIC(result,(name != ""));

        /* impletement */
        iterator = dirinfo_root_t;
        while (iterator != nullptr)
        {
            /* find */
            if (iterator->name == name)
            {
                *dirinfo_t = iterator;
                result = CC_E_OK;
                break;
            }
            /* children */
            if (iterator->children != nullptr)
            {
                result = cc_file_dir_seek(dirinfo_t,iterator->children,name);
                if (result == CC_E_OK)
                {
                    break;
                }
            }
            /* next */
            if (iterator->next == nullptr)
            {
                break;
            }
            iterator = iterator->next;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_getpath()
****************************************************************************************************/
cc_result cc_file_dir_getpath(QString *path,cc_file_dir_struct *dirinfo_t,QString name)
{
    cc_result result = CC_E_NOT_OK_NOT_FIND;
    cc_file_dir_struct *iterator;

    do
    {
        /* check */
        CHECK_PTR(result,path);
        CHECK_PTR(result,dirinfo_t);
        CHECK_LOGIC(result,(name != ""));

        /* impletement */
        result = cc_file_dir_seek(&iterator,dirinfo_t,name);
        if (result != CC_E_OK)
        {
            continue;
        }
        /* get path */
        *path = iterator->path;

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_open()
****************************************************************************************************/
cc_result cc_file_dir_open(QString folderpath)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(folderpath != ""));

        /* impletement */
        /* get path */
        QString absolutePath = QDir(folderpath).absolutePath();
        CHECK_LOGIC(result, QDir(absolutePath).exists());
        /* get url */
        QUrl url = QUrl::fromLocalFile(absolutePath);
        /* open */
        QDesktopServices::openUrl(url);

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_create()
****************************************************************************************************/
cc_result cc_file_dir_create(QString directory)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(directory != ""));
        /* impletement */
        QFileInfo fileInfo(directory);
        QString dirPath = fileInfo.absolutePath();
        if(QDir().mkpath(dirPath) != CC_TRUE) 
        {
            qDebug() << "create fail" << dirPath;
            continue;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_check()
****************************************************************************************************/
cc_result cc_file_dir_check(QString directory)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(directory != ""));
        /* impletement */
        QFileInfo fileInfo(directory);
        QString dirPath = fileInfo.absolutePath();
        QDir dir(dirPath);
        if(dir.exists() != CC_TRUE)
        {
            result = CC_E_NOT_OK;
            continue;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_dir_mainfunction()
****************************************************************************************************/
cc_result cc_file_dir_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File file_dir.c End!
****************************************************************************************************/

