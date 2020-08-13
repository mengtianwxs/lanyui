#include "lan2tab.h"



QTB_LANYUI

Lan2Tab::Lan2Tab(QString objectname,QWidget* parent,int width,int height,QString bgcolor):
    QToolButton (parent)
{

    this->setObjectName(objectname);
    this->setFixedSize(width,height);
    this->setStyleSheet("QToolButton{background:"+bgcolor+";color:#ffffff;border:none;}QPushButton::hover{background:#00a06e;}");

    this->setToolButtonStyle(Qt::ToolButtonTextOnly);

    default_action=new QAction();
    connect(default_action,SIGNAL(triggered()),this,SLOT(method_click()));
    this->setDefaultAction(default_action);






}

Lan2Tab::~Lan2Tab()
{


}




void Lan2Tab::method_click()
{
    if(objectName()!=""){
        emit sig_tab(this->objectName());
    }


}
QTE_LANYUI
