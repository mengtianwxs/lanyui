#include "lan22hsplitter.h"


Lan22hSplitter::Lan22hSplitter()
{
    panel1=new QFrame(this);
    panel1=new QFrame(this);

    this->setOrientation(Qt::Horizontal);
    this->setOpaqueResize(true);
    this->setHandleWidth(2);
    this->setStyleSheet("QSplitter::handle{background:#ffffff");

}

QFrame *Lan22hSplitter::getPanelleft() const
{
    return panel1;

}

QFrame *Lan22hSplitter::getPanelright() const
{
    return panel2;
}

