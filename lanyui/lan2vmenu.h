#ifndef LAN2VMENU_H
#define LAN2VMENU_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

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

#endif // LAN2VMENU_H
