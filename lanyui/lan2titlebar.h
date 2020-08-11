#ifndef CUSTOMBAR_H
#define CUSTOMBAR_H
#include "lanyui/styles/lss2titlebar.h"
#include "lan2quickmenu.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QLineEdit>
#include <QMenu>
#include <QSizePolicy>

#include "lan2global.h"

QTB_LANYUI
class Lan2TitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit Lan2TitleBar(QWidget *parent = nullptr);
private:
    bool t_isLeftPressed=false;
    QPoint start_pos;

    QWidget* mainWidget;

    QLabel* lal_title;
    QLabel* lal_icon;
    QPushButton* btn_min;
    QPushButton* btn_close;
    QPushButton* btn_max;
    int t_d=3;
public:
    void addQuickMenu(Lan2QuickMenu* menu);
    void setMinBtnText(QString text);
    void setMaxBtnText(QString text);
    void setCloseBtnText(QString text);
    void setWinTitle(QString text);
    void setwinIcon(QString text);
    void addWidget(int index,QWidget* wid);
    QWidget* getWidgetByName(QString na);

private:
    QHBoxLayout* hbox;


protected:
    void contextMenuEvent(QContextMenuEvent* event);
//    void mousePressEvent(QMouseEvent* event);

protected slots:
    void onClick();
//    void onrs(QPoint);

};
QTE_LANYUI
#endif // CUSTOMBAR_H
