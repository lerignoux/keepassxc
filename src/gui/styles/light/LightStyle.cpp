/*
 *  Copyright (C) 2020 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "LightStyle.h"
#include "gui/ApplicationSettingsWidget.h"
#ifdef Q_OS_MACOS
#include "gui/macutils/MacUtils.h"
#endif

#include <QDialog>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>

void LightStyle::polish(QPalette& palette)
{
#if defined(Q_OS_WIN)
    palette.setColor(QPalette::All, QPalette::Window, QStringLiteral("#F9F9F9"));
#else
    palette.setColor(QPalette::Active, QPalette::Window, QStringLiteral("#F9F9F9"));
    palette.setColor(QPalette::Inactive, QPalette::Window, QStringLiteral("#F4F4F4"));
    palette.setColor(QPalette::Disabled, QPalette::Window, QStringLiteral("#EDEDEE"));
#endif

    palette.setColor(QPalette::Active, QPalette::WindowText, QStringLiteral("#080809"));
    palette.setColor(QPalette::Inactive, QPalette::WindowText, QStringLiteral("#18181A"));
    palette.setColor(QPalette::Disabled, QPalette::WindowText, QStringLiteral("#828389"));

    palette.setColor(QPalette::Active, QPalette::Base, QStringLiteral("#F9F9F9"));
    palette.setColor(QPalette::Inactive, QPalette::Base, QStringLiteral("#F5F5F4"));
    palette.setColor(QPalette::Disabled, QPalette::Base, QStringLiteral("#EFEFF2"));

    palette.setColor(QPalette::Active, QPalette::AlternateBase, QStringLiteral("#ECF3E8"));
    palette.setColor(QPalette::Inactive, QPalette::AlternateBase, QStringLiteral("#EAF2E6"));
    palette.setColor(QPalette::Disabled, QPalette::AlternateBase, QStringLiteral("#E1E9DD"));

    palette.setColor(QPalette::All, QPalette::ToolTipBase, QStringLiteral("#538D1D"));
    palette.setColor(QPalette::All, QPalette::ToolTipText, QStringLiteral("#F3F3F4"));

#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
    palette.setColor(QPalette::Active, QPalette::PlaceholderText, QStringLiteral("#71727D"));
    palette.setColor(QPalette::Inactive, QPalette::PlaceholderText, QStringLiteral("#878893"));
    palette.setColor(QPalette::Disabled, QPalette::PlaceholderText, QStringLiteral("#A3A4AC"));
#endif

    palette.setColor(QPalette::Active, QPalette::Text, QStringLiteral("#080809"));
    palette.setColor(QPalette::Inactive, QPalette::Text, QStringLiteral("#18181A"));
    palette.setColor(QPalette::Disabled, QPalette::Text, QStringLiteral("#828389"));

    palette.setColor(QPalette::Active, QPalette::Button, QStringLiteral("#D4D5DD"));
    palette.setColor(QPalette::Inactive, QPalette::Button, QStringLiteral("#DADBDA"));
    palette.setColor(QPalette::Disabled, QPalette::Button, QStringLiteral("#E7E8E8"));

    palette.setColor(QPalette::Active, QPalette::ButtonText, QStringLiteral("#181A18"));
    palette.setColor(QPalette::Inactive, QPalette::ButtonText, QStringLiteral("#5F6671"));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QStringLiteral("#9499A0"));

    palette.setColor(QPalette::Active, QPalette::BrightText, QStringLiteral("#F3F3F4"));
    palette.setColor(QPalette::Inactive, QPalette::BrightText, QStringLiteral("#EDEFFD"));
    palette.setColor(QPalette::Disabled, QPalette::BrightText, QStringLiteral("#C6D7BE"));

    palette.setColor(QPalette::All, QPalette::Light, QStringLiteral("#F8F9FA"));
    palette.setColor(QPalette::All, QPalette::Midlight, QStringLiteral("#E8E9EC"));
    palette.setColor(QPalette::All, QPalette::Dark, QStringLiteral("#B9BAC4"));
    palette.setColor(QPalette::All, QPalette::Mid, QStringLiteral("#C8C9D0"));
    palette.setColor(QPalette::All, QPalette::Shadow, QStringLiteral("#6B6D7A"));

    palette.setColor(QPalette::Active, QPalette::Highlight, QStringLiteral("#59A314"));
    palette.setColor(QPalette::Inactive, QPalette::Highlight, QStringLiteral("#56961A"));
    palette.setColor(QPalette::Disabled, QPalette::Highlight, QStringLiteral("#638F50"));

    palette.setColor(QPalette::Active, QPalette::HighlightedText, QStringLiteral("#F3F3F4"));
    palette.setColor(QPalette::Inactive, QPalette::HighlightedText, QStringLiteral("#EDEFFD"));
    palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QStringLiteral("#C6D7BE"));

    palette.setColor(QPalette::All, QPalette::Link, QStringLiteral("#3E9A10"));
    palette.setColor(QPalette::All, QPalette::LinkVisited, QStringLiteral("#418D1A"));
}

QStringList LightStyle::getAppStyleSheetPaths() const
{
    QStringList stylesheets = {QStringLiteral(":/styles/light/lightstyle.qss")};
#ifdef Q_OS_WIN
    stylesheets << QStringLiteral(":/styles/light/lightstyle-win.qss");
#endif
    return stylesheets;
}

void LightStyle::polish(QWidget* widget)
{
    if (qobject_cast<QMainWindow*>(widget) || qobject_cast<QDialog*>(widget)
        || qobject_cast<QMenuBar*>(widget) || qobject_cast<QToolBar*>(widget)) {
        auto palette = widget->palette();
#ifdef Q_OS_MACOS
        if (!MacUtils::instance()->isDarkMode()) {
            // Let the Cocoa platform plugin draw its own background
            palette.setColor(QPalette::All, QPalette::Window, Qt::transparent);
        } else {
            palette.setColor(QPalette::Active, QPalette::Window, QStringLiteral("#D6D6D6"));
            palette.setColor(QPalette::Inactive, QPalette::Window, QStringLiteral("#F6F6F6"));
            palette.setColor(QPalette::Disabled, QPalette::Window, QStringLiteral("#D4D4D4"));
        }
#else
        palette.setColor(QPalette::All, QPalette::Window, QStringLiteral("#FFFFFF"));
#endif
        widget->setPalette(palette);
    }
}
