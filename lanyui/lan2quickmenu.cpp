#include "lan2quickmenu.h"

#include <QLabel>
QTB_LANYUI
Lan2QuickMenu::Lan2QuickMenu(QWidget *parent) : QFrame(parent)
{
    this->setFixedHeight(C_QuickMenu_Height);
    this->setStyleSheet(LSS_QuickMenu_BG);

    hbox=new QHBoxLayout();
    hbox->setSpacing(2);
    hbox->setContentsMargins(0,0,0,0);
    hbox->setMargin(0);
    this->setLayout(hbox);

    //init end menu and ToolButton
    endTBTN=new QToolButton();
//    endTBTN->setToolButtonStyle(Qt::ToolButtonIconOnly);
    endTBTN->setFixedSize(25,28);
//    endTBTN->setIcon(QIcon("://lanyui/images/quickmenu1.png"));
//    endTBTN->setIconSize(QSize(15,20));
    endTBTN->setToolButtonStyle(Qt::ToolButtonTextOnly);
    endTBTN->setText("〤");
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    endTBTN->setFont(font);

    endTBTN->setStyleSheet(LSS_QuickMenu_TBEnd);
    endMenu=new QMenu();
    endMenu->setStyleSheet("QMenu{background:#f9f9f9;color:#505050;width:100px;}QMenu::item:selected{background:#efefef;color:#505050;}");
    endTBTN->setPopupMode(QToolButton::InstantPopup);


}

//void Lan2QuickMenu::addToolButton(QToolButton *tb, QString iconasset,QString objectname, QString menutext)
//{
//    if(tb!=NULL and iconasset!="" and menutext!=NULL  and objectname!=""){

//        vec_tbs.append(tb);
//        vec_icons.append(iconasset);
//        vec_menutext.append(menutext);

//        index=index+1;//序列号
//        map.insert(menutext,index);//把endToolButton的文字显示信息与序列号关联起来

//        vec_actend.append(new QAction());//endToolButton的Qaction自动建立，自动管理
//        vec_name.append(objectname);//toolbutton的objectname

//        isOk=true;
//    }else{
//        isOk=false;
//    }



//}

void Lan2QuickMenu::addToolButton(QToolButton *tb,QString objectname, QString menutext)
{
    if(tb!=NULL and menutext!=NULL  and objectname!=""){

        vec_tbs.append(tb);
        vec_menutext.append(menutext);

        index=index+1;//序列号
        map.insert(menutext,index);//把endToolButton的文字显示信息与序列号关联起来

        vec_actend.append(new QAction());//endToolButton的Qaction自动建立，自动管理
        vec_name.append(objectname);//toolbutton的objectname

        isOk=true;
    }else{
        isOk=false;
    }



}

void Lan2QuickMenu::endQuickMenu()
{

    int t=vec_tbs.count();
    this->setFixedWidth((t+1)*30);//总共是T＋1个

    //前期需要添加的组件
    if(t>0 and isOk){
        for(int i=0;i<t;i++){

            vec_tbs[i]->setStyleSheet(LSS_QuickMenu_TB);
//            vec_tbs[i]->setIcon(QIcon(vec_icons[i]));
            vec_tbs[i]->setObjectName(vec_name[i]);//为每个ToolButton设置objcetname
            hbox->addWidget(vec_tbs[i]);
//            qDebug()<<vec_icons[i]<<vec_tbs[i]->objectName();
        }

        //给end menu设置菜单

        for(int o=0;o<t;o++){
            vec_actend[o]->setText(vec_menutext[o]);
            endMenu->addAction(vec_actend[o]);
            connect(vec_actend[o],SIGNAL(triggered()),this,SLOT(method_act()));
            vec_actend[o]->setCheckable(true);
            vec_actend[o]->setChecked(true);
        }
    }

    hbox->addWidget(endTBTN);
    hbox->addStretch();
    endTBTN->setMenu(endMenu);
}

QToolButton *Lan2QuickMenu::getToolButtonByObjectName(QString name)
{
    return this->findChild<QToolButton*>(name);
}

void Lan2QuickMenu::showToolButton(int index)
{
   vec_tbs[index-1]->show();
}

void Lan2QuickMenu::hideToolButton(int index)
{
    vec_tbs[index-1]->hide();
}



int Lan2QuickMenu::getIndexByName(QString name)
{
    return int(map[name]);
}

void Lan2QuickMenu::bindQActionByName(QString name,QAction* act)
{
    this->getToolButtonByObjectName(name)->setDefaultAction(act);
}

void Lan2QuickMenu::method_act()
{
     QAction* ac=qobject_cast<QAction*>(sender());
     int i=getIndexByName(ac->text());
     if(ac->isChecked()){
        showToolButton(i);
     }else{
         hideToolButton(i);
     }

}

QTE_LANYUI


