#include "lan2starttab.h"

QTB_LANYUI


Lan2StartTab::Lan2StartTab(QString objecetname, QWidget *parent):QToolButton(parent)

{

    this->setFixedSize(C_TabStartWidth,C_TabStartHeight);
    this->setStyleSheet(StyleSheet_DefaultStartTabBG);
    def_action=new QAction();
    this->setDefaultAction(def_action);
    connect(def_action,SIGNAL(triggered()),this,SLOT(method_starttab()));


    this->setObjectName(objecetname);
    if(this->text().isEmpty()){
          this->setText(objecetname);
    }

}

void Lan2StartTab::method_starttab()
{
    emit sig_starttab(this->objectName());
}


QTE_LANYUI
