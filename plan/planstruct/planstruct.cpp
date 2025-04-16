
/****************************************************************************************************
* File planstruct.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
#include "planstruct.h"
#include "planstruct_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QString>
#include <QDir>

/****************************************************************************************************
* Define
****************************************************************************************************/
#define PLANSTRUCT_READDEEP_MAX (3)
/****************************************************************************************************
* Type Define
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* directory deep */
cc_uint8 planstruct_readdeep = 0;

/* planstruct */
planstruct_struct planstruct_t;

/* init */
planstruct_init_struct planstruct_init_t;

/* init flag */
cc_boolean planstruct_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* plan_struct_init()
****************************************************************************************************/
cc_result plan_struct_init(planstruct_init_struct *planstruct_init_cfg)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag != CC_TRUE));
        CHECK_PTR(result,planstruct_init_cfg);
        CHECK_LOGIC(result,(planstruct_init_cfg->directory != ""));
        CHECK_PTR(result,planstruct_init_cfg->qTreeWidget);
        /* check directory */
        QDir dir(planstruct_init_cfg->directory);
        CHECK_LOGIC(result,dir.exists());

        /* hold config */
        planstruct_init_t.directory = planstruct_init_cfg->directory;
        planstruct_init_t.qTreeWidget = planstruct_init_cfg->qTreeWidget;
        /* init */
        planstruct_readdeep = 0;
        /* init root */
        planstruct_t.parent = nullptr;
        planstruct_t.type = PLANSTRUCT_TYPE_CLASS;
        planstruct_t.path = planstruct_init_t.directory;
        planstruct_t.name = planstruct_init_t.directory.split("/").last();
        planstruct_t.next = nullptr;
        planstruct_t.children = nullptr;
        /* init ui */
        QStringList headers;
        plantruct_cfg_struct *plantruct_cfg;
        CHECK_FUNC(result,plan_struct_cfg_get(&plantruct_cfg));
        planstruct_init_t.qTreeWidget->setColumnCount(PLANSTRUCT_CFG_TABLE_COLUMN_NUM);
        for (int i = 0; i < PLANSTRUCT_CFG_TABLE_COLUMN_NUM; ++i)
        {
            headers << plantruct_cfg[i].name;
        }
        planstruct_init_t.qTreeWidget->setHeaderLabels(headers);

        /* init flag */
        planstruct_initflag = CC_TRUE;
    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_getroot()
****************************************************************************************************/
planstruct_struct *plan_struct_getroot(cc_void)
{
    return &planstruct_t;
}

/****************************************************************************************************
* plan_struct_getinitcfg()
****************************************************************************************************/
planstruct_init_struct *plan_struct_getinitcfg(cc_void)
{
    return &planstruct_init_t;
}

/****************************************************************************************************
* plan_struct_insertchild()
****************************************************************************************************/
cc_result plan_struct_insertchild(planstruct_struct *planstruct,planstruct_struct *child_planstruct)
{
    cc_result result = CC_E_OK;
    planstruct_struct **iterator;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_PTR(result,planstruct);
        CHECK_PTR(result,child_planstruct);
        /* firt child */
        if(planstruct->children == nullptr)
        {
            planstruct->children = child_planstruct;
        }
        else
        {
            /* iterator */
            iterator = &planstruct->children;
            while(((*iterator) != nullptr) && ((*iterator)->next != nullptr))
            {
                iterator = &(*iterator)->next;
            }
            /* insert */
            (*iterator)->next = child_planstruct;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_read()
****************************************************************************************************/
cc_result plan_struct_read(QString directory,planstruct_struct *planstruct)
{
    cc_result result = CC_E_OK;
    QDir dir(directory);

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_LOGIC(result,(directory != ""));
        CHECK_LOGIC(result,dir.exists());
        CHECK_LOGIC(result,planstruct_readdeep < PLANSTRUCT_READDEEP_MAX);

        /* clear */
        planstruct->children = nullptr;
        planstruct->next = nullptr;

        /* iterator read directory & file */
        QFileInfoList infolist = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
        for (const QFileInfo &info : infolist)
        {
            planstruct_struct *new_planstruct = new planstruct_struct;
            new_planstruct->parent = planstruct;
            new_planstruct->type = PLANSTRUCT_TYPE_CLASS;
            new_planstruct->path = directory + "/" + info.fileName();
            new_planstruct->name = info.fileName();
            new_planstruct->next = nullptr;
            new_planstruct->children = nullptr;
            /* insert child */
            plan_struct_insertchild(planstruct,new_planstruct);
            if(info.isDir())
            {
                /* is dir */
                /* type */
                new_planstruct->type = PLANSTRUCT_TYPE_CLASS;
                /* into */
                planstruct_readdeep++;
                plan_struct_read(info.filePath(),new_planstruct);
                planstruct_readdeep = 0;
            }
            else if(info.isFile())
            {
                /* is file */
                new_planstruct->type = PLANSTRUCT_TYPE_ITEM;
            }
            else
            {

            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_qtreewidgetitem_get()
****************************************************************************************************/
cc_result plan_struct_qtreewidgetitem_get(QTreeWidgetItem **item,QString name)
{
    cc_result result = CC_E_NOT_OK;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_LOGIC(result,(name != ""));

        /* find item */
        for (QTreeWidgetItemIterator it(planstruct_init_t.qTreeWidget); *it; ++it)
        {
            *item = *it;
            if((*item)->text(1) == name)
            {
                result = CC_E_OK;
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_push_class()
****************************************************************************************************/
cc_result plan_struct_push_class(planstruct_struct *planstruct)
{
    cc_result result = CC_E_OK;
    QTreeWidgetItem *itemparent;
    QTreeWidgetItem *item;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_PTR(result,planstruct);

        /* get parent */
        if((planstruct->parent == nullptr) || \
           (planstruct->parent->name == planstruct_t.name))
        {
            itemparent = new QTreeWidgetItem(planstruct_init_t.qTreeWidget);
            item = itemparent;
        }
        else
        {
            CHECK_FUNC(result,plan_struct_qtreewidgetitem_get(&itemparent,planstruct->parent->name));
            /* create new item */
            item = new QTreeWidgetItem(itemparent);
        }
        item->setText(PLANSTRUCT_CFG_INFOINDEX_NUM,QString::number(itemparent->childCount()));
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PROJECT,planstruct->name);
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PROGRESS,"0%");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_STARTTIME,"2025");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_ENDTIME,"2025");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PATH,planstruct->path);
        item->setText(PLANSTRUCT_CFG_INFOINDEX_COMMENT,"");
    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_push_item()
****************************************************************************************************/
cc_result plan_struct_push_item(planstruct_struct *planstruct)
{
    cc_result result = CC_E_OK;
    QTreeWidgetItem *itemparent;
    QTreeWidgetItem *item;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_PTR(result,planstruct);

        /* get parent */
        if((planstruct->parent == nullptr) || \
            (planstruct->parent->name == planstruct_t.name))
        {
            itemparent = new QTreeWidgetItem(planstruct_init_t.qTreeWidget);
            item = itemparent;
        }
        else
        {
            CHECK_FUNC(result,plan_struct_qtreewidgetitem_get(&itemparent,planstruct->parent->name));
            /* create new item */
            item = new QTreeWidgetItem(itemparent);
        }
        item->setText(PLANSTRUCT_CFG_INFOINDEX_NUM,QString::number(itemparent->childCount()));
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PROJECT,planstruct->name);
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PROGRESS,"0%");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_STARTTIME,"2025");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_ENDTIME,"2025");
        item->setText(PLANSTRUCT_CFG_INFOINDEX_PATH,planstruct->path);
        item->setText(PLANSTRUCT_CFG_INFOINDEX_COMMENT,"");

    }while(0u);

    return result;
}

/****************************************************************************************************
* plan_struct_push()
****************************************************************************************************/
cc_result plan_struct_push(planstruct_struct *planstruct)
{
    cc_result result = CC_E_OK;
    planstruct_struct *iterator;

    do
    {
        /* check */
        CHECK_LOGIC(result,(planstruct_initflag == CC_TRUE));
        CHECK_PTR(result,planstruct);

        /* iterator */
        iterator = planstruct->children;
        while(iterator != nullptr)
        {
            /* push base struct */
            switch (iterator->type)
            {
            case PLANSTRUCT_TYPE_CLASS:
                {
                    plan_struct_push_class(iterator);
                }
                break;
            case PLANSTRUCT_TYPE_ITEM:
                {
                    plan_struct_push_item(iterator);
                }
                break;
            default:
                break;
            }
            /* children */
            if (iterator->children != nullptr)
            {
                plan_struct_push(iterator);
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
* cc_plan_struct_mainfunction()
****************************************************************************************************/
cc_result cc_plan_struct_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File planstruct.c End!
****************************************************************************************************/

