#ifndef LAN2LTAB_H
#define LAN2LTAB_H
#include "lanyui/styles/lss2starttab.h"
#include <QAction>
#include <QObject>
#include <QToolButton>
#include <QWidget>

#include"lan2global.h"

QTB_LANYUI

class Lan2StartTab : public QToolButton
{
    Q_OBJECT
public:
    Lan2StartTab(QString objecetname,QWidget* parent=Q_NULLPTR);

public:
    QAction* def_action;

signals:
   void sig_starttab(QString name);

protected slots:
   void method_starttab();

};
QTE_LANYUI
#endif // LAN2LTAB_H
