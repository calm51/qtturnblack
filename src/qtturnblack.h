#pragma execution_character_set("utf-8")

#ifndef QTTURNBLACK_H
#define QTTURNBLACK_H

#include "qtturnblack_global.h"

#include <qpair.h>
#include <qpalette.h>

namespace Qtturnblack {

enum class Color {
    Light = 0,   // 纯白背景
    Dark = 1,    // 夜间模式
    Gray = 2,    // Fusion灰
    Default = 3, // 算是重置
};

struct QTTURNBLACK_EXPORT qtb {
    Color color;
    QString styleSheet;
    QPalette palette;
};

qtb QTTURNBLACK_EXPORT get(const Color &color);

} // namespace Qtturnblack


#endif // QTTURNBLACK_H
