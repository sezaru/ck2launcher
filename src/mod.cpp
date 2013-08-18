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

#include "mod.hpp"

#include "ioutils.hpp"
#include "configmanager.hpp"

////// PUBLIC METHODS //////

Mod::Mod(const std::string & path) :
  fileName_{path.substr(path.find_last_of("/\\") + 1)}, name_{IOUtils::extractName(path)}
{ }

bool
Mod::enabled(void) const
{
  return ConfigManager::singleton().modEnabled(name_);
}

void
Mod::enabled(const bool status)
{
  ConfigManager::singleton().modEnabled(name_, status);
}

std::string
Mod::fileName(void) const
{
  return fileName_;
}

std::string
Mod::name(void) const
{
  return name_;
}
