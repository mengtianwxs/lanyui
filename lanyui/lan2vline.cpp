#include "lan2vline.h"
QTB_LANYUI
Lan2VLine::Lan2VLine()
{
    this->setFrameShape(QFrame::VLine);
    this->setFrameShadow(QFrame::Sunken);
    this->setLineWidth(0);
    this->setFixedHeight(C_PageHeight-20);
    this->setFixedWidth(1);
    this->setStyleSheet(LSS_VLINEBG);
}
QTE_LANYUI
