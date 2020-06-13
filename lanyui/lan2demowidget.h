#ifndef LAN2DEMOWIDGET_H
#define LAN2DEMOWIDGET_H

#include <QObject>
#include <QWidget>
#include<QDebug>
#include <QMouseEvent>

class Lan2DemoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit Lan2DemoWidget(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent* event);

signals:

public slots:
};

#endif // LAN2DEMOWIDGET_H
