#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <lanyui/lan2demo.h>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,800);
    Lan2Demo* ldemo=new Lan2Demo();
    ldemo->init(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"resize";
    emit sigresize();

}
