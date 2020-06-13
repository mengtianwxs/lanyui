#ifndef LANYU_TAB_H
#define LANYU_TAB_H

#include "lan2page.h"
#include "lanyui/styles/lss2tab.h"
#include <QAction>
#include <QObject>
#include <QPushButton>
#include <QToolButton>
#include <QWidget>
#include "lan2global.h"

QTB_LANYUI

class Lan2Tab : public QToolButton
{
    Q_OBJECT
public:

    Lan2Tab(QString objectname,QWidget* parent);
    ~Lan2Tab();


    QAction* default_action;



 signals:
    void sig_tab(QString name);

protected slots:
    void method_click();


};
QTE_LANYUI
#endif // LANYU_TAB_H
