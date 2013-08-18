// ck2launcher - A Qt5 launcher for Crusader Kings 2 game.
// Copyright (C) 2013  Eduardo Barreto Alexandre

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

#include "gui/launcher.hpp"

#include <QtWebKitWidgets/QWebFrame>
#include <QtWidgets/QDesktopWidget>
#include <QtGui/QDesktopServices>
#include <QtCore/QProcess>

#include "ioutils.hpp"
#include "gui/configuration.hpp"

namespace Gui
{
  ////// PUBLIC METHODS //////

  Launcher::Launcher(QWidget * const parent) : QMainWindow{parent, Qt::Dialog}
  {
    ui_.setupUi(this);

    // Move window to center of the screen
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Disable QWebNav scrollbars
    ui_.news_->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    ui_.news_->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);

    mods_ = Mods{ui_.mods_};
    mods_.load();

    dlcs_ = Dlcs{ui_.dlcs_};
    dlcs_.load();
    
    connect(ui_.dlcs_, &QListWidget::itemChanged, [&] (const QListWidgetItem * const item)
            {
              if (dlcs_.hasDlc(item->text().toStdString()))
                dlcs_.dlc(item->text().toStdString()).enabled(item->checkState() ? true : false);
            });

    connect(ui_.mods_, &QListWidget::itemChanged, [&] (const QListWidgetItem * const item)
            {
              if (mods_.hasMod(item->text().toStdString()))
                mods_.mod(item->text().toStdString()).enabled(item->checkState() ? true : false);
            });

    connect(ui_.register_, &QPushButton::clicked, [&]
            {
              QDesktopServices::openUrl(QUrl{configManager_.registerUrl().c_str()});
            });

    connect(ui_.config_, &QPushButton::clicked, [&]
            {
              Gui::Configuration configuration;
              if (!configuration.exec())
                return;

              mods_.load();
              dlcs_.load();
            });

    connect(ui_.start_, &QPushButton::clicked, [&]
            {
              auto arguments = QStringList{};

              auto command = configManager_.bumblebeeCommand();
              if (configManager_.bumblebee())
                arguments << "./ck2";
              else
                command = "./ck2";
              
              for (const auto & dlcPair : dlcs_)
                if (!dlcPair.second.enabled())
                  arguments << ("-exclude_dlc=dlc/" + dlcPair.second.fileName()).c_str();

              for (const auto & modPair : mods_)
                if (modPair.second.enabled())
                  arguments << ("-mod=mod/" + modPair.second.fileName()).c_str();

              QProcess::startDetached(command.c_str(), arguments, configManager_.gamePath().c_str());
              
              QApplication::quit();
            });
  }
}
