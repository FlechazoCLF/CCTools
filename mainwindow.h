
/****************************************************************************************************
* File Start!
****************************************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/****************************************************************************************************
* Include
****************************************************************************************************/
#include <QMainWindow>
#include "ccai/ccai.h"
#include "codeexample.h"
#include "collect.h"
#include "communication.h"
#include "components.h"
#include "draft.h"
#include "file.h"
#include "knowledge.h"
#include "moment.h"
#include "navigate.h"
#include "plan.h"
#include "project.h"
#include "projectcollect.h"
#include "script.h"
#include "toolcollect.h"
#include "qtimer.h"

/****************************************************************************************************
* Define
****************************************************************************************************/
/* debug */
#define MAINWINDOW_LOG_PRINT(format,...) log_print(CC_KERNEL_MODULE_MAINWINDOW,this->ui->textBrowser_sidebar_log,format,##__VA_ARGS__)
/* windows show */
#define CC_MAIN_WINDOWS_CTRL_SHOW(p,c)\
    do\
    {\
        if(p == nullptr)\
        {\
            /* new */\
            p = new c();\
            p->show();\
        }\
        else if(p->isVisible() != true)\
        {\
            p->show();\
        }\
        else if(p->isMinimized() == true)\
        {\
            p->showNormal();\
        }\
        else\
        {\
            p->raise();\
        }\
    }while(0u);

/****************************************************************************************************
* Type
****************************************************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_main_navigate_tools_tool_codeexample_clicked();
    void on_pushButton_main_navigate_tools_tool_communication_clicked();
    void on_pushButton_main_navigate_tools_tool_plan_clicked();
    void on_pushButton_main_navigate_tools_tool_components_clicked();
    void on_pushButton_main_navigate_tools_tool_file_clicked();
    void on_pushButton_main_navigate_tools_tool_knowledge_clicked();
    void on_pushButton_main_navigate_tools_tool_script_clicked();
    void on_pushButton_main_navigate_tools_tool_toolcollect_clicked();
    void on_pushButton_main_navigate_tools_tool_project_clicked();
    void on_pushButton_main_navigate_tools_tool_projectcollect_clicked();
    void on_pushButton_main_navigate_tools_tool_collecte_clicked();
    void on_pushButton_main_navigate_tools_tool_draft_clicked();
    void on_pushButton_main_navigate_tools_tool_moment_clicked();
    void on_pushButton_main_navigate_tools_tool_AI_clicked();
    void on_pushButton_main_navigate_tools_AI_config_ollama_downloadpath_clicked();
    void on_pushButton_main_navigate_tools_AI_config_ollama_installpath_clicked();
    void on_pushButton_main_navigate_tools_AI_operate_install_clicked();

private:
    Ui::MainWindow *ui;
    /* sub module */
    CodeExample *CodeExampleWindow = NULL;
    Collect *CollectWindow = NULL;
    Communication *CommunicationWindow = NULL;
    Components *ComponentsWindow = NULL;
    Draft *DraftWindow = NULL;
    File *FileWindow = NULL;
    Knowledge *KnowledgeWindow = NULL;
    Moment *MomentWindow = NULL;
    Navigate *NavigateWindow = NULL;
    Plan *PlanWindow = NULL;
    Project *ProjectWindow = NULL;
    ProjectCollect *ProjectCollectWindow = NULL;
    Script *ScriptWindow = NULL;
    ToolCollect *ToolCollectWindow = NULL;
    CCAI *CCAIWindow = NULL;

    /* kernel */
    cc_result cc_kernel_init(cc_void);
    cc_result cc_timer_init(cc_void);

    /* ccai */
    cc_result cc_ai_init(cc_void);

};
#endif // MAINWINDOW_H

/****************************************************************************************************
* File End!
****************************************************************************************************/
