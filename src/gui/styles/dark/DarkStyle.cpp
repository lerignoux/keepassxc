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

#include "DarkStyle.h"
#ifdef Q_OS_MACOS
#include "gui/macutils/MacUtils.h"
#endif

#include <QDialog>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>

void DarkStyle::polish(QPalette& palette)
{
    palette.setColor(QPalette::Active, QPalette::Window, QStringLiteral("#3B3D3C"));
    palette.setColor(QPalette::Inactive, QPalette::Window, QStringLiteral("#363736"));
    palette.setColor(QPalette::Disabled, QPalette::Window, QStringLiteral("#444846"));

    palette.setColor(QPalette::Active, QPalette::WindowText, QStringLiteral("#CBCFCB"));
    palette.setColor(QPalette::Inactive, QPalette::WindowText, QStringLiteral("#C1C8C1"));
    palette.setColor(QPalette::Disabled, QPalette::WindowText, QStringLiteral("#7A857A"));

    palette.setColor(QPalette::Active, QPalette::Base, QStringLiteral("#2F2F2F"));
    palette.setColor(QPalette::Inactive, QPalette::Base, QStringLiteral("#2A2B2B"));
    palette.setColor(QPalette::Disabled, QPalette::Base, QStringLiteral("#373937"));

    palette.setColor(QPalette::Active, QPalette::AlternateBase, QStringLiteral("#343635"));
    palette.setColor(QPalette::Inactive, QPalette::AlternateBase, QStringLiteral("#333433"));
    palette.setColor(QPalette::Disabled, QPalette::AlternateBase, QStringLiteral("#3D3F3C"));

    palette.setColor(QPalette::All, QPalette::ToolTipBase, QStringLiteral("#171717"));
    palette.setColor(QPalette::All, QPalette::ToolTipText, QStringLiteral("#BABFBA"));

#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 0))
    palette.setColor(QPalette::Active, QPalette::PlaceholderText, QStringLiteral("#7A827A"));
    palette.setColor(QPalette::Inactive, QPalette::PlaceholderText, QStringLiteral("#717871"));
    palette.setColor(QPalette::Disabled, QPalette::PlaceholderText, QStringLiteral("#5E675E"));
#endif

    palette.setColor(QPalette::Active, QPalette::Text, QStringLiteral("#CBCFCB"));
    palette.setColor(QPalette::Inactive, QPalette::Text, QStringLiteral("#C1C8C1"));
    palette.setColor(QPalette::Disabled, QPalette::Text, QStringLiteral("#7A857A"));

    palette.setColor(QPalette::Active, QPalette::Button, QStringLiteral("#343635"));
    palette.setColor(QPalette::Inactive, QPalette::Button, QStringLiteral("#303130"));
    palette.setColor(QPalette::Disabled, QPalette::Button, QStringLiteral("#343634"));

    palette.setColor(QPalette::Active, QPalette::ButtonText, QStringLiteral("#B9BEB9"));
    palette.setColor(QPalette::Inactive, QPalette::ButtonText, QStringLiteral("#9EA59E"));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QStringLiteral("#737E73"));

    palette.setColor(QPalette::Active, QPalette::BrightText, QStringLiteral("#CBCFCB"));
    palette.setColor(QPalette::Inactive, QPalette::BrightText, QStringLiteral("#CBCFCB"));
    palette.setColor(QPalette::Disabled, QPalette::BrightText, QStringLiteral("#CBCFCB"));

    palette.setColor(QPalette::All, QPalette::Light, QStringLiteral("#474948"));
    palette.setColor(QPalette::All, QPalette::Midlight, QStringLiteral("#373838"));
    palette.setColor(QPalette::All, QPalette::Dark, QStringLiteral("#242525"));
    palette.setColor(QPalette::All, QPalette::Mid, QStringLiteral("#2E2F2F"));
    palette.setColor(QPalette::All, QPalette::Shadow, QStringLiteral("#171817"));

    palette.setColor(QPalette::Active, QPalette::Highlight, QStringLiteral("#345B20"));
    palette.setColor(QPalette::Inactive, QPalette::Highlight, QStringLiteral("#2F4B21"));
    palette.setColor(QPalette::Disabled, QPalette::Highlight, QStringLiteral("#344929"));

    palette.setColor(QPalette::Active, QPalette::HighlightedText, QStringLiteral("#E6E9E6"));
    palette.setColor(QPalette::Inactive, QPalette::HighlightedText, QStringLiteral("#C5CCC5"));
    palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QStringLiteral("#344929"));

    palette.setColor(QPalette::All, QPalette::Link, QStringLiteral("#76A65E"));
    palette.setColor(QPalette::All, QPalette::LinkVisited, QStringLiteral("#5B8048"));
}

QStringList DarkStyle::getAppStyleSheetPaths() const
{
    return {QStringLiteral(":/styles/dark/darkstyle.qss")};
}

void DarkStyle::polish(QWidget* widget)
{
    if (qobject_cast<QMainWindow*>(widget) || qobject_cast<QDialog*>(widget) || qobject_cast<QMenuBar*>(widget)
        || qobject_cast<QToolBar*>(widget)) {
        auto palette = widget->palette();
#ifdef Q_OS_MACOS
        if (MacUtils::instance()->isDarkMode()) {
            // Let the Cocoa platform plugin draw its own background
            palette.setColor(QPalette::All, QPalette::Window, Qt::transparent);
        } else {
            palette.setColor(QPalette::Active, QPalette::Window, QStringLiteral("#2A2A2A"));
            palette.setColor(QPalette::Inactive, QPalette::Window, QStringLiteral("#2D2D2D"));
            palette.setColor(QPalette::Disabled, QPalette::Window, QStringLiteral("#2A2A2A"));
        }
#else
        palette.setColor(QPalette::All, QPalette::Window, QStringLiteral("#2B2B2B"));
#endif
        widget->setPalette(palette);
    }
}