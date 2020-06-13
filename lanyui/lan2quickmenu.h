#ifndef LAN2QUICKMENU_H
#define LAN2QUICKMENU_H

#include "styles/lss2quickmenu.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QObject>
#include <QToolButton>
#include <QAction>
#include <QMap>
#include "lan2global.h"
QTB_LANYUI

class Lan2QuickMenu : public QFrame
{
    Q_OBJECT
public:
    explicit Lan2QuickMenu(QWidget *parent = nullptr);
public:
//    void addToolButton(QToolButton* tb=NULL,QString iconasset="",QString objectname="",QString menutext="");
    void addToolButton(QToolButton* tb=NULL,QString objectname="",QString menutext="");

    void endQuickMenu();
    QToolButton* getToolButtonByObjectName(QString name);
    void showToolButton(int index);
    void hideToolButton(int index);
    int getIndexByName(QString name);
    void bindQActionByName(QString name,QAction* act);


public:
    QHBoxLayout* hbox;
    QVector<QToolButton*> vec_tbs;
    QVector<QString> vec_icons;
    QVector<QString> vec_menutext;
    QVector<QAction*> vec_actend;
    QVector<QString> vec_name;
    QMap<QString ,int> map;

private:
    bool isOk=false;
    QToolButton* endTBTN;
    QMenu* endMenu;
    int index=0;

public  slots:
    void method_act();


};
QTE_LANYUI
#endif // LAN2QUICKMENU_H
