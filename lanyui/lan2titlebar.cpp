#include "lan2titlebar.h"

QTB_LANYUI
Lan2TitleBar::Lan2TitleBar(QWidget *parent)
    : QFrame(parent)
{

    setStyleSheet(StyleSheet_WidCommonBG);
    setFixedHeight(C_TitleBarHeight);

    lal_icon=new QLabel();
    lal_icon->setFixedSize(C_TitleBarWidWidth,C_TitleBarWidHeight);


    lal_title=new QLabel();
    lal_title->setObjectName("title");
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

    btn_min->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);
    btn_max->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);
    btn_close->setStyleSheet(StyleSheet_DefaultTitleBarPushButtonBG);

    btn_min->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);
    btn_max->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);
    btn_close->setFixedSize(C_TitleBarsPBWidth,C_TitleBarsPBHeight);



    QFont font("Microsoft YaHei",14,2);
    lal_title->setFont(font);

    QLineEdit* le=new QLineEdit();
    le->setStyleSheet("QLineEdit{background:#ffffff;}QLineEdit::hover{border:none}");


//    QLabel* lalnullleft=new QLabel();
//    lalnullleft->setFixedHeight(C_TitleBarHeight);
//    QLabel* lalnullright=new QLabel();
//    lalnullright->setFixedHeight(C_TitleBarHeight);
//    lalnullleft->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

//    lalnullleft->setAutoFillBackground(false);
//    lalnullleft->setAttribute(Qt::WA_TransparentForMouseEvents,true);

    hbox=new QHBoxLayout();
    hbox->addWidget(lal_icon);
    hbox->addStretch(1);
//    hbox->addWidget(lalnullleft,1);

    hbox->addWidget(lal_title);
    hbox->addStretch(1);
//    hbox->addWidget(lalnullright,1);
    hbox->addWidget(btn_min);
    hbox->addWidget(btn_max);
    hbox->addWidget(btn_close);
    hbox->setSpacing(0);
    hbox->setContentsMargins(0,0,0,0);
    hbox->setMargin(0);

    this->setLayout(hbox);


    connect(btn_min,SIGNAL(clicked()),this,SLOT(onClick()));
    connect(btn_max,SIGNAL(clicked()),this,SLOT(onClick()));
    connect(btn_close,SIGNAL(clicked()),this,SLOT(onClick()));

//    this->setAttribute(Qt::WA_TransparentForMouseEvents,true);




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

QWidget *Lan2TitleBar::getWidgetByName(QString na)
{
    return findChild<QWidget*>(na);
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
  delete menu;
  event->ignore();


}

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


QTE_LANYUI
