
/****************************************************************************************************
* Include
****************************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "kernel.h"

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* MainWindow
****************************************************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* kernel init */
    cc_kernel_init();
    /* ai init */
    cc_ai_init();
    /* ui */
    /* create window */
    CodeExampleWindow = new CodeExample();
    CollectWindow = new Collect();
    CommunicationWindow = new Communication();
    ComponentsWindow = new Components();
    DraftWindow = new Draft();
    FileWindow = new File();
    KnowledgeWindow = new Knowledge();
    MomentWindow = new Moment();
    PlanWindow = new Plan();
    ProjectWindow = new Project();
    ProjectCollectWindow = new ProjectCollect();
    ScriptWindow = new Script();
    ToolCollectWindow = new ToolCollect();
    CCAIWindow = new CCAI();

    /* no use */
    NavigateWindow = new Navigate();

    /* log */
    MAINWINDOW_LOG_PRINT("Init Complete!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/****************************************************************************************************
* CodeExample
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_codeexample_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(CodeExampleWindow,CodeExample);
    /* log */
    MAINWINDOW_LOG_PRINT("Click CodeExample!");
}

/****************************************************************************************************
* Collect
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_collecte_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(CollectWindow,Collect);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Collect!");
}

/****************************************************************************************************
*  Communication
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_communication_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(CommunicationWindow,Communication);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Communication!");
}

/****************************************************************************************************
* Components
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_components_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(ComponentsWindow,Components);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Components!");
}

/****************************************************************************************************
* Draft
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_draft_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(DraftWindow,Draft);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Draft!");
}

/****************************************************************************************************
* File
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_file_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(FileWindow,File);
    /* log */
    MAINWINDOW_LOG_PRINT("Click File!");
}

/****************************************************************************************************
* Knowledge
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_knowledge_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(KnowledgeWindow,Knowledge);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Knowledge!");
}

/****************************************************************************************************
* Moment
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_moment_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(MomentWindow,Moment);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Moment!");
}

/****************************************************************************************************
* Plan
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_plan_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(PlanWindow,Plan);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Plan!");
}

/****************************************************************************************************
* Project
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_project_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(ProjectWindow,Project);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Project!");
}

/****************************************************************************************************
* ProjectCollect
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_projectcollect_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(ProjectCollectWindow,ProjectCollect);
    /* log */
    MAINWINDOW_LOG_PRINT("Click ProjectCollect!");
}

/****************************************************************************************************
* Script
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_script_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(ScriptWindow,Script);
    /* log */
    MAINWINDOW_LOG_PRINT("Click Script!");
}

/****************************************************************************************************
* ToolCollect
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_toolcollect_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(ToolCollectWindow,ToolCollect);
    /* log */
    MAINWINDOW_LOG_PRINT("Click ToolCollect!");
}

/****************************************************************************************************
* AI
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_tool_AI_clicked()
{
    /* show */
    CC_MAIN_WINDOWS_CTRL_SHOW(CCAIWindow,CCAI);
    /* log */
    MAINWINDOW_LOG_PRINT("Click CCAI!");
}

/****************************************************************************************************
* cc_ai_init
****************************************************************************************************/
cc_result MainWindow::cc_ai_init(cc_void)
{
    cc_result result = CC_E_OK;
    cc_ccai_struct cc_ccai_t;
    cc_ccai_t.ollama_cfg_t.qLineEdit_download = this->ui->lineEdit_main_navigate_tools_AI_config_ollama_downloadpath;
    cc_ccai_t.ollama_cfg_t.qLineEdit_install = this->ui->lineEdit_main_navigate_tools_AI_config_ollama_installpath;
    cc_ccai_t.ollama_cfg_t.qComboBox_model = this->ui->comboBox_main_navigate_tools_AI_config_ollama_selectmodel;
    cc_ccai_init(&cc_ccai_t);
    return result;
}

/****************************************************************************************************
* on_pushButton_main_navigate_tools_AI_config_ollama_downloadpath_clicked
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_AI_config_ollama_downloadpath_clicked()
{
    /* ollama download path */
    cc_ccai_ollama_downloadpath_select(this->ui->lineEdit_main_navigate_tools_AI_config_ollama_downloadpath);
    /* log */
    MAINWINDOW_LOG_PRINT("select ollama download path!");
}

/****************************************************************************************************
* on_pushButton_main_navigate_tools_AI_config_ollama_installpath_clicked
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_AI_config_ollama_installpath_clicked()
{
    /* ollama install path */
    cc_ccai_ollama_installpath_select(this->ui->lineEdit_main_navigate_tools_AI_config_ollama_installpath);
    /* log */
    MAINWINDOW_LOG_PRINT("select ollama install path!");
}

/****************************************************************************************************
* on_pushButton_main_navigate_tools_AI_operate_install_clicked
****************************************************************************************************/
void MainWindow::on_pushButton_main_navigate_tools_AI_operate_install_clicked()
{
    /* install */
    cc_ccai_install();
    /* log */
    MAINWINDOW_LOG_PRINT("Click CCAI install!");
}

/****************************************************************************************************
* Other
****************************************************************************************************/



/****************************************************************************************************
* File End!
****************************************************************************************************/




