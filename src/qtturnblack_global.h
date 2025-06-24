#pragma execution_character_set("utf-8")

#ifndef QTTURNBLACK_GLOBAL_H
#define QTTURNBLACK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTTURNBLACK_LIBRARY)
#define QTTURNBLACK_EXPORT Q_DECL_EXPORT
#else
#define QTTURNBLACK_EXPORT Q_DECL_IMPORT
#endif

#endif // QTTURNBLACK_GLOBAL_H
