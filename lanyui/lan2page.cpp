#include "lan2page.h"

#include <QLabel>

QTB_LANYUI

Lan2Page::Lan2Page(QString objectname, QWidget *parent)
{
     setWindowFlags(Qt::FramelessWindowHint);
    this->setObjectName("p"+objectname);
   hbox=new QHBoxLayout();
   hbox->setSpacing(6);
   hbox->setMargin(0);
   hbox->setContentsMargins(0,0,0,0);
   this->setLayout(hbox);
//   this->setStyleSheet("QFrame{border:1px solid #00ff00}");

}

void Lan2Page::addDemo(QString txt)
{
    lal=new QLabel(this);
    lal->setText(txt);

}

void Lan2Page::addToolGroup(Lan2ToolGroup *gt)
{
    hbox->addLayout(gt);
}

void Lan2Page::addSpace(int space)
{
    hbox->addSpacing(space);
}

void Lan2Page::addEndSpace()
{
    hbox->addStretch();
}


QTE_LANYUI



