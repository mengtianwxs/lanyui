#include "lan2vmenu.h"

Lan2vmenu::Lan2vmenu(QWidget *parent) : QFrame (parent)
{
vbox=new QVBoxLayout();
vbox->setSpacing(0);
vbox->setMargin(0);
vbox->setContentsMargins(0,0,0,0);
this->setLayout(vbox);
lal1=new QLabel("aabb");
lal2=new QLabel("dd32");
vbox->addWidget(lal1);
vbox->addWidget(lal2);
this->setFixedWidth(100);
this->setStyleSheet("background:#ffeecc");

}
