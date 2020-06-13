#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void sigresize();

protected:
    virtual void resizeEvent(QResizeEvent* event);



};

#endif // MAINWINDOW_H
