#ifndef LAN22HSPLITTER_H
#define LAN22HSPLITTER_H

#include <QObject>
#include <QWidget>
#include <qsplitter.h>
#include<QDebug>
#include <QVBoxLayout>

class Lan22hSplitter : public QSplitter
{
    Q_OBJECT
public:
    Lan22hSplitter();

    QFrame *getPanelleft() const;

    QFrame *getPanelright() const;

private:

    QFrame* panel1;
    QFrame* panel2;
};

#endif // LAN22HSPLITTER_H
