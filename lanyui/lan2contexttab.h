#ifndef LAN2ContextTab_H
#define LAN2ContextTab_H
#include "lanyui/styles/lss2assets.h"
#include "lanyui/styles/lss2contexttab.h"
#include "lan2endshoworhidetab.h"


#include "lan2page.h"
#include "lan2rtab.h"
#include "lan2tab.h"
#include "lan2starttab.h"
#include <QBoxLayout>
#include <QObject>
#include <QWidget>
#include<QMap>
#include "lan2global.h"

QTB_LANYUI
class Lan2ContextTab : public QWidget
{
    Q_OBJECT
public:

    enum State{
        SHOW,
        HIDE
    };
    explicit Lan2ContextTab(QWidget *parent = nullptr);
    void bindMainTabAndPage(Lan2Tab* tb,Lan2Page* page);
    void addRightTab(Lan2RTab* rtb);
    void addEndShowOrHideTab(QString path1,QString path2);
    void addStartTab(Lan2StartTab* ltb);
    void endTabAndPage();

    Lan2Page* getPageByIndex(int i);//没有实现
    Lan2Tab* getMTabByIndex(int i);//没有实现
    Lan2Tab* getRTabByIndex(int i);//没有实现

    Lan2Tab* getTabByObjectName(QString tab_name);
    Lan2Page* getPageByObjectName(QString page_name);
    Lan2StartTab* getStartTabByObjectName(QString tab_name);
    Lan2RTab* getRightTabByObjectName(QString tab_name);
    Lan2EndShowOrHideTab* getEndShowOrHideTabByObjectName(QString name);

    void hidePage();
    void deleteAllPage();

    void showPage();
    void init(QString name);
    void initStartTab(QString name);

    void addStartAndInitTab(Lan2StartTab* ltb,QString name);
    void setEndTabState(State state);
//    Stage get


public:
    QHBoxLayout* tabHBox;
    QHBoxLayout* pageHBox;
    QVBoxLayout* mainVbox;

    QVector<Lan2Tab*> vec_tabs;
    QVector<Lan2RTab*> vec_rtabs;
    QVector<Lan2Page*> vec_pages;

    int cout_tabs;

    QWidget* wid_tab;
    QWidget* wid_page;


private:
    QVector<Lan2Page*> vec_selectPage;
    int times=0;
    QString endpath1="";
    QString endpath2="";
    Lan2EndShowOrHideTab* endtb;
    State lanstate;
signals:
    void CONTEXTTAB_STARTTAB(QString name);
    void CONTEXTTAB_ENDTAB(QString name);
    void CONTEXTTAB_RTAB(QString name);


protected slots:
    void method_tab(QString name);
    void method_start_tab(QString name);
    void method_right_tab(QString name);
    void method_end_tab(QString name);

};
QTE_LANYUI
#endif // LAN2ContextTab_H
