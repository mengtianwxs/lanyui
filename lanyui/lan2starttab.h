#ifndef LAN2LTAB_H
#define LAN2LTAB_H
#include "lss2starttab.h"
#include <QAction>
#include <QObject>
#include <QToolButton>
#include <QWidget>

#include"lan2global.h"

QTB_LANYUI

class Lan2StartTab : public QToolButton//只允许显示文字
{
    Q_OBJECT
public:
    Lan2StartTab(QString objectname="",QWidget* parent=Q_NULLPTR,int width=60,int height=35,QString bgcolor="#14af75");

public:
    QAction* def_action;


signals:
   void sig_starttab(QString name);

protected slots:
   void method_starttab();

};
QTE_LANYUI
#endif // LAN2LTAB_H
