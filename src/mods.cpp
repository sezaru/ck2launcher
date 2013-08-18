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

#include "mods.hpp"

#include "ioutils.hpp"
#include "configmanager.hpp"

////// PUBLIC METHODS //////

Mods::Mods(QListWidget * uiMods) : uiMods_{uiMods}
{ }

void
Mods::load(void)
{
  if (uiMods_ == nullptr)
    return;
  
  auto & configManager = ConfigManager::singleton();

  mods_.clear();
  for (const auto & file : IOUtils::listFiles(configManager.configPath() + "/mod", ".mod"))
    mods_.insert(std::make_pair(IOUtils::extractName(file), Mod{file}));

  uiMods_->clear();
  for (const auto & mod : mods_)
    uiMods_->addItem(mod.first.c_str());
    
  for (const auto & item : uiMods_->findItems("*", Qt::MatchWildcard))
  {
    item->setCheckState(mods_.at(item->text().toStdString()).enabled() ? Qt::Checked : Qt::Unchecked);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
  }
}

std::map<std::string, Mod>::iterator
Mods::begin(void)
{
  return std::begin(mods_);
}

std::map<std::string, Mod>::const_iterator
Mods::cbegin(void) const
{
  return mods_.cbegin();
}

std::map<std::string, Mod>::iterator
Mods::end(void)
{
  return std::end(mods_);
}

std::map<std::string, Mod>::const_iterator
Mods::cend(void) const
{
  return mods_.cend();
}

bool
Mods::hasMod(const std::string & name)
{
  return mods_.find(name) != std::end(mods_) ? true : false;
}

Mod &
Mods::mod(const std::string & name)
{
  return mods_.at(name);
}
