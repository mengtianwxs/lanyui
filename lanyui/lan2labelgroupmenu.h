#ifndef LAN2LABELGROUPMENU_H
#define LAN2LABELGROUPMENU_H

#include "lan2hline.h"

#include <QFrame>
#include <QLabel>
#include <QMenu>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include"lan2global.h"

QTB_LANYUI

class Lan2LabelGroupMenu : public QMenu
{
public:
    Lan2LabelGroupMenu(int width);

public:
    QVBoxLayout* vbox;
    QVector<QMenu*> vec_menu;
    QVector<QLabel*> vec_lal;
    QVector<QAction*> vec_actmenu;
    QList<QAction*> liac;
    QVector<QWidget*> vec_wid;
    QVector<int> vec_space_Separator;
private:
    int m_width;
public:
    void addHLine(int menu_index);
    void addLabelMenu(QString lal,QList<QAction*> li_ac);
//    void addOtherWidget(QWidget* wid);
    void addAction_c(QAction* act,int menu_index);
    void endLabelGroup();


};

QTE_LANYUI

#endif // LAN2LABELGROUPMENU_H
