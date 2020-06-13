#include "lan2titlebar.h"

#include <QLineEdit>
#include <QMenu>
#include <QSizePolicy>
QTB_LANYUI
Lan2TitleBar::Lan2TitleBar(QWidget *parent) : QWidget(parent)
{



    lal_icon=new QLabel();
    lal_icon->setFixedSize(C_TitleBarWidWidth,C_TitleBarWidHeight);


    lal_title=new QLabel();
    lal_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    lal_title->setFixedHeight(C_TitleBarWidHeight);
    lal_title->setScaledContents(true);
    lal_title->setStyleSheet("color:#ffffff");

    btn_min=new QPushButton();
    btn_max=new QPushButton();
    btn_close=new QPushButton();
    btn_max->setText("「」");
    btn_min->setText("-");
    btn_close->setText("x");
//    btn_close->setFlat(false);

    btn_min->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);
    btn_max->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);
    btn_close->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);

    btn_min->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);
    btn_max->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);
    btn_close->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);


    QWidget* mainWidget=new QWidget();
    QHBoxLayout* mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(mainWidget);
    mainWidget->setStyleSheet(StyleSheet_WidCommonBG);
    mainWidget->setFixedHeight(C_TitleBarHeight);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);


//    QFont font("Microsoft YaHei",14,2);
//    lal_title->setFont(font);

//    QLineEdit* le=new QLineEdit();
//    le->setStyleSheet("QLineEdit{background:#ffffff;}QLineEdit::hover{border:none}");

    hbox=new QHBoxLayout();
    hbox->addWidget(lal_icon);
    hbox->addStretch(1);

    hbox->addWidget(lal_title);
    hbox->addStretch(1);
    hbox->addWidget(btn_min);
    hbox->addWidget(btn_max);
    hbox->addWidget(btn_close);
    hbox->setSpacing(0);
    hbox->setContentsMargins(0,0,0,0);
    hbox->setMargin(0);
    mainWidget->setLayout(hbox);

    connect(btn_min,SIGNAL(clicked()),this,SLOT(onClick()));
    connect(btn_max,SIGNAL(clicked()),this,SLOT(onClick()));
    connect(btn_close,SIGNAL(clicked()),this,SLOT(onClick()));
    this->setContextMenuPolicy(Qt::DefaultContextMenu);

}

void Lan2TitleBar::addQuickMenu(Lan2QuickMenu *menu)
{
    hbox->insertWidget(1,menu);
    hbox->insertSpacing(1,16);

}

void Lan2TitleBar::setMinBtnText(QString text)
{

    btn_min->setText(text);
}

void Lan2TitleBar::setMaxBtnText(QString text)
{
    btn_max->setText(text);
}

void Lan2TitleBar::setCloseBtnText(QString text)
{
    btn_close->setText(text);
}

void Lan2TitleBar::setWinTitle(QString text)
{
    lal_title->setText(text);
}

void Lan2TitleBar::setwinIcon(QString text)
{
    QIcon icon(text);
    lal_icon->setPixmap(icon.pixmap(lal_icon->size()));
}

void Lan2TitleBar::addWidget(int index, QWidget *wid)
{
    hbox->insertWidget(index,wid);
}

void Lan2TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        isLeftPressed=true;
        start_pos=event->globalPos();
    }
}

void Lan2TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(isLeftPressed){
//        qDebug()<<parentWidget()->metaObject()->className()<<"title"<<parentWidget()->parentWidget()->metaObject()->className();
        parentWidget()->parentWidget()->move(parentWidget()->parentWidget()->geometry().topLeft()+event->globalPos()-start_pos);

        start_pos=event->globalPos();


    }
}

void Lan2TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        isLeftPressed=false;
    }
}

void Lan2TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
        QWidget* mainwid=parentWidget()->parentWidget();
        if(mainwid->windowState()==Qt::WindowNoState){
            mainwid->showMaximized();

        }else if(mainwid->windowState()==Qt::WindowMaximized){

            mainwid->showNormal();
        }

}

void Lan2TitleBar::contextMenuEvent(QContextMenuEvent *event)
{

  QMenu* menu=new QMenu();
  QAction* ac1=menu->addAction("最大化");
  QAction* ac2=menu->addAction("最小化");
  QAction* ac3=menu->addAction("关闭");
  ac1->setObjectName("ac_max");
  ac2->setObjectName("ac_min");
  ac3->setObjectName("ac_close");

  connect(ac1,SIGNAL(triggered()),this,SLOT(onRightMenuClick()));
  connect(ac2,SIGNAL(triggered()),this,SLOT(onRightMenuClick()));
  connect(ac3,SIGNAL(triggered()),this,SLOT(onRightMenuClick()));
  menu->exec(QCursor::pos());//事件注册之后再声明此语句，要不然无效qaction
  event->accept();

}
/*
bool Lan2TitleBar::eventFilter(QObject *obj, QEvent *event)
{
    QWidget* pw=qobject_cast<QWidget*>(obj);
    switch (event->type()) {
    case QEvent::WindowTitleChange:
        if(pw){

            lal_title->setText(pw->windowTitle());
            return true;
        }

        break;

    case QEvent::WindowIconChange:
        if(pw){
            QIcon icon=pw->windowIcon();
            lal_icon->setPixmap(icon.pixmap(lal_icon->size()));
            return true;


        }

    }

    return QWidget::eventFilter(obj,event);



}
*/
void Lan2TitleBar::onClick()
{
    QWidget* mainwid=this->parentWidget()->parentWidget();
    QPushButton* pb=qobject_cast<QPushButton*>(sender());

    if(mainwid->isTopLevel()){

        if(pb==btn_min){

            mainwid->showMinimized();
        }
        if(pb==btn_max){
            if(mainwid->windowState()==Qt::WindowMaximized){
                mainwid->setWindowState(Qt::WindowNoState);

            }else {
               mainwid->showMaximized();

            }
        }
        if(pb==btn_close){

            mainwid->close();
        }
    }



}

void Lan2TitleBar::onRightMenuClick()
{

    QWidget* mainwid=this->parentWidget()->parentWidget();
    QAction* ac=qobject_cast<QAction*>(sender());
    if(ac->objectName()=="ac_min"){
        mainwid->showMinimized();
    }
    if(ac->objectName()=="ac_max"){
        mainwid->showMaximized();
    }
    if(ac->objectName()=="ac_close"){
        mainwid->close();
    }
}
QTE_LANYUI
