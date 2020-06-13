#ifndef LAN2LABELGROUPMENU_H
#define LAN2LABELGROUPMENU_H

#include "lan2hline.h"

#include <QFrame>
#include <QLabel>
#include <QMenu>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include"lan2global.h"

QTB_LANYUI

class Lan2LabelGroupMenu : public QFrame
{
public:
    Lan2LabelGroupMenu(int width,int height);

public:
    QVBoxLayout* vbox;
public:
    void addHLine(Lan2HLine* line);
    void addLabelMenu(QLabel* lal,QMenu* menu);


};

QTE_LANYUI

#endif // LAN2LABELGROUPMENU_H
