
/****************************************************************************************************
* File file_md_cfg.c Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "file_md_cfg.h"
/* log */
/* sub module */
/* components */

/* ui */
/* cpp */
#include <QRegularExpression>

/****************************************************************************************************
* Define
****************************************************************************************************/

/****************************************************************************************************
* Type
****************************************************************************************************/

/****************************************************************************************************
* Global Variable
****************************************************************************************************/

/* init flag */
cc_boolean cc_file_md_cfg_initflag = CC_FALSE;
/* default content */
QString cc_file_md_cfg_defaultcontent = "\
---\n\
title: {file_title}\n\
Date: {file_date}\n\
Author: flechazo\n\
Description:\n\
---\n\
\n\
\n\
# 缘起\n\
\n\
flechazo\n\
\n\
# 计划\n\
\n\
## 整体规划\n\
\n\
\n\
\n\
## 代码路径\n\
\n\
```\n\
local path\n\
```\n\
\n\
## 代码仓库\n\
\n\
```\n\
git url\n\
```\n\
\n\
# 任务列表\n\
\n\
- [ ] 摸鱼学习\n\
";

/****************************************************************************************************
* Function Impletement
****************************************************************************************************/

/****************************************************************************************************
* cc_file_md_cfg_init()
****************************************************************************************************/
cc_result cc_file_md_cfg_init(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {
        /* init object */

        /* register object */


        /* init file_md_cfg */


        /* init service */

        /* register service */


        /* start service */

    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_cfg_content()
****************************************************************************************************/
cc_result cc_file_md_cfg_content(QString *content)
{
    cc_result result = CC_E_OK;

    do
    {
        /* check */
        CHECK_PTR(result,content);
        /* output */
        *content = cc_file_md_cfg_defaultcontent;
    }while(0u);

    return result;
}

/****************************************************************************************************
* cc_file_md_cfg_parse()
****************************************************************************************************/
cc_result cc_file_md_cfg_parse(QString *dstcontent,QString srccontent)
{
    cc_result result = CC_E_OK;
    QString html;
    QStringList lines;

    do
    {
        /* check */
        CHECK_PTR(result,dstcontent);
        /* parse */
        lines = srccontent.split("\n");
        for (QString &line : lines)
        {
            /* title */
            if (line.startsWith("# ")) {
                html += "<h1>" + line.mid(2) + "</h1>";
            } else if (line.startsWith("## ")) {
                html += "<h2>" + line.mid(3) + "</h2>";
            } else if (line.startsWith("### ")) {
                html += "<h3>" + line.mid(4) + "</h3>";
            } else if (line.startsWith("#### ")) {
                html += "<h4>" + line.mid(5) + "</h4>";
            } else if (line.startsWith("##### ")) {
                html += "<h5>" + line.mid(6) + "</h5>";
            } else if (line.startsWith("###### ")) {
                html += "<h6>" + line.mid(7) + "</h6>";
            }

            /* unordered list */
            else if (line.startsWith("- ")) {
                html += "<ul><li>" + line.mid(2) + "</li></ul>";
            }

            /* ordered list */
            else if (line.startsWith("1. ") || line.startsWith("2. ") || line.startsWith("3. ")) {
                html += "<ol><li>" + line.mid(3) + "</li></ol>";
            }

            /* bold */
            else if (line.contains("**") || line.contains("__")) {
                line.replace(QRegularExpression("\\*\\*(.*?)\\*\\*"), "<b>\\1</b>");
                line.replace(QRegularExpression("__(.*?)__"), "<b>\\1</b>");
                html += "<p>" + line + "</p>";
            }

            /* italic */
            else if (line.contains("*") || line.contains("_")) {
                line.replace(QRegularExpression("\\*(.*?)\\*"), "<i>\\1</i>");
                line.replace(QRegularExpression("_(.*?)_"), "<i>\\1</i>");
                html += "<p>" + line + "</p>";
            }

            /* code */
            else if (line.contains("`")) {
                line.replace(QRegularExpression("`(.*?)`"), "<code>\\1</code>");
                html += "<p>" + line + "</p>";
            }

            /* link */
            else if (line.contains("[") && line.contains("](")) {
                QRegularExpression linkRegex("\\[(.*?)\\]\\((.*?)\\)");
                QRegularExpressionMatchIterator matchIterator = linkRegex.globalMatch(line);
                while (matchIterator.hasNext()) {
                    QRegularExpressionMatch match = matchIterator.next();
                    QString linkText = match.captured(1);
                    QString linkUrl = match.captured(2);
                    line.replace(match.capturedStart(), match.capturedLength(), "<a href=\"" + linkUrl + "\">" + linkText + "</a>");
                }
                html += "<p>" + line + "</p>";
            }

            /* img */
            else if (line.contains("![")) {
                QRegularExpression imageRegex("!\\[(.*?)\\]\\((.*?)\\)");
                QRegularExpressionMatchIterator matchIterator = imageRegex.globalMatch(line);
                while (matchIterator.hasNext()) {
                    QRegularExpressionMatch match = matchIterator.next();
                    QString altText = match.captured(1);
                    QString imgUrl = match.captured(2);
                    line.replace(match.capturedStart(), match.capturedLength(), "<img src=\"" + imgUrl + "\" alt=\"" + altText + "\" />");
                }
                html += "<p>" + line + "</p>";
            }

            /* text */
            else {
                html += "<p>" + line + "</p>";
            }
        }
        /* outpur */
        *dstcontent = html;
    }while(0u);

    return result;
}


/****************************************************************************************************
* cc_file_md_cfg_mainfunction()
****************************************************************************************************/
cc_result cc_file_md_cfg_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File file_md_cfg.c End!
****************************************************************************************************/

