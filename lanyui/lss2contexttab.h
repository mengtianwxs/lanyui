#ifndef LSS2CONTEXTTAB_H
#define LSS2CONTEXTTAB_H
#include "lss2base.h"

const QString CO_TabDefBG="#14af75";//单纯的设置颜色
const QString CO_TabDefWord="#ffffff";

const QString StyleSheet_WidTabBG="background:#14af75;";//设置Tab背景颜色
const QString StyleSheet_WidPageBG="QWidget#wid_page{background:#ffffff;border-bottom:1 solid #cccccc;}";//设置Page背景颜色需要添加大括号不然会给widget下所有控件添加下边框线
const QString StyleSheet_DefaultTabBG="QToolButton{padding-top:-1px;background:#14af75;color:#ffffff;border:none;}";
const QString StyleSheet_SelectTab="QToolButton{padding-top:-1px;background:#ffffff;color:#505050;border:none;}";


#endif // LSS2CONTEXTTAB_H
