#include "lan2starttab.h"

QTB_LANYUI


Lan2StartTab::Lan2StartTab(QString objectname,QWidget* parent,int width,int height,QString bgcolor):QToolButton(parent)

{

    this->setFixedSize(width,height);
    this->setStyleSheet("QToolButton{padding-top:-1px;background:"+bgcolor+";color:#ffffff;border:none;}QToolButton:hover{background:#00a06e;}");
    def_action=new QAction();
    this->setDefaultAction(def_action);
    connect(def_action,SIGNAL(triggered()),this,SLOT(method_starttab()));
    this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    if(objectname!=""){
      this->setObjectName(objectname);
    }



}


void Lan2StartTab::method_starttab()
{
    if(objectName()!=""){
        emit sig_starttab(this->objectName());

    }
}


QTE_LANYUI
