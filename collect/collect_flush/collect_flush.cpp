
/****************************************************************************************************
* File collect_flush.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "collect_flush.h"
#include "collect_flush_cfg.h"
/* log */
/* sub module */
/* components */
#include "buttonarray.h"
#include "file_dir.h"
#include "file_md.h"

/* ui */
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
/* cpp */
#include <QPushButton>
#include <QDesktopServices>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* cc_collect_flush */
cc_collect_flush_struct cc_collect_flush_t;
/* init flag */
cc_boolean cc_collect_flush_initflag = CC_FALSE;

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_collect_flush_init()
****************************************************************************************************/
cc_result cc_collect_flush_init(cc_collect_flush_struct *cfg)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg);
        CHECK_PTR(result,cfg->qtextbrower);
        /* init */
        cc_collect_flush_t.qtextbrower = cfg->qtextbrower;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_button_getidx()
****************************************************************************************************/
cc_result cc_collect_flush_button_getidx(cc_uint32 *idx,QString name)
{
    cc_result result = CC_E_NOT_OK;

    do
    {
        /* check */
        CHECK_PTR(result,idx);
        CHECK_LOGIC(result,(name != ""));
        /* impletement */
        for (int i = 0; i < cc_collect_flush_t.infolist.count(); ++i)
        {
            if(cc_collect_flush_t.infolist[i].name == name)
            {
                *idx = i;
                result = CC_E_OK;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_buttoncreate_callback()
****************************************************************************************************/
cc_result cc_collect_flush_buttoncreate_callback(QPushButton *button,cc_uint32 idx,QString name)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,button);
        CHECK_LOGIC(result,(idx < cc_collect_flush_t.infolist.count()));
        CHECK_LOGIC(result,(name != ""));
        /* impletement */
        /* add  */
        QObject::connect(button, &QPushButton::clicked, [button]() {
            /* get idx */
            cc_uint32 idx;
            cc_collect_flush_button_getidx(&idx,button->text());
            /* get url */
            QString strurl = cc_collect_flush_t.infolist.at(idx).url;
            QUrl url(strurl);
            /* open url */
            if (QDesktopServices::openUrl(url) != CC_TRUE)
            {
                qDebug() << "open url error!" << strurl;
            }
        });
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_covertlist()
****************************************************************************************************/
cc_result cc_collect_flush_covertlist(QStringList *qstringlist,QList<cc_collect_flush_cfg_info_struct> *infolist,QString parent,cc_collect_flush_cfg_info_enum type)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,qstringlist);
        CHECK_PTR(result,infolist);
        /* convert */
        for (cc_uint32 i = 0; i < infolist->count(); i++)
        {
            /* check parent */
            CHECK_LOGIC(result,(infolist->at(i).parent == parent));
            /* take */
            switch (type)
            {
            case CC_COLLECT_FLUSH_CFG_INFO_PARENT:
                qstringlist->append(infolist->at(i).parent);
                break;
            case CC_COLLECT_FLUSH_CFG_INFO_NAME:
                qstringlist->append(infolist->at(i).name);
                break;
            case CC_COLLECT_FLUSH_CFG_INFO_URL:
                qstringlist->append(infolist->at(i).url);
                break;
            case CC_COLLECT_FLUSH_CFG_INFO_DESCRIPTION:
                qstringlist->append(infolist->at(i).description);
                break;
            default:
                break;
            }
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_display_button()
****************************************************************************************************/
cc_result cc_collect_flush_display_button(cc_file_dir_struct *dirinfo_t,QScrollArea *qscrollarea,QWidget *qwidget)
{
    cc_result result = CC_E_OK;
    QString content;
    QStringList qstringlist;
    QWidget *scrollAreaContents;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,cc_collect_flush_t.dirinfo_root_t);
        CHECK_PTR(result,qscrollarea);
        CHECK_PTR(result,qwidget);

        /* impletement */
        if (dirinfo_t->parent != cc_collect_flush_t.dirinfo_root_t)
        {
            /* deep end then create button */
            cc_collect_flush_covertlist(&qstringlist,&cc_collect_flush_t.infolist,dirinfo_t->parent->name,CC_COLLECT_FLUSH_CFG_INFO_NAME);
            CHECK_LOGIC(result,(qstringlist.count() > 0));
            /* create */
            scrollAreaContents = new QWidget(qwidget);
            cc_buttonarray_create(&qstringlist,scrollAreaContents,CC_COLLECT_FLUSH_CFG_BUTTON_ROW_NUM_MAX,cc_collect_flush_buttoncreate_callback);
            /* set widget */
            qscrollarea->setWidget(scrollAreaContents);
            qscrollarea->setMinimumHeight((qstringlist.count() / CC_COLLECT_FLUSH_CFG_BUTTON_ROW_NUM_MAX + 1) * 60);
        }
        /* clear */
        qstringlist.clear();

    }while(0u);

    return result;
}


/****************************************************************************************************
* cc_collect_flush_display_dir()
****************************************************************************************************/
cc_result cc_collect_flush_display_dir(cc_file_dir_struct *dirinfo_t,QWidget *qwidget,QScrollArea **qscrollarea)
{
    cc_result result = CC_E_OK;
    QScrollArea *newqscrollarea;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,cc_collect_flush_t.dirinfo_root_t);
        CHECK_PTR(result,qwidget);
        CHECK_PTR(result,dirinfo_t->children);

        /* get parent */
        newqscrollarea = new QScrollArea(qwidget);
        newqscrollarea->setWidgetResizable(true);
        newqscrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        /* layout */
        CHECK_PTR(result,qwidget->layout());
        qwidget->layout()->addWidget(newqscrollarea);
        *qscrollarea = newqscrollarea;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_display_file()
****************************************************************************************************/
cc_result cc_collect_flush_display_file(cc_file_dir_struct *dirinfo_t,QWidget *qwidget,QScrollArea *qscrollarea,QList<cc_collect_flush_cfg_info_struct> *infolist)
{
    cc_result result = CC_E_OK;
    QString content;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,cc_collect_flush_t.dirinfo_root_t);
        CHECK_PTR(result,qwidget);
        CHECK_PTR(result,qscrollarea);
        CHECK_PTR(result,infolist);

        /* get info */
        /* read md file */
        cc_file_md_read(&content,dirinfo_t->path);
        /* get info list */
        cc_collect_flush_cfg_get_info(dirinfo_t,infolist,content);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_display()
****************************************************************************************************/
cc_result cc_collect_flush_display(cc_file_dir_struct *dirinfo_t,QWidget *qwidget)
{
    cc_result result = CC_E_OK;
    static QList<QScrollArea *> qscrollarealist;
    QScrollArea *qscrollarea;
    cc_file_dir_struct *iterator;

    do
    {
        /* check */
        CHECK_PTR(result,dirinfo_t);
        CHECK_PTR(result,qwidget);
        /* qwidget -> v layout (group) */

        /* iterator */
        iterator = dirinfo_t->children;
        while(iterator != nullptr)
        {
            /* push base struct */
            switch (iterator->type)
            {
            case CC_FILE_DIR_TYPE_DIR:
            {
                /* find dir */
                cc_collect_flush_display_dir(iterator,qwidget,&qscrollarea);
                /* insert list */
                qscrollarealist.append(qscrollarea);
            }
            break;
            case CC_FILE_DIR_TYPE_FILE:
            {
                /* find file */
                cc_collect_flush_display_file(iterator,qwidget,qscrollarea,&cc_collect_flush_t.infolist);
            }
            break;
            default:
                break;
            }
            /* children */
            if (iterator->children != nullptr)
            {
                cc_collect_flush_display(iterator,qwidget);
            }
            /* next */
            if (iterator->next == nullptr)
            {
                if(qscrollarealist.count() > 0)
                {
                    qscrollarea = qscrollarealist.takeLast();
                    cc_collect_flush_display_button(iterator,qscrollarea,qwidget);
                }
                break;
            }
            iterator = iterator->next;
        }
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_show_layout()
****************************************************************************************************/
cc_result cc_collect_flush_show_layout(QWidget *parentqwidget,QWidget *childqwidget)
{
    cc_result result = CC_E_OK;
    QHBoxLayout *qhboxlayout = new QHBoxLayout();
    QScrollArea *newqscrollarea;

    do
    {
        /* check parameter */
        CHECK_PTR(result,parentqwidget);
        CHECK_PTR(result,childqwidget);
        /* impletement */
        parentqwidget->setLayout(qhboxlayout);
        /* get parent */
        newqscrollarea = new QScrollArea(parentqwidget);
        qhboxlayout->addWidget(newqscrollarea);
        newqscrollarea->setWidgetResizable(true);
        newqscrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        /* layout */
        newqscrollarea->setWidget(childqwidget);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_show()
****************************************************************************************************/
cc_result cc_collect_flush_show(QString directory,QWidget *qwidget)
{
    cc_result result = CC_E_OK;
    QWidget *childqwidget;
    QVBoxLayout *childqvboxlayout;
    cc_file_dir_struct dirinfo_t;

    do
    {
        /* check parameter */
        CHECK_PTR(result,qwidget);
        CHECK_LOGIC(result,(directory != ""));
        /* impletement */
        childqwidget = new QWidget(qwidget);
        childqvboxlayout = new QVBoxLayout(childqwidget);
        childqwidget->setLayout(childqvboxlayout);
        /* read dir */
        cc_file_dir_getinfo(&dirinfo_t,directory,CC_COLLECT_FLUSH_CFG_PATH_DEEP_MAX);
        /* record root */
        cc_collect_flush_t.dirinfo_root_t = &dirinfo_t;
        cc_collect_flush_t.infolist.clear();
        /* display */
        cc_collect_flush_display(&dirinfo_t,childqwidget);
        /* layout */
        cc_collect_flush_show_layout(qwidget,childqwidget);
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_collect_flush_mainfunction()
****************************************************************************************************/
cc_result cc_collect_flush_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File collect_flush.c End!
****************************************************************************************************/

