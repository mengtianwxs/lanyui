#ifndef LAN2GROUPTOOL_H
#define LAN2GROUPTOOL_H
#include "lanyui/styles/lss2grouptool.h"
#include "lanyui/styles/lss2vline.h"
#include "lan2gridmenu.h"
#include <QBoxLayout>
#include <QObject>
#include <QToolButton>
#include <QMenu>
#include<QAction>
#include <QFrame>
#include <QLabel>
#include "lan2global.h"
#include "lan2labelgroupmenu.h"

QTB_LANYUI
class Lan2ToolGroup : public QHBoxLayout
{
  Q_OBJECT
public:
    Lan2ToolGroup();
    //@1
    void addToolButton(QToolButton* tb,int width=0,int height=0);
    //@2
    void addToolButtonAndInsertMenu(QToolButton* tb,QString text,int width=0,int height=0,QString iconasset="",QMenu* menu=NULL);
    //@3
    void addOtherWidget(QWidget* wid,int width=0,int height=0);
    //@4
    void addGroup(QLayout* ly);
    //@5
    void addUPAndDownDoubleToolButton(QToolButton* tb_icon=NULL,QString asset="",QToolButton* tb_text=NULL,QString text="",QMenu* menu=NULL);
    //@6
    void addTitleMenu(QToolButton* tb,Lan2LabelGroupMenu* li_labelmenu);

    void endGroup();
public:
    ////////////group1
    QVector<QToolButton*> vec_tbs;
    QVector<QString> vec_assets;
    QVector<QString> vec_texts;
    QVector<QMenu*> vec_menus;
      ////////////group2
    QVector<QWidget*> vec_wids;
     ////////////group3
    QVector<QLayout*> vec_layouts;

    QVector<QToolButton*> vec_titletb;
    QVector<Lan2LabelGroupMenu*> vec_labelgroup;

    QAction* act_tbtext;
    QFrame* wid;

public:
    QToolButton* getTBByName(QString name);
private:
    bool isOnlyText=false;
public slots:
    void ontbtextaction();






};
QTE_LANYUI
#endif // LAN2GROUPTOOL_H
