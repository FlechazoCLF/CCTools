
/****************************************************************************************************
* File Start!
****************************************************************************************************/

/****************************************************************************************************
* Include
****************************************************************************************************/
/* type */
#include "toolcollect.h"
/* log */
/* sub module */
#include "toolcollect_frp.h"
#include "toolcollect_frp_cfg.h"
/* components */
#include "cctools_cfg.h"

/* ui */
#include "ui_toolcollect.h"
/* cpp */
#include <QFileDialog>

/****************************************************************************************************
* Variable
****************************************************************************************************/
cc_toolcollect_struct cc_toolcollect_t;

/****************************************************************************************************
* Function
****************************************************************************************************/

/****************************************************************************************************
* ToolCollect()
****************************************************************************************************/
ToolCollect::ToolCollect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolCollect)
{
    ui->setupUi(this);
    /* default path */
    this->ui->lineEdit_toolcollect_config_path->setText((QString)CCTOOLS_CFG_DATABASE_PATH + "/toolcollect");
    /* init frp */
    cc_toolcollect_frp_struct cc_toolcollect_frp_t;
    cc_toolcollect_frp_t.qtextbrower = this->ui->textBrowser_sidebar_log;
    this->cc_toolcollect_frp_init(&cc_toolcollect_frp_t);
    /* init log */
    cc_toolcollect_t.qtextbrower = this->ui->textBrowser_sidebar_log;
}

ToolCollect::~ToolCollect()
{
    delete ui;
}

/****************************************************************************************************
* on_pushButton_toolcollect_frp_config_path_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_frp_config_path_clicked()
{
    do
    {
        /* select path */
        QString directory = QFileDialog::getExistingDirectory(this,
                                                              tr("请选择一个目录读取内网穿透配置哦🍔"),
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
        /* check directory */
        if (directory.isEmpty())
        {
            qDebug() << "No directory selected";
            continue;
        }
        /* set path */
        qDebug() << "Selected directory:" << directory;
        /* show */
        this->ui->lineEdit_toolcollect_frp_config_path->setText(directory);
    }while(0u);
}

/****************************************************************************************************
* on_lineEdit_toolcollect_frp_config_path_textChanged()
****************************************************************************************************/
void ToolCollect::on_lineEdit_toolcollect_frp_config_path_textChanged(const QString &arg1)
{
    cc_toolcollect_frp_setpath(arg1);
}

/****************************************************************************************************
* on_pushButton_toolcollect_frp_config_read_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_frp_config_read_clicked()
{
    /* read config */
}

/****************************************************************************************************
* on_pushButton_toolcollect_frp_view_config_service_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_frp_view_config_service_clicked()
{
    if(this->ui->pushButton_toolcollect_frp_view_config_service->text() == "开始服务")
    {
        /* start service */
        cc_toolcollect_frp_cfg_service_set_serviceport(this->ui->lineEdit_toolcollect_frp_view_service_config_port->text());
        cc_toolcollect_frp_cfg_service_set_token(this->ui->lineEdit_toolcollect_frp_view_service_config_token->text());
        cc_toolcollect_frp_service_start();
        this->ui->pushButton_toolcollect_frp_view_config_service->setText("停止服务");
    }
    else
    {
        /* stop service */
        cc_toolcollect_frp_service_stop();
        this->ui->pushButton_toolcollect_frp_view_config_service->setText("开始服务");
    }
}

/****************************************************************************************************
* on_pushButton_toolcollect_frp_view_client_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_frp_view_client_clicked()
{
    if(this->ui->pushButton_toolcollect_frp_view_client->text() == "开始服务")
    {
        /* start client */
        cc_toolcollect_frp_cfg_client_set_name("frpc");
        cc_toolcollect_frp_cfg_client_set_serviceip(this->ui->lineEdit_toolcollect_frp_view_client_service_ip->text());
        cc_toolcollect_frp_cfg_client_set_serviceport(this->ui->lineEdit_toolcollect_frp_view_client_service_port->text());
        cc_toolcollect_frp_cfg_client_set_token(this->ui->lineEdit_toolcollect_frp_view_client_config_token->text());
        cc_toolcollect_frp_cfg_item_struct item;
        item.item = "\
[[proxies]]\n\
name = \"{clientitem_name}\"\n\
type = \"{clientitem_type}\"\n\
localIP = \"{clientitem_localip}\"\n\
localPort = {clientitem_localport}\n\
remotePort = {clientitem_remoteport}\n";
        item.itemtype = CC_TOOLCOLLECT_FRP_CFG_ITEM_TYPE_TCP;
        item.name = this->ui->lineEdit_toolcollect_frp_view_client_config_name->text();
        item.type = this->ui->comboBox_toolcollect_frp_view_client_config_type->currentText();
        item.localip = this->ui->lineEdit_toolcollect_frp_view_client_config_localip->text();
        item.localport = this->ui->lineEdit_toolcollect_frp_view_client_config_localport->text();
        item.remoteport = this->ui->lineEdit_toolcollect_frp_view_client_config_remoteport->text();
        item.customDomains = "";
        item.subdomain = "";
        cc_toolcollect_frp_cfg_client_item_set(0,&item);
        cc_toolcollect_frp_client_start();
        this->ui->pushButton_toolcollect_frp_view_client->setText("停止服务");
    }
    else
    {
        /* stop service */
        cc_toolcollect_frp_client_stop();
        this->ui->pushButton_toolcollect_frp_view_client->setText("开始服务");
    }
}

/****************************************************************************************************
* on_pushButton_toolcollect_web_path_open_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_web_path_open_clicked()
{

}

/****************************************************************************************************
* on_pushButton_toolcollect_web_path_read_clicked()
****************************************************************************************************/
void ToolCollect::on_pushButton_toolcollect_web_path_read_clicked()
{

}

/****************************************************************************************************
* cc_toolcollect_mainfunction()
****************************************************************************************************/
cc_result cc_toolcollect_mainfunction(cc_void)
{
    cc_result result = CC_E_OK;

    do
    {

    }while(0u);

    return result;
}

/****************************************************************************************************
* File End!
****************************************************************************************************/
