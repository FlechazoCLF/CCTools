
/****************************************************************************************************
* Start File
****************************************************************************************************/

#ifndef _PROJECT_CODESTRUCT_CFG_H
#define _PROJECT_CODESTRUCT_CFG_H
/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "cc_type.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QString>

/****************************************************************************************************
* Type
****************************************************************************************************/

/* file type */
typedef enum
{
    CC_PROJECT_CODESTRUCT_FILETYPE_C = 0,
    CC_PROJECT_CODESTRUCT_FILETYPE_H,
    CC_PROJECT_CODESTRUCT_FILETYPE_CPP,
    CC_PROJECT_CODESTRUCT_FILETYPE_PYTHON,
    CC_PROJECT_CODESTRUCT_FILETYPE_JAVA,
    CC_PROJECT_CODESTRUCT_FILETYPE_TYPESCRIPT,
    CC_PROJECT_CODESTRUCT_FILETYPE_JAVASCRIPT,
    CC_PROJECT_CODESTRUCT_FILETYPE_HTML,
    CC_PROJECT_CODESTRUCT_FILETYPE_END
}cc_project_codestruct_filetype_enum;
/* file type map */
typedef struct
{
    cc_project_codestruct_filetype_enum type;
    cc_int8 postfix[CC_NAME_MAX_LEN];
    QString comboBoxValue;
    QString *content;
}cc_project_codestruct_filetypemap_struct;

/* cc_project_codestruct_cfg_struct */
typedef struct
{
    QString codetype;
    QString filetype;
    QString codefilltype;
    QString doctype;
}cc_project_codestruct_cfg_struct;

/****************************************************************************************************
* Variable
****************************************************************************************************/

/****************************************************************************************************
* Function
****************************************************************************************************/
cc_result cc_project_codestruct_cfg_init(cc_project_codestruct_cfg_struct *cfg_t);
cc_result cc_project_codestruct_cfg_getcfg(cc_project_codestruct_cfg_struct **cfg_t);
cc_project_codestruct_filetype_enum cc_project_codestruct_getfiletype(QString filename);
QString cc_project_codestruct_cfg_getpostfix(cc_project_codestruct_filetype_enum type);
QString cc_project_codestruct_cfg_content(cc_project_codestruct_filetype_enum type,QString fileName);

#endif /* _PROJECT_CODESTRUCT_CFG_H */
/****************************************************************************************************
* End File
****************************************************************************************************/
