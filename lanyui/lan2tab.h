#ifndef LANYU_TAB_H
#define LANYU_TAB_H

#include "lan2page.h"
#include <QAction>
#include <QObject>
#include <QPushButton>
#include <QToolButton>
#include <QWidget>
#include "lan2global.h"

QTB_LANYUI

class Lan2Tab : public QToolButton//只允许显示文字信息
{
    Q_OBJECT
public:

    Lan2Tab(QString objectname="",QWidget* parent=Q_NULLPTR,int width=60,int height=35,QString bgcolor="#14af75");
    ~Lan2Tab();


    QAction* default_action;



 signals:
    void sig_tab(QString name);

protected slots:
    void method_click();


};
QTE_LANYUI
#endif // LANYU_TAB_H
