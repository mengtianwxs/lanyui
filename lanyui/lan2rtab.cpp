#include "lan2rtab.h"
QTB_LANYUI

Lan2RTab::Lan2RTab(QString objectname,QWidget* parent,int width,int height,QString bgcolor):
    QToolButton (parent)
{

    this->setFixedSize(width,height);
    this->setStyleSheet("QToolButton{padding-top:-1px;background:"+bgcolor+";color:#ffffff;border:none;}QToolButton:hover{background:#00a06e;}");
    def_action=new QAction();
    this->setDefaultAction(def_action);
    connect(def_action,SIGNAL(triggered()),this,SLOT(method_rtab()));

    if(objectname!=""){
        this->setObjectName(objectname);
    }
   //一般设置成图片不需要有文字信息显示


}

void Lan2RTab::setInitIcon(QString url)
{
    this->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->setIcon(QIcon(url));
    this->setIconSize(QSize(C_TabRWidth,C_TabRHeight));

}

void Lan2RTab::settext(QString text)
{

    this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    def_action->setText(text);
}


void Lan2RTab::method_rtab()
{
    if(objectName()!=""){
        emit sig_rtab(this->objectName());
    }

}

QTE_LANYUI
