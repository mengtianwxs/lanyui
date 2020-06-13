#include "lan2tab.h"



QTB_LANYUI

Lan2Tab::Lan2Tab(QString objectname, QWidget *parent)
{

    this->setFixedSize(C_TabWidth,C_TabHeight);
    this->setStyleSheet("QToolButton{background:#14af75;color:#ffffff;border:none;}QPushButton::hover{background:#00a06e;}");


    default_action=new QAction();
    connect(default_action,SIGNAL(triggered()),this,SLOT(method_click()));
    this->setDefaultAction(default_action);


    this->setObjectName(objectname);
    if(this->text()==""){
        this->setText(objectname);
    }

}

Lan2Tab::~Lan2Tab()
{


}



void Lan2Tab::method_click()
{
 // qDebug()<<this->text();
  emit sig_tab(this->objectName());

}
QTE_LANYUI
