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

#include "dlcs.hpp"

#include "ioutils.hpp"
#include "configmanager.hpp"

////// PUBLIC METHODS //////

Dlcs::Dlcs(QListWidget * uiDlcs) : uiDlcs_{uiDlcs}
{ }

void
Dlcs::load(void)
{
  if (uiDlcs_ == nullptr)
    return;

  auto & configManager = ConfigManager::singleton();

  dlcs_.clear();
  for (const auto & file : IOUtils::listFiles(configManager.gamePath() + "/dlc", ".dlc"))
    dlcs_.insert(std::make_pair(IOUtils::extractName(file), Dlc{file}));

  uiDlcs_->clear();
  for (const auto & dlc : dlcs_)
    uiDlcs_->addItem(dlc.first.c_str());

  for (const auto & item : uiDlcs_->findItems("*", Qt::MatchWildcard))
  {
    item->setCheckState(dlcs_.at(item->text().toStdString()).enabled() ? Qt::Checked : Qt::Unchecked);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
  }
}

std::map<std::string, Dlc>::iterator
Dlcs::begin(void)
{
  return std::begin(dlcs_);
}

std::map<std::string, Dlc>::const_iterator
Dlcs::cbegin(void) const
{
  return dlcs_.cbegin();
}

std::map<std::string, Dlc>::iterator
Dlcs::end(void)
{
  return std::end(dlcs_);
}

std::map<std::string, Dlc>::const_iterator
Dlcs::cend(void) const
{
  return dlcs_.cend();
}

bool
Dlcs::hasDlc(const std::string & name)
{
  return dlcs_.find(name) != std::end(dlcs_) ? true : false;
}

Dlc &
Dlcs::dlc(const std::string & name)
{
  return dlcs_.at(name);
}
