#ifndef LAN2MOVE_H
#define LAN2MOVE_H

#include <QPropertyAnimation>
#include<QWidget>
#include "lan2global.h"
QTB_LANYUI


class Lan2Move
{
public:
    Lan2Move();
    static void to(QObject *target,int duration_sec=0,int x=0,int y=0,QEasingCurve ec=QEasingCurve::Linear );
    static void to2(QObject *target1,QObject* target2,int duration_sec=0,int width1=0,int width2=0,QEasingCurve ec=QEasingCurve::Linear );
};
QTE_LANYUI
#endif // LAN2MOVE_H
