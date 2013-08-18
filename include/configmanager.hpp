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

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

#include <QtCore/QSettings>

#pragma GCC diagnostic pop

#include <string>

#include "singleton.hpp"

class ConfigManager : public Singleton<ConfigManager>
{
public:
  std::string
  gamePath(void) const;

  void
  gamePath(const std::string & path);

  std::string
  configPath(void) const;

  void
  configPath(const std::string & path);

  std::string
  registerUrl(void) const;

  bool
  bumblebee(void) const;

  void
  bumblebee(bool status);

  std::string
  bumblebeeCommand(void) const;

  void
  bumblebeeCommand(const std::string & command);

  bool
  modEnabled(const std::string & name) const;

  void
  modEnabled(const std::string & name, bool status);

  
  bool
  dlcEnabled(const std::string & name) const;

  void
  dlcEnabled(const std::string & name, bool status);

private:
  QSettings settings_{"Crusader Kings 2 Launcher", "Crusader Kings 2 Launcher"};
};

#endif // CONFIGMANAGER_H_
