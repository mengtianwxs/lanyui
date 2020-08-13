#include "lan2basetab.h"

QTB_LANYUI
Lan2BaseTab::Lan2BaseTab(QString objectname, QWidget *parent, int width, int height, QString bgcolor)
{
    this->setObjectName(objectname);
    this->setFixedSize(width,height);
    this->setStyleSheet("QToolButton{background:"+bgcolor+";color:#ffffff;border:none;}QPushButton::hover{background:#00a06e;}");
    this->setToolButtonStyle(Qt::ToolButtonTextOnly);
}
QTE_LANYUI
