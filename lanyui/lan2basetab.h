#ifndef LAN2BASETAB_H
#define LAN2BASETAB_H

#include <QToolButton>

#include "lan2global.h"
QTB_LANYUI

class Lan2BaseTab : public QToolButton
{
    Q_OBJECT
public:
    Lan2BaseTab(QString objectname="",QWidget* parent=Q_NULLPTR,int width=60,int height=35,QString bgcolor="#14af75");
};

QTE_LANYUI
#endif // LAN2BASETAB_H
