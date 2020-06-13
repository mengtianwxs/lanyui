#include "lan2labelgroupmenu.h"
QTB_LANYUI
Lan2LabelGroupMenu::Lan2LabelGroupMenu(int width,int height)
{
   vbox=new QVBoxLayout();
   this->setLayout(vbox);
   this->setFixedWidth(width);
   this->setFixedHeight(height);
}

void Lan2LabelGroupMenu::addHLine(Lan2HLine *line)
{

    vbox->addWidget(line);
}
QTE_LANYUI
