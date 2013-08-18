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

#ifndef GUI_LAUNCHER_H_
#define GUI_LAUNCHER_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

#include <QtWidgets/QMainWindow>

#include "ui_launcher.h"

#pragma GCC diagnostic pop

#include "dlcs.hpp"
#include "mods.hpp"
#include "configmanager.hpp"

namespace Gui
{
  class Launcher : public QMainWindow
  {
  public:
    explicit Launcher(QWidget * const parent = nullptr);

  private:
    Ui::Launcher ui_;

    Dlcs dlcs_;
    Mods mods_;

    ConfigManager configManager_;
  };
}

#endif // GUI_LAUNCHER_H_
