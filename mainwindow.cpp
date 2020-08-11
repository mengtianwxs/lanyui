#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lanyui/lan2global.h"
#include "lanyui/lan2titlebar.h"

#include <lanyui/lan2vmenu.h>

QT_USE_LANYUI

MainWindow::MainWindow(QWidget *parent) :
    CFramelessWindow (parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    this->centralWidget()->setLayout(fw_vbox);
    vbox=new QVBoxLayout();
    vbox->setSpacing(0);
    vbox->setContentsMargins(0,0,0,0);
    vbox->setMargin(0);
    this->centralWidget()->setLayout(vbox);

    initUserData();


}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::getDesktopWidth()
{
    QDesktopWidget* desktop=QApplication::desktop();
    int width=desktop->screen()->width();
    return width;
}

int MainWindow::getDesktopHeight()
{
    QDesktopWidget* desktop=QApplication::desktop();
    int height=desktop->screen()->height();
    return height;
}

void MainWindow::initUserData()
{

    /////////////////////////////////////do something
    /// do lan2widget
    ///
    ///

    tb=new Lan2TitleBar();
    this->setTitleBar(tb);
    tb->setWinTitle("llmm");

//    addIgnoreWidget(
    this->addIgnoreWidget(tb->getWidgetByName("title"));
//    this->addIgnoreWidget(tb);

    Lan2vmenu* vm=new Lan2vmenu();

//    this->addIgnoreWidget(tb);
//    lal=new QLabel();
//    lal->setText("llllmt");
//    this->setTitleBar(lal);
//    lal->installEventFilter(this);

//    lal->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(lal,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slot_r(QPoint)));

//    Lan2QuickMenu* quickmenu=new Lan2QuickMenu();
//    QToolButton* tb1=new QToolButton();
//    tb1->setText("aa");
//    QToolButton* tb2=new QToolButton();
//    tb2->setText("bb");
//    quickmenu->addToolButton(tb1);
//    quickmenu->addToolButton(tb2);
//    quickmenu->endQuickMenu();

//    tb->addQuickMenu(quickmenu);

        vbox->addWidget(tb);
        vbox->addWidget(vm);
//        vbox->addWidget(lal);
        vbox->addStretch();



}

//bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
//{

// QWidget* tar=tb->findChild<QWidget*>("mm");
//    if(obj==lal){

//        if(ev->type()==QEvent::MouseButtonPress){
//            QMouseEvent* mouseevent=(QMouseEvent*)ev;
//            if(mouseevent->buttons()==Qt::RightButton){
//                qDebug()<<"right button";

//            }
//        }

//    }

//    return QMainWindow::eventFilter(obj,ev);
//}

void MainWindow::hideMainToolBarAndMenuBar(QMainWindow *mw)
{


    QToolBar* toolbar=mw->findChild<QToolBar*>("mainToolBar");
    if(toolbar)
    toolbar->hide();
    QMenuBar* menubar=mw->findChild<QMenuBar*>("menuBar");
    if(menubar)
    menubar->hide();

}

void MainWindow::hideMainStatusBar(QMainWindow *mw)
{
//    QStatusBar* statusbar=mw->findChild<QStatusBar*>("statusBar");
//    if(statusbar){
//        statusbar->hide();
    //    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
//    if(event->buttons()==Qt::RightButton){
//        qDebug()<<event->pos()<<"right click";
//    }
}

//void MainWindow::slot_r(QPoint p)
//{
//    qDebug()<<p<<"sr";
//    QMenu* menu=new QMenu();
//    menu->addAction("aa111");
//    menu->addAction("bb111");
//    menu->exec(QCursor::pos());
//}


