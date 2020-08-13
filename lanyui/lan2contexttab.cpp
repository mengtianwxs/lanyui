#include "lan2contexttab.h"

QTB_LANYUI

Lan2ContextTab::Lan2ContextTab(int height,int tabheight,QWidget *parent) : QWidget(parent)
{

    setWindowFlags(Qt::FramelessWindowHint);

    this->setFixedHeight(height);//设置总高度
    _tabheight=tabheight;
    _height=height;

    wid_page=new QWidget(this);
    wid_tab=new QWidget(this);
    wid_page->setObjectName("wid_page");
    wid_tab->setObjectName("wid_tab");

    wid_page->setFixedHeight(height-tabheight);
    wid_tab->setFixedHeight(tabheight);

    wid_tab->setStyleSheet(StyleSheet_WidTabBG);
    wid_page->setStyleSheet(StyleSheet_WidPageBG);

    tabHBox=new QHBoxLayout();
    tabHBox->setSpacing(0);

    tabHBox->setContentsMargins(6,0,10,0);

    pageHBox=new QHBoxLayout();
    pageHBox->setSpacing(0);
    pageHBox->setMargin(0);
    pageHBox->setContentsMargins(0,0,0,0);

    wid_tab->setLayout(tabHBox);
    wid_page->setLayout(pageHBox);



    mainVbox=new QVBoxLayout(this);
    mainVbox->setSpacing(0);
    mainVbox->setMargin(0);
    mainVbox->setContentsMargins(0,0,0,0);

    this->setLayout(mainVbox);

    mainVbox->addWidget(wid_tab);
    mainVbox->addWidget(wid_page);
    //lanstate=State::SHOW;
}


void Lan2ContextTab::bindMainTabAndPage(Lan2Tab *tb, Lan2Page *page)
{
     vec_pages.append(page);
     vec_tabs.append(tb);
     connect(tb,SIGNAL(sig_tab(QString)),this,SLOT(method_tab(QString)));

}



void Lan2ContextTab::addRightTab( Lan2RTab *rtb)
{
     tabHBox->addWidget(rtb);
     tabHBox->addSpacing(4);
     connect(rtb,SIGNAL(sig_rtab(QString)),this,SLOT(method_right_tab(QString)));

}

void Lan2ContextTab::addEndShowOrHideTab(QString path1,QString path2)
{
    endpath1=path1;
    endpath2=path2;
    endtb=new Lan2EndShowOrHideTab("soh");

    endtb->setIcon(QIcon(path1));
    tabHBox->addWidget(endtb);
    connect(endtb,SIGNAL(sig_endtab(QString)),this,SLOT(method_end_tab(QString)));

}


void Lan2ContextTab::addStartTab(Lan2StartTab *ltb)
{
    tabHBox->addWidget(ltb);
    connect(ltb,SIGNAL(sig_starttab(QString)),this,SLOT(method_start_tab(QString)));

}



void Lan2ContextTab::endTabAndPage()
{

    if(!vec_tabs.isEmpty() and !vec_pages.isEmpty()){
        for(auto w : vec_tabs){

            tabHBox->addWidget(qobject_cast<Lan2Tab*>(w));
        }
            tabHBox->addStretch();//留白用

    }

}

Lan2Tab *Lan2ContextTab::getTabByObjectName(QString tab_name)
{
    for (auto t : vec_tabs){

        if(t->objectName()==tab_name){
            return t;
        }
    }
}

Lan2Page *Lan2ContextTab::getPageByObjectName(QString page_name)
{
    QString pn="p"+page_name;
    for (auto p : vec_pages){

        if(p->objectName()==pn){
            return p;
        }
    }
}

Lan2StartTab *Lan2ContextTab::getStartTabByObjectName(QString tab_name)
{
    return wid_tab->findChild<Lan2StartTab*>(tab_name);
}

Lan2RTab *Lan2ContextTab::getRightTabByObjectName(QString tab_name)
{
    return wid_tab->findChild<Lan2RTab*>(tab_name);
}

Lan2EndShowOrHideTab *Lan2ContextTab::getEndShowOrHideTabByObjectName(QString name)
{
    return wid_tab->findChild<Lan2EndShowOrHideTab*>(name);
}

void Lan2ContextTab::hidePage()
{

    for(auto p : vec_pages){
         Lan2Page* page=qobject_cast<Lan2Page*>(p);
         if(!page->isHidden()){
             page->hide();
             page->setParent(Q_NULLPTR);
         }

    }
    if(!wid_page->isHidden()){


      wid_page->hide();
      wid_page->setParent(Q_NULLPTR);
      mainVbox->removeWidget(wid_page);
    }
      this->setFixedHeight(_tabheight);//重新设置整体高度为tab的高度

}

void Lan2ContextTab::deleteAllPage()
{
    if(wid_page->children().count()>0){
        for(auto p : vec_pages){
             Lan2Page* page=qobject_cast<Lan2Page*>(p);
             pageHBox->removeWidget(page);
             page->setParent(Q_NULLPTR);
        }
    }

}

void Lan2ContextTab::showPage()
{
    if(wid_page->isHidden()){


        for(auto p : vec_pages){
            Lan2Page* page=qobject_cast<Lan2Page*>(p);

            page->setParent(wid_page);//设置的顺序很重要不然会出现闪屏现象
            page->show();//设置的顺序很重要不然会出现闪屏现象

        }

        wid_page->setParent(this);//设置的顺序很重要不然会出现闪屏现象
        mainVbox->addWidget(wid_page);//设置的顺序很重要不然会出现闪屏现象
        wid_page->show();//设置的顺序很重要不然会出现闪屏现象
        this->setFixedHeight(_height);//重新设置整体高度为tab的高度+page的高度

        deleteAllPage();

        if(vec_selectPage.count()>0){

            pageHBox->addWidget(vec_selectPage[vec_selectPage.count()-1]);
        }

    }

}

void Lan2ContextTab::inittab(QString tabobjectname)
{
    Lan2Tab* tb=getTabByObjectName(tabobjectname);
    tb->setStyleSheet(StyleSheet_SelectTab);
    if(pageHBox->count()>0){
         deleteAllPage();
    }

     pageHBox->addWidget(getPageByObjectName(tabobjectname));
     vec_selectPage.append(getPageByObjectName(tabobjectname));//***

     lanstate=State::SHOW;
}

void Lan2ContextTab::initStartTab()
{
    if(lanstarttab!=Q_NULLPTR){
        lanstarttab->setStyleSheet(StyleSheet_DefaultStartTabBG);
    }

}

void Lan2ContextTab::addStartAndInitTab(Lan2StartTab* ltb)
{

    if(ltb!=Q_NULLPTR){
        lanstarttab=ltb;
        tabHBox->addWidget(ltb);
        connect(ltb,SIGNAL(sig_starttab(QString)),this,SLOT(method_start_tab(QString)));

        ltb->setStyleSheet(StyleSheet_DefaultStartTabBG);
    }

}

void Lan2ContextTab::setEndTabState(Lan2ContextTab::State state)
{
//    cstate=state;
    lanstate=state;
}




void Lan2ContextTab::method_tab(QString name)
{

    for(auto t : vec_tabs){
        t->setStyleSheet(StyleSheet_DefaultTabBG);
    }
    Lan2Tab* tb=getTabByObjectName(name);
    tb->setStyleSheet(StyleSheet_SelectTab);

    deleteAllPage();

    pageHBox->addWidget(getPageByObjectName(name));
    vec_selectPage.append(getPageByObjectName(name));

    if(wid_page->isHidden()){
        showPage();
        endtb->setIcon(QIcon(endpath1));
        lanstate=State::SHOW;
    }


}
//starttab do somethings...
void Lan2ContextTab::method_start_tab(QString name)
{
    Lan2StartTab* stb=getStartTabByObjectName(name);
    stb->setStyleSheet(StyleSheet_DefaultStartTabBG);
//    qDebug()<<"do start";
    emit CONTEXTTAB_STARTTAB(name);


}
void Lan2ContextTab::method_right_tab(QString name)
{
//    qDebug()<<name<<"rtab";
    emit CONTEXTTAB_RTAB(name);


}
//通过不同的数字0 1实现右侧图片的切换

void Lan2ContextTab::method_end_tab(QString name)
{

 times=times+1;
    Lan2EndShowOrHideTab* endtab=getEndShowOrHideTabByObjectName(name);

    if(lanstate==State::SHOW){
        endtab->setIcon(QIcon(endpath2));
        hidePage();

    }

    if(lanstate==State::HIDE){
        endtab->setIcon(QIcon(endpath1));

        showPage();
    }


    if(times%2==0){
        lanstate=State::SHOW;
    }else{
        lanstate=State::HIDE;
    }


    emit CONTEXTTAB_ENDTAB(name);
}

QTE_LANYUI




