#include "lan2gridmenu.h"


QTB_LANYUI
Lan2GridMenu::Lan2GridMenu(int width, int height)
{
    if(width==0 or height==0){

    }else{
        this->setFixedWidth(width);
        this->setFixedHeight(height);
    }

    grid=new QGridLayout();
    grid->setSpacing(2);
    grid->setContentsMargins(2,2,2,2);
    grid->setMargin(2);

    this->setLayout(grid);

}

void Lan2GridMenu::addToolButtonMat(QVector<QToolButton *> qtb, int row, int col)
{
    int r=row;
    int c=col;
    int rc=row*col;//行数、列数
    int cout=qtb.count();//ToolButton的总数
//    rc的数量只能大于或等于cout
    if(rc>=cout){
//init ToolButton style and size
        for(int m=0;m<cout;m++){

            qtb[m]->setFixedSize(C_GridMenu_TBDEFWidth,C_GridMenu_TBDEFHeight);
            qtb[m]->setStyleSheet(LSS_TB_BG);
        }}

        //如果正好相等，则排满布局,先扫描列，再扫描行
        if(rc==cout){
             int temp=0;
            for(int l=0;l<c;l++){
                for(int h=0;h<r;h++){
                  temp=temp+1;
                  grid->addWidget(qtb[temp-1],h,l);
                }
            }
        }


    else if(rc>cout){

        int tp=0;
        int ctemp=rc-cout;

       for(int l=0;l<c;l++){
           for(int h=0;h<r;h++){
             tp=tp+1;
             if(tp<=cout ){
              grid->addWidget(qtb[tp-1],l,h);
             }


           }
       }
   }

    else{
        qDebug()<<"error";
    }

    //grid->addWidget(qtb,0,0);


}


QTE_LANYUI
