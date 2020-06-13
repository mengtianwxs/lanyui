#ifndef LANYU_PAGE_H
#define LANYU_PAGE_H

#include "lan2toolgroup.h"

#include <QObject>
#include <QFrame>
#include<QHBoxLayout>
#include <QLabel>
#include "lan2global.h"
QTB_LANYUI


class Lan2Page : public QFrame
{
    Q_OBJECT
//    Q_PROPERTY(QString mingzi READ getMZ WRITE setMZ )

public:
    Lan2Page(QString objectname,QWidget* parent=NULL);
public:
    void addDemo(QString txt);
    void addGroupTool(Lan2ToolGroup* gt);
    void addEndSpace();


private:

    QHBoxLayout* hbox;
    QLabel* lal;
};

QTE_LANYUI

#endif // LANYU_PAGE_H
