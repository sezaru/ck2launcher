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

#include "ioutils.hpp"

#include <boost/filesystem.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include "iohelpers.hpp"

namespace IOUtils
{
  Files
  listFiles(const std::string & directoryPath, const std::string & extension)
  {
    auto directory = boost::filesystem::path{directoryPath};

    if (!boost::filesystem::exists(directory) || !boost::filesystem::is_directory(directory))
      return Files{};

    auto files = Files{};

    for (const auto & file : IOHelpers::Directory{directory})
      if (boost::filesystem::is_regular_file(file.status()))
        if (extension.empty() || (!extension.empty() && file.path().extension() == extension))
          files.emplace_back(file.path().string());
    
    return files;
  }

  std::string
  extractName(const std::string & filePath)
  {
    std::ifstream file{filePath};
    if (!file.is_open())
    {
      std::cerr << "Error: File " << filePath << " failed to open!" << std::endl;
      return std::string{};
    }

    auto line = std::string{}, name = std::string{};
    while (file.good())
    {
      std::getline(file, line);
    
      std::stringstream ss{line};
      std::string parameter;
      ss >> parameter;

      if (parameter != "name")
        continue;
    
      name = line.substr(line.find_first_of('"') + 1);
      name = name.substr(0, name.find_last_of('"'));
    }

    return name;
  }
}
