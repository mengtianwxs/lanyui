#ifndef LSS2GROUPTOOL_H
#define LSS2GROUPTOOL_H
#include "lss2base.h"
#include <QtGlobal>




#ifdef Q_OS_LINUX
// linux
const QString LSS_TOOLBUTTON_SELECT=
        "QToolButton{padding-top:0px;background:#ffffff;color:#505050;border:none;}"
        "QToolButton:hover{background:#efefef;}"
        "QToolButton:pressed{ background:#cecece;}"
        "QToolButton::menu-indicator::image{width:6px;height:6px;subcontrol-position:bottom center;bottom:4px;}"
        "QToolButton::menu-indicator:pressed{top:0px; left:0px;};";
const QString LSS_TOOLBUTTON_DOWN=

        "QToolButton{padding-top:-2px;margin-left:1px;background:#ffffff;color:#505050;border:none;}"
        "QToolButton:hover{background:#efefef;}"
        "QToolButton:pressed{ background:#cecece;}"
        "QToolButton::menu-indicator::image{width:6px;height:6px;subcontrol-position:bottom center;bottom:2px;}"
        "QToolButton::menu-indicator:pressed{top:0px; left:0px;};";
#endif

#ifdef Q_OS_WIN
// win
const QString LSS_TOOLBUTTON_SELECT=
        "QToolButton{padding-top:-1px;background:#ffffff;color:#505050;border:none;}"
        "QToolButton:hover{background:#efefef;}"
        "QToolButton:pressed{ background:#cecece;}"
        "QToolButton::menu-indicator::image{width:6px;height:6px;subcontrol-position:bottom center;bottom:4px;}"
        "QToolButton::menu-indicator:pressed{top:-5px; left:-1px;};";
const QString LSS_TOOLBUTTON_DOWN=
        "QToolButton{padding-top:-1px;margin-left:0px;background:#ffffff;color:#505050;border:none;}"
        "QToolButton:hover{background:#efefef;}"
        "QToolButton:pressed{ background:#cecece;}"
        "QToolButton::menu-indicator::image{width:6px;height:6px;subcontrol-position:bottom center;bottom:2px;}"
        "QToolButton::menu-indicator:pressed{bottom:3px; left:-1px;};";
#endif



const QString LSS_MENU="QMenu{background:#ffffff;color:#505050;}QMenu::item:selected{background:#efefef;}";

const QString LSS_TOOLBUTTON_DEF="QToolButton{padding-top:-1px;background:#ffffff;color:#505050;border:none;}QToolButton:hover{background:#efefef;}QToolButton:pressed{ background:#cecece;};";

const QString LSS_TOOLBUTTON_UP=
        "QToolButton{padding-top:2px;margin-left:0px;background:#ffffff;color:#505050;border:none;}"
        "QToolButton:hover{background:#efefef;}"
        "QToolButton:pressed{background:#cecece;}";

const QString LSS_TOOLBUTTON_UPDOWNWI="QFrame{padding-left:1px;background:#ffffff;}QFrame:hover{background:#c7c7c7;}QFrame:pressed{background:#cecece;}";
const QString LSS_TBUPDOWN_CLICKED="QToolButton{background:#cecece};";

#endif // LSS2GROUPTOOL_H
