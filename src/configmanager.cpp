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

#include "configmanager.hpp"

#include <QtCore/QDir>

////// PUBLIC METHODS //////

std::string
ConfigManager::gamePath(void) const
{
  return settings_.value("directory/game", QDir::homePath() + "/.local/share/Steam/SteamApps/common/Crusader Kings II").
    toString().toStdString();
}

void
ConfigManager::gamePath(const std::string & path)
{
  settings_.setValue("directory/game", path.c_str());
}

std::string
ConfigManager::configPath(void) const
{
  return settings_.value("directory/config", QDir::homePath() + "/Documents/Paradox Interactive/Crusader Kings II").
    toString().toStdString();
}

void
ConfigManager::configPath(const std::string & path)
{
  settings_.setValue("directory/config", path.c_str());
}

std::string
ConfigManager::registerUrl(void) const
{
  return settings_.value("web/register", "http://forum.paradoxplaza.com/forum/mygames.php").toString().toStdString();
}

bool
ConfigManager::bumblebee(void) const
{
  return settings_.value("bumblebee/enabled", false).toBool();
}

void
ConfigManager::bumblebee(const bool status)
{
  settings_.setValue("bumblebee/enabled", status);
}

std::string
ConfigManager::bumblebeeCommand(void) const
{
  return settings_.value("bumblebee/command", "optirun").toString().toStdString();
}

void
ConfigManager::bumblebeeCommand(const std::string & command)
{
  settings_.setValue("bumblebee/command", command.c_str());
}

bool
ConfigManager::modEnabled(const std::string & name) const
{
  return settings_.value(("mod/" + name).c_str(), true).toBool();
}

void
ConfigManager::modEnabled(const std::string & name, const bool status)
{
  settings_.setValue(("mod/" + name).c_str(), status);
}

bool
ConfigManager::dlcEnabled(const std::string & name) const
{
  return settings_.value(("dlc/" + name).c_str(), true).toBool();
}

void
ConfigManager::dlcEnabled(const std::string & name, const bool status)
{
  settings_.setValue(("dlc/" + name).c_str(), status);
}
