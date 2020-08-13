#ifndef LAN2GLOBAL_H
#define LAN2GLOBAL_H
#include<QDebug>
#include <QtGlobal>
#define QTB_LANYUI namespace LANYUI {
#define QTE_LANYUI }
#define QTU_LANYUI using namespace LANYUI;

#if defined (LANYUI)
#undef LANYUI
#define LANYUI "power by mengtianwxs 2020"
#endif

#endif // LAN2GLOBAL_H
