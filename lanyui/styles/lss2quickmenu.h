#ifndef LSS2QUICKMENU_H
#define LSS2QUICKMENU_H
#include "lss2base.h"
const QString LSS_QuickMenu_BG="background:transparent";
const QString LSS_QuickMenu_TB=
        "QToolButton{padding-top:-1px;background:transparent;border:none;}"
        "QToolButton:hover{background:#00a06e;}"
       ;

const QString LSS_QuickMenu_TBEnd=
        "QToolButton{padding-top:-1px;background:transparent;border:none;color:#ffffff;}"
        "QToolButton:hover{background:#00a06e;}"
         "QToolButton::menu-indicator{image:None;}"
       ;


const QString LSS_QuickMenu_EndTB=
        "QToolButton::menu-indicator{image:None;}"
        "QToolButton{padding-top:-1px;background:transparent;border:none;color:#505050}"
        "QToolButton:hover{background:##00a06e;}"
        ;


#endif // LSS2QUICKMENU_H
