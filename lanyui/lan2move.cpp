#include "lan2move.h"

#include <QSplitter>
QTB_LANYUI
Lan2Move::Lan2Move()
{

}

void Lan2Move::to2(QObject *target1, QObject *target2, int duration_sec, int width1, int width2, QEasingCurve ec)
{
    QWidget* wid1=qobject_cast<QWidget*>(target1);
    QWidget* wid2=qobject_cast<QWidget*>(target2);


  QPropertyAnimation* pa1=new QPropertyAnimation(target1,"geometry");
  QPropertyAnimation* pa2=new QPropertyAnimation(target2,"geometry");
  pa1->setDuration(duration_sec*1000);
  pa2->setDuration(duration_sec*1000);

  pa1->setEasingCurve(ec);
  pa2->setEasingCurve(ec);
  if(width1!=0 and width2!=0){
    pa1->setEndValue(QRect(wid1->x(),wid1->y(),width1,wid1->height()));
    pa2->setEndValue(QRect(wid2->x(),wid2->y(),width2,wid2->height()));
  }



  pa1->start();
  pa2->start();
}


void Lan2Move::to(QObject *target, int duration_sec,  int x, int y, QEasingCurve ec)
{
    QWidget* wid=qobject_cast<QWidget*>(target);

  QPropertyAnimation* pa=new QPropertyAnimation(target,"geometry");
  pa->setDuration(duration_sec*1000);
  pa->setEasingCurve(ec);
  if(x!=0 and y==0){
    pa->setEndValue(QRect(x,wid->y(),wid->width(),wid->height()));
  }

  if(x==0 and y!=0){
      pa->setEndValue(QRect(wid->x(),y,wid->width(),wid->height()));
  }

  if(x!=0 and y!=0){
       pa->setEndValue(QRect(x,y,wid->width(),wid->height()));
  }


  pa->start();

}
QTE_LANYUI


