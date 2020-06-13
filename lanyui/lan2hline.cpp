#include "lan2hline.h"

QTB_LANYUI
Lan2HLine::Lan2HLine()
{
    this->setFrameShape(QFrame::HLine);
    this->setFrameShadow(QFrame::Sunken);
    this->setLineWidth(0);
    this->setFixedWidth(LEN_HLINE);
    this->setFixedWidth(1);
    this->setStyleSheet(LSS_HLINEBG);
}
QTE_LANYUI
