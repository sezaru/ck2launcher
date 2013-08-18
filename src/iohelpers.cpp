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

#include "iohelpers.hpp"

namespace IOHelpers
{
  ////// PUBLIC METHODS //////

  Directory::Directory(const boost::filesystem::path & path) : path_{path}
  { }

  boost::filesystem::directory_iterator
  Directory::begin(void)
  {
    return boost::filesystem::directory_iterator{path_};
  }

  boost::filesystem::directory_iterator
  Directory::end(void)
  {
    return boost::filesystem::directory_iterator{};
  }
}
