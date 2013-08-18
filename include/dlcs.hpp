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

#ifndef DLCS_H_
#define DLCS_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

#include <QtWidgets/QListWidget>

#pragma GCC diagnostic pop

#include <string>
#include <map>

#include "dlc.hpp"

class Dlcs
{
public:
  Dlcs(void) = default;
  explicit Dlcs(QListWidget * uiDlcs);
  
  void
  load(void);

  std::map<std::string, Dlc>::iterator
  begin(void);

  std::map<std::string, Dlc>::const_iterator
  cbegin(void) const;

  std::map<std::string, Dlc>::iterator
  end(void);

  std::map<std::string, Dlc>::const_iterator
  cend(void) const;

  bool
  hasDlc(const std::string & name);
  
  Dlc &
  dlc(const std::string & name);

private:
  std::map<std::string, Dlc> dlcs_;

  QListWidget * uiDlcs_ = nullptr;
};

#endif // DLCS_H_
