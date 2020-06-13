#include "lan2demowidget.h"

Lan2DemoWidget::Lan2DemoWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:#ffffff");
//    this->setMouseTracking(true);
//    qDebug()<<parentWidget()->metaObject()->className();
}

void Lan2DemoWidget::mouseMoveEvent(QMouseEvent *event)
{

    this->setStyleSheet("QWidget:hover{border:1px solid #ececec;}");
    qDebug()<<"test wid";
//    event->accept();
//    QWidget::mouseMoveEvent(event);



}
