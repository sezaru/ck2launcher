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

#ifndef MODS_H_
#define MODS_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

#include <QtWidgets/QListWidget>

#pragma GCC diagnostic pop

#include <string>
#include <map>

#include "mod.hpp"

class Mods
{
public:
  Mods(void) = default;
  explicit Mods(QListWidget * uiMods);
  
  void
  load(void);

  std::map<std::string, Mod>::iterator
  begin(void);

  std::map<std::string, Mod>::const_iterator
  cbegin(void) const;

  std::map<std::string, Mod>::iterator
  end(void);

  std::map<std::string, Mod>::const_iterator
  cend(void) const;

  bool
  hasMod(const std::string & name);
  
  Mod &
  mod(const std::string & name);

private:
  std::map<std::string, Mod> mods_;

  QListWidget * uiMods_ = nullptr;
};

#endif // MODS_H_
