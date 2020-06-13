#ifndef LANYU_RTAB_H
#define LANYU_RTAB_H
#include "lanyui/styles/lss2rtab.h"
#include <QAction>
#include <QObject>
#include <QToolButton>
#include <QWidget>
#include"lan2global.h"

QTB_LANYUI
class Lan2RTab : public QToolButton
{
    Q_OBJECT
public:
    Lan2RTab(QString objectname);
    void setricon(QString url);
    void  settext(QString text);
    QAction* def_action;

signals:
    void sig_rtab(QString name);
protected slots:
    void method_rtab();
};
QTE_LANYUI
#endif // LANYU_RTAB_H
