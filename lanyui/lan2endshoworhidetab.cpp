#include "lan2endshoworhidetab.h"


QTB_LANYUI

Lan2EndShowOrHideTab::Lan2EndShowOrHideTab(QString objectname)
{
    this->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->setFixedSize(C_TabRWidth,C_TabRHeight);
    this->setStyleSheet(StyleSheet_DefaultRTabBG);

    def_action=new QAction();
    this->setDefaultAction(def_action);
    connect(def_action,SIGNAL(triggered()),this,SLOT(method_endtab()));

    this->setObjectName(objectname);//一般设置成图片不需要有文字信息显示
}

void Lan2EndShowOrHideTab::method_endtab()
{
    emit sig_endtab(this->objectName());
}


QTE_LANYUI
