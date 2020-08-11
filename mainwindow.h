#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QToolBar>
#include<QMenuBar>
#include<QMouseEvent>
#include<QDesktopWidget>
#include <QVBoxLayout>

#include <lanyui/framelesswindow.h>
#include <lanyui/lan2contexttab.h>
#include <lanyui/lan2titlebar.h>
//#include <lanyui/lan2demowindow.h>
#include<lanyui/styles/lss2assets.h>
#include <lanyui/lan2quickmenu.h>

QT_USE_LANYUI
namespace Ui {
class MainWindow;
}

class MainWindow : public CFramelessWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVBoxLayout* vbox;

public:

    int getDesktopWidth();
    int getDesktopHeight();


    void initUserData();//use data


private:

    void hideMainToolBarAndMenuBar(QMainWindow* mw);
    void hideMainStatusBar(QMainWindow* mw);

    Lan2TitleBar* tb;
    QLabel* lal;

protected:
    void mousePressEvent(QMouseEvent*event);

public slots:
//    void slot_r(QPoint);









};

#endif // MAINWINDOW_H
