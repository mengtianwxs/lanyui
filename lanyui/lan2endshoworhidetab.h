#ifndef LAN2ENDSHOWORHIDETAB_H
#define LAN2ENDSHOWORHIDETAB_H
#include "lss2rtab.h"
#include<QObject>
#include <QAction>
#include <QObject>
#include <qtoolbutton.h>
#include "lan2global.h"

QTB_LANYUI

class Lan2EndShowOrHideTab : public QToolButton
{
    Q_OBJECT
public:
    Lan2EndShowOrHideTab(QString objectname);
    QAction* def_action;

signals:
    void sig_endtab(QString name);
protected slots:
    void method_endtab();
};
QTE_LANYUI

#endif // LAN2ENDSHOWORHIDETAB_H
