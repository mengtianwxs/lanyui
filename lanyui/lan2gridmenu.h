#ifndef LAN2GRIDMENU_H
#define LAN2GRIDMENU_H

#include <QGridLayout>
#include <QMenu>
#include <QObject>
#include <QAction>
#include <QToolButton>
#include <lanyui/styles/lss2base.h>
#include "lanyui/styles/lss2gridmenu.h"
#include "lan2global.h"

QTB_LANYUI
class Lan2GridMenu : public QMenu
{
public:
    Lan2GridMenu(int width=0,int height=0);
    //添加工具按钮矩阵
    void addToolButtonMat(QVector<QToolButton*> qtb,int row=1,int col=1);
    void bindActionByName(QAction &ac,QString name);
public:
    QGridLayout* grid;

};

QTE_LANYUI

#endif // LAN2GRIDMENU_H
