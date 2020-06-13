#ifndef LAN2GLOBAL_H
#define LAN2GLOBAL_H

#define QTB_LANYUI namespace LANYUI {
#define QTE_LANYUI }
#define QTUSE_LANYUI using namespace LANYUI;

#if defined (LANYUI)
#undef LANYUI
#define LANYUI "power by mengtianwxs 2020"
#endif

#endif // LAN2GLOBAL_H
