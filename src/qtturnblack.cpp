#pragma execution_character_set("utf-8")

#include "qtturnblack.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QGuiApplication>


namespace Qtturnblack {

static Color _lasttime_color = Color::Default;
static QPair<bool, QPalette> _default_palette;

qtb get(const Color &color) {
    if (_lasttime_color == Color::Default && !_default_palette.first) {
        _default_palette.first = true;
        _default_palette.second = qApp->palette();
    }
    _lasttime_color = color;

    qtb result;
    result.color = color;
    result.palette = _default_palette.second;

    QString root_path(":/qtturnblack/resource");

    if (color == Color::White) {
    } else if (color == Color::Dark) {
    } else if (color == Color::Gray) {
        result.palette.setColor(QPalette::Base, QColor(53, 53, 53));
        result.palette.setColor(QPalette::Window, QColor(53, 53, 53));
        result.palette.setColor(QPalette::Button, QColor(53, 53, 53));

        result.palette.setColor(QPalette::Light, QColor(95, 95, 95));
        result.palette.setColor(QPalette::Midlight, QColor(255, 255, 53));
        result.palette.setColor(QPalette::Dark, QColor(172, 172, 172));
        result.palette.setColor(QPalette::Mid, QColor(222, 222, 222));
        result.palette.setColor(QPalette::Shadow, QColor(53, 255, 255));

        result.palette.setColor(QPalette::PlaceholderText, QColor(163, 163, 163));

        result.palette.setColor(QPalette::ToolTipBase, QColor(53, 53, 53));
        result.palette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));

        result.palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
        result.palette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
        result.palette.setColor(QPalette::AlternateBase, QColor(73, 73, 73));

        result.palette.setColor(QPalette::Text, QColor(255, 255, 255));
        result.palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
        result.palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));

        result.palette.setColor(QPalette::ColorGroup::Inactive, QPalette::Button, QColor(53, 53, 53));

        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::Base, QColor(44, 44, 44));
        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::Window, QColor(44, 44, 44));
        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::Button, QColor(44, 44, 44));

        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::Highlight, QColor(118, 118, 118));

        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::Text, QColor(155, 155, 155));
        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::WindowText, QColor(155, 155, 155));
        result.palette.setColor(QPalette::ColorGroup::Disabled, QPalette::ButtonText, QColor(155, 155, 155));


        result.palette.setColor(QPalette::BrightText, QColor(255, 255, 0));


    } else if (color == Color::Default) {
        // result.palette.setColor(QPalette::Window, QColor(240, 240, 240));
        // result.palette.setColor(QPalette::Button, QColor(240, 240, 240));
    }

    if (color == Color::Gray) {
        const QString &image_path = root_path + "/image/gray";
        const QString &style_path = root_path + "/style/gray";
        QDir path(style_path);
        foreach (const auto &i, path.entryList(QDir::Filter::Files)) {
            QFile file(path.absoluteFilePath(i));
            file.open(QIODevice::ReadOnly);
            QString file_data = QString::fromUtf8(file.readAll());
            file.close();
            file_data = file_data.replace("ARG_ImagePath", image_path)
                            .replace("ARG_MenuItemLeftSpan",
#ifdef Q_OS_WIN
                                     "24"
#else
                                     "4"
#endif
                                     )
                            .replace("ARG_GroupTitleUpto",
#ifdef Q_OS_WIN
                                     "7ex"
#else
                                     "3.5ex"
#endif
                            );
            // qDebug() << i;
            // QStringList sl{"QTreeWidget.css",};
            // if (sl.contains(i)) {
            //     continue;
            // }
            result.styleSheet += file_data;
            // qApp->setStyleSheet(result.styleSheet);
        };
    }

    return result;
}


} // namespace Qtturnblack
