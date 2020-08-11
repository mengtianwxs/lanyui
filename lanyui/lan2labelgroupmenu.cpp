#include "lan2labelgroupmenu.h"
QTB_LANYUI
Lan2LabelGroupMenu::Lan2LabelGroupMenu(int width)
{
   vbox=new QVBoxLayout();
   vbox->setSpacing(2);
   vbox->setMargin(0);
   vbox->setContentsMargins(2,4,4,2);
   this->setLayout(vbox);
   m_width=width;

}

void Lan2LabelGroupMenu::addHLine(int menu_index)
{

    vec_menu[menu_index]->addSeparator();
    vec_space_Separator.append(1);
}

void Lan2LabelGroupMenu::addLabelMenu(QString lal, QList<QAction *> li_ac)
{
    QLabel* la=new QLabel();
    la->setObjectName("ll");

    la->setText(lal);
    la->setStyleSheet("background:#cccccc;color:#505050;font-weight:bold;}");
//    vbox->addWidget(la);
    QMenu* lanmenu=new QMenu();
    lanmenu->setFixedWidth(m_width);
    lanmenu->setStyleSheet("QMenu{background:#ffffff;color:#505050;}QMenu::item:selected{background:#efefef;}");

   // menu->setFixedHeight(300);
  //  menu->setStyleSheet("background:#ffffff;color:#505050;}");\
//    vbox->addWidget(menu);

    int c=li_ac.count();
    for(int i=0;i<c;i++){
        lanmenu->addAction(li_ac[i]);
        vec_actmenu.append(li_ac[i]);
    }
   // qDebug()<<lanmenu->actions()<<"lllll";

    vec_lal.append(la);
    vec_menu.append(lanmenu);

    //liac=li_ac;




}

//void Lan2LabelGroupMenu::addOtherWidget(QWidget *wid)
//{
//    vbox->addWidget(wid);
//    vec_wid.append(wid);

//}

void Lan2LabelGroupMenu::addAction_c(QAction *act, int menu_index)
{


    vec_menu[menu_index]->addAction(act);
    vec_actmenu.append(act);


}

void Lan2LabelGroupMenu::endLabelGroup()
{
    //添加有标题的菜单组
    int t_lal=vec_lal.count();
    for(int i=0;i<t_lal;i++){
       vbox->addWidget(vec_lal[i]);
       vbox->addWidget(vec_menu[i]);
       vec_lal[i]->setFixedHeight(30);

    }


    int c1=vec_lal.count();
    int c4=vec_actmenu.count();
    int c2=vec_space_Separator.count();


    int c_all=c1*30+c4*28+c2*10;
//    qDebug()<<"all"<<c_all<<c_all*20<<c1<<"-"<<c4<<"-";
    this->setFixedHeight(c_all);
     vbox->addStretch();
    //

}
QTE_LANYUI
