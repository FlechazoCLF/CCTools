
/****************************************************************************************************
* Start File
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "project_codestruct_cfg.h"
#include "project.h"
/* log */
/* sub module */
/* components */

/* ui */
#include "ui_project.h"
/* cpp */
#include <QDateTime>

/****************************************************************************************************
* Variable
****************************************************************************************************/

/* cc_project_codestruct_cfg_t */
cc_project_codestruct_cfg_struct cc_project_codestruct_cfg_t =
{
    .codetype = "C",
    .filetype = "覆盖原文件",
    .codefilltype = "填充基本代码框架",
    .doctype = "添加说明文档",
};

QString cc_project_codestruct_cfg_content_c = "\n\
/****************************************************************************************************\n\
* File {file_name}{file_postfix} Start!\n\
****************************************************************************************************/\n\
\n\
/*\n\
 *\n\
 *  Copyright (c) 2024-2025 by flechazo. All rights reserved.\n\
 *\n\
 * Author : CarlChai LinFeng Chai flechazo\n\
 * Website: flechazo.mba\n\
 *\n\
 * Change Logs:\n\
 * Date           Author       Notes\n\
 * {file_date}     cc          the first version\n\
 *\n\
*/\n\
\n\
/****************************************************************************************************\n\
* Include\n\
****************************************************************************************************/\n\
/* type */\n\
#include \"{file_name}.h\"\n\
/* log */\n\
/* sub module */\n\
/* components */\n\
\n\
/* ui */\n\
/* cpp */\n\
\n\
/****************************************************************************************************\n\
* Define\n\
****************************************************************************************************/\n\
\n\
/****************************************************************************************************\n\
* Type\n\
****************************************************************************************************/\n\
\n\
/****************************************************************************************************\n\
* Global Variable\n\
****************************************************************************************************/\n\
\n\
/* cc_{file_name} */\n\
cc_{file_name}_struct cc_{file_name}_t;\n\
/* init flag */\n\
cc_boolean cc_{file_name}_initflag = CC_FALSE;\n\
\n\
/****************************************************************************************************\n\
* Function Impletement\n\
****************************************************************************************************/\n\
\n\
/****************************************************************************************************\n\
* cc_{file_name}_init()\n\
****************************************************************************************************/\n\
cc_result cc_{file_name}_init(cc_void)\n\
{\n\
    cc_result result = CC_E_OK;\n\
\n\
    do\n\
    {\n\
        /* check */\n\
        CHECK_PTR(result,CC_NULL_PTR);\n\
        /* init object */\n\
\n\
        /* register object */\n\
\n\
\n\
        /* init {file_name} */\n\
\n\
\n\
        /* init service */\n\
\n\
        /* register service */\n\
\n\
\n\
        /* start service */\n\
\n\
    }while(0u);\n\
\n\
    return result;\n\
}\n\
\n\
\n\
/****************************************************************************************************\n\
* cc_{file_name}_mainfunction()\n\
****************************************************************************************************/\n\
cc_result cc_{file_name}_mainfunction(cc_void)\n\
{\n\
    cc_result result = CC_E_OK;\n\
\n\
    do\n\
    {\n\
\n\
    }while(0u);\n\
\n\
    return result;\n\
}\n\
\n\
/****************************************************************************************************\n\
* File {file_name}{file_postfix} End!\n\
****************************************************************************************************/\n\
\n";

QString cc_project_codestruct_cfg_content_h = "\n\
/****************************************************************************************************\n\
* File {file_name}{file_postfix} Start!\n\
****************************************************************************************************/\n\
\n\
#ifndef _{file_name_uppercase}_H\n\
#define _{file_name_uppercase}_H\n\
\n\
/****************************************************************************************************\n\
* Include\n\
****************************************************************************************************/\n\
/* type */\n\
#include \"cc_type.h\"\n\
/* log */\n\
/* sub module */\n\
/* components */\n\
\n\
/* ui */\n\
/* cpp */\n\
\n\
/****************************************************************************************************\n\
* Define\n\
****************************************************************************************************/\n\
\n\
/****************************************************************************************************\n\
* Type\n\
****************************************************************************************************/\n\
\n\
/* cc_{file_name} */\n\
typedef struct\n\
{\n\
    cc_uint8 id;\n\
}cc_{file_name}_struct;\n\
\n\
/****************************************************************************************************\n\
* Global Variable\n\
****************************************************************************************************/\n\
\n\
/****************************************************************************************************\n\
* Function\n\
****************************************************************************************************/\n\
\n\
cc_result cc_{file_name}_init(cc_void);\n\
cc_result cc_{file_name}_mainfunction(cc_void);\n\
\n\
#endif /* _{file_name_uppercase}_H */\n\
/****************************************************************************************************\n\
* File {file_name}{file_postfix} End!\n\
****************************************************************************************************/\n\
\n";
QString cc_project_codestruct_cfg_content_cpp = "";
QString cc_project_codestruct_cfg_content_python = "";
QString cc_project_codestruct_cfg_content_java = "";
QString cc_project_codestruct_cfg_content_typescript = "";
QString cc_project_codestruct_cfg_content_javascript = "";
QString cc_project_codestruct_cfg_content_html = "";

cc_project_codestruct_filetypemap_struct cc_project_codestruct_filetypemap_t[CC_PROJECT_CODESTRUCT_FILETYPE_END] =
{
    {CC_PROJECT_CODESTRUCT_FILETYPE_C,         ".c",    "C",         &cc_project_codestruct_cfg_content_c},
    {CC_PROJECT_CODESTRUCT_FILETYPE_H,         ".h",    "H",         &cc_project_codestruct_cfg_content_h},
    {CC_PROJECT_CODESTRUCT_FILETYPE_CPP,       ".cpp",  "C++",       &cc_project_codestruct_cfg_content_cpp},
    {CC_PROJECT_CODESTRUCT_FILETYPE_PYTHON,    ".py",   "Python",    &cc_project_codestruct_cfg_content_python},
    {CC_PROJECT_CODESTRUCT_FILETYPE_JAVA,      ".java", "Java",      &cc_project_codestruct_cfg_content_java},
    {CC_PROJECT_CODESTRUCT_FILETYPE_TYPESCRIPT,".ts",   "TypeScript",&cc_project_codestruct_cfg_content_typescript},
    {CC_PROJECT_CODESTRUCT_FILETYPE_JAVASCRIPT,".js",   "JavaScript",&cc_project_codestruct_cfg_content_javascript},
    {CC_PROJECT_CODESTRUCT_FILETYPE_HTML,      ".html", "HTML",      &cc_project_codestruct_cfg_content_html},
};

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* cc_project_codestruct_cfg_init()
****************************************************************************************************/
cc_result cc_project_codestruct_cfg_init(cc_project_codestruct_cfg_struct *cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        /* impletement */
        cc_project_codestruct_cfg_t.codetype = (cfg_t->codetype == "") ? cc_project_codestruct_cfg_t.codetype : cfg_t->codetype ;
        cc_project_codestruct_cfg_t.filetype = (cfg_t->filetype == "") ? cc_project_codestruct_cfg_t.filetype : cfg_t->filetype ;
        cc_project_codestruct_cfg_t.codefilltype = (cfg_t->codefilltype == "") ? cc_project_codestruct_cfg_t.codefilltype : cfg_t->codefilltype ;
        cc_project_codestruct_cfg_t.doctype = (cfg_t->doctype == "") ? cc_project_codestruct_cfg_t.doctype : cfg_t->doctype ;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_project_codestruct_cfg_getcfg()
****************************************************************************************************/
cc_result cc_project_codestruct_cfg_getcfg(cc_project_codestruct_cfg_struct **cfg_t)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,cfg_t);
        /* impletement */
        *cfg_t = &cc_project_codestruct_cfg_t;
    }while(0u);

    return result;
}

/****************************************************************************************************
* project_codestruct_cfg_getpostfix()
****************************************************************************************************/
QString cc_project_codestruct_cfg_getpostfix(cc_project_codestruct_filetype_enum type)
{
    QString postfix = ".txt";
    cc_uint16 i;

    for (i = 0; i < CC_PROJECT_CODESTRUCT_FILETYPE_END; ++i)
    {
        if(cc_project_codestruct_filetypemap_t[i].type != type)
        {
            continue;
        }
        /* get postfix */
        postfix = QString(cc_project_codestruct_filetypemap_t[i].postfix);
    }

    return postfix;
}

/****************************************************************************************************
* cc_project_codestruct_getfiletype()
****************************************************************************************************/
cc_project_codestruct_filetype_enum cc_project_codestruct_getfiletype(QString filetype)
{
    cc_project_codestruct_filetype_enum type = CC_PROJECT_CODESTRUCT_FILETYPE_C;
    cc_uint16 i;

    for (i = 0; i < CC_PROJECT_CODESTRUCT_FILETYPE_END; ++i)
    {
        if(cc_project_codestruct_filetypemap_t[i].comboBoxValue != filetype)
        {
            continue;
        }
        /* get postfix */
        type = cc_project_codestruct_filetypemap_t[i].type;
    }
    return type;
}

/****************************************************************************************************
* cc_project_codestruct_cfg_content()
****************************************************************************************************/
QString cc_project_codestruct_cfg_content(cc_project_codestruct_filetype_enum type,QString fileName)
{
    QString content;
    cc_uint16 i;

    for (i = 0; i < CC_PROJECT_CODESTRUCT_FILETYPE_END; ++i)
    {
        if(cc_project_codestruct_filetypemap_t[i].type != type)
        {
            continue;
        }
        /* get postfix */
        content = *cc_project_codestruct_filetypemap_t[i].content;
        /* process content */
        content.replace("{file_name}",fileName);
        content.replace("{file_name_uppercase}",fileName.toUpper());
        content.replace("{file_postfix}",cc_project_codestruct_cfg_getpostfix(type));
        content.replace("{file_date}",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    }
    return content;
}

/****************************************************************************************************
* End File
****************************************************************************************************/
