#ifndef CUSTOMBAR_H
#define CUSTOMBAR_H
#include "lanyui/styles/lss2titlebar.h"
#include "lan2quickmenu.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QMainWindow>

#include "lan2global.h"

QTB_LANYUI
class Lan2TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit Lan2TitleBar(QWidget *parent = nullptr);
private:
    bool isLeftPressed;
    QPoint start_pos;

    QLabel* lal_title;
    QLabel* lal_icon;
    QPushButton* btn_min;
    QPushButton* btn_close;
    QPushButton* btn_max;
public:
    QHBoxLayout* hbox;
    void addQuickMenu(Lan2QuickMenu* menu);
    void setMinBtnText(QString text);
    void setMaxBtnText(QString text);
    void setCloseBtnText(QString text);
    void setWinTitle(QString text);
    void setwinIcon(QString text);
    void addWidget(int index,QWidget* wid);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent* event);
   // bool eventFilter(QObject* obj,QEvent* event);



protected slots:
    void onClick();
    void onRightMenuClick();

};
QTE_LANYUI
#endif // CUSTOMBAR_H
