#include "lan2toolgroup.h"
#include "lan2vline.h"

QTB_LANYUI

Lan2ToolGroup::Lan2ToolGroup()
{
    this->setSpacing(6);
    this->setContentsMargins(0,0,0,0);
    this->setMargin(0);
}

void Lan2ToolGroup::addToolButton(QToolButton *tb,int width,int height)
{
    if(width==0){
//        tb->setFixedWidth(C_GroupToolButtonDefWidth);
    }else{

        tb->setFixedWidth(width);
    }
    if(height==0){
        tb->setFixedHeight(C_GroupToolButtonDefHeight);
    }else{
        tb->setFixedHeight(height);
    }




    vec_menus.append(NULL);
    vec_tbs.append(tb);
    vec_assets.append("LANNULL");
    vec_texts.append("");
    isOnlyText=true;

}

void Lan2ToolGroup::addToolButtonAndInsertMenu(QToolButton* tb, QString text, int width, int height, QString iconasset,QMenu* menu)
{
    if(width==0){
        tb->setFixedWidth(C_GroupToolButtonDefWidth);
    }else{

        tb->setFixedWidth(width);
    }
    if(height==0){
        tb->setFixedHeight(C_GroupToolButtonDefHeight);
    }else{
        tb->setFixedHeight(height);
    }


    if(text==""){
        text="DEMO";
    }
    if(iconasset==""){
        iconasset="LANNULL";
    }


        if(menu==NULL){
            vec_menus.append(NULL);
        }else{
            vec_menus.append(menu);
        }


    vec_tbs.append(tb);
    vec_assets.append(iconasset);
    vec_texts.append(text);

    

}

void Lan2ToolGroup::addOtherWidget(QWidget *wid, int width, int height)
{
    if(width==0){
        wid->setFixedWidth(C_GroupToolButtonDefWidth);
    }else{

        wid->setFixedWidth(width);
    }
    if(height==0){
        wid->setFixedHeight(C_GroupToolButtonDefHeight);
    }else{
        wid->setFixedHeight(height);
    }
    vec_wids.append(wid);


}

void Lan2ToolGroup::addGroup(QLayout *ly)
{
    vec_layouts.append(ly);

}

//上面图标下面文字的组合
void Lan2ToolGroup::addUPAndDownDoubleToolButton(QToolButton *tb_icon, QString asset, QToolButton *tb_text, QString text, QMenu *menu)
{

//    QToolButton* wid=new QToolButton();

    wid=new QFrame();
    wid->setFixedSize(C_ToolGroup_DOUBLE_TB_Widht,C_ToolGroup_DOUBLE_TB_Height);
    wid->setStyleSheet(LSS_TOOLBUTTON_UPDOWNWI);
    tb_icon->setFixedSize(C_TG_DTBUP_Width,C_TG_DTBUP_Heihgt);
    tb_text->setFixedSize(C_TG_DTBDOWN_Wdith,C_TG_DTBDOWN_Height);
    tb_icon->setObjectName("tbicon");
    tb_text->setObjectName("tbtext");


    QVBoxLayout* vb=new QVBoxLayout();
     wid->setLayout(vb);

    vb->setSpacing(0);
    vb->setContentsMargins(0,0,0,0);
    vb->setMargin(0);
    vb->addWidget(tb_icon);
    vb->addWidget(tb_text);
    this->addWidget(wid);

    tb_icon->setStyleSheet(LSS_TOOLBUTTON_UP);
//    tb_text->setArrowType(Qt::DownArrow);
    if(asset!=""){
        tb_icon->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tb_icon->setIcon(QIcon(asset));
    }

    if(text!=""){
        tb_text->setToolButtonStyle(Qt::ToolButtonTextOnly);
//        tb_text->setText(text);
        QAction* actext=new QAction("ddtt");
        tb_text->setDefaultAction(actext);
        connect(actext,SIGNAL(triggered()),this,SLOT(ontbtextaction()));

    }

    if(menu){
      tb_text->setMenu(menu);
      tb_text->setPopupMode(QToolButton::InstantPopup);
      tb_text->setStyleSheet(LSS_TOOLBUTTON_DOWN);


      menu->setStyleSheet(LSS_MENU);
    }

}

void Lan2ToolGroup::addTitleMenu(QToolButton *tb, Lan2LabelGroupMenu *li_labelmenu)
{
   vec_titletb.append(tb);
  vec_labelgroup.append(li_labelmenu);

}




void Lan2ToolGroup::endGroup()
{
    ////////////////////////////////////////////////////add toolbutton menu or no menu
    int c=vec_tbs.count();
    if(c>0){

        for(int i=0;i<c;i++){
           vec_tbs[i]->setStyleSheet(LSS_TOOLBUTTON_DEF);
           if(isOnlyText){
           }else{
               vec_tbs[i]->setText(vec_texts[i]);
           }
//            vec_tbs[i]->setText(vec_texts[i]);


            //设置ToolButton的样式
            if(vec_assets[i]=="LANNULL"){
                 vec_tbs[i]->setToolButtonStyle(Qt::ToolButtonTextOnly);
            }else{
                 vec_tbs[i]->setIcon(QIcon(vec_assets[i]));

                 vec_tbs[i]->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            }


            if(vec_menus[i]==NULL){

            }else {
                    vec_tbs[i]->setMenu(vec_menus[i]);


                vec_tbs[i]->setPopupMode(QToolButton::InstantPopup);
                vec_tbs[i]->setStyleSheet(LSS_TOOLBUTTON_SELECT);
                vec_menus[i]->setStyleSheet(LSS_MENU);
            }

            this->addWidget(vec_tbs[i]);
        }
    }

    //////////////////////////////////////////////////////////////add widget
    int b=vec_wids.count();
    if(b>0){

        for(int n=0;n<b;n++){
         this->addWidget(vec_wids[n]);
        }
    }


    //////////////////////////////////////////////////////////////add layout
    int a=vec_layouts.count();
    if(a>0){
        for(int m=0;m<a;m++){
            this->addLayout(vec_layouts[m]);
        }
    }

    ////////////////////////////////////////////////////add label
   int menucout=vec_labelgroup.count();
   int labelcout=vec_titletb.count();
   if(menucout>0 and labelcout>0){
       for(int i=0;i<menucout;i++){
vec_titletb[i]->setPopupMode(QToolButton::InstantPopup);
          vec_titletb[i]->setMenu(vec_labelgroup[i]);
          this->addWidget(vec_titletb[i]);

       }

   }


/////////////////////////////////////////////////////////////////////////add v line
      Lan2VLine* vline=new Lan2VLine();

     this->addWidget(vline);
      isOnlyText=false;

}

QToolButton *Lan2ToolGroup::getTBByName(QString name)
{
    return wid->findChild<QToolButton*>(name);
}

void Lan2ToolGroup::ontbtextaction()
{
qDebug()<<"clicked tb";
//  QToolButton* tb_icon=getTBByName("tbicon");
//  QToolButton* tb_text=getTBByName("tbtext");
//  tb_icon->setStyleSheet(LSS_TBUPDOWN_CLICKED);
//  tb_text->setStyleSheet(LSS_TBUPDOWN_CLICKED);
}

QTE_LANYUI



