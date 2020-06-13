#ifndef LSS2UPDOWNTOOLBUTTON_H
#define LSS2UPDOWNTOOLBUTTON_H
#include<QObject>
const QString LSS_TOOLBUTTON_SELECTUPDOWN=
        "QToolButton{padding-top:-1px;background:#ffffff;color:#505050;border:none;}"
        "QFrame QToolButton:hover{background:#efefef;border:1px solid #ececec;}"
        "QToolButton:pressed{ background:#cecece;}"
        "QToolButton::menu-indicator::image{width:6px;height:6px;subcontrol-position:bottom center;bottom:4px;}"


        "QToolButton::menu-indicator:pressed{top:-5px; left:-1px;};";

#endif // LSS2UPDOWNTOOLBUTTON_H
