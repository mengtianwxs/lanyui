#ifndef LAN2VMENU_H
#define LAN2VMENU_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include"lan2global.h"
QTB_LANYUI
class Lan2vmenu : public QFrame
{
    Q_OBJECT
public:
    explicit Lan2vmenu(QWidget *parent = nullptr);
private:
    QLabel* lal1;
    QLabel* lal2;
    QVBoxLayout* vbox;


signals:

public slots:
};
QTE_LANYUI
#endif // LAN2VMENU_H
