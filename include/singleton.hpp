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

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <cassert>

template <typename T>
class Singleton
{
public:
  Singleton(void)
  {
    assert(!singleton_);
    singleton_ = static_cast<T *>(this);
  }

  ~Singleton(void)
  {
    assert(singleton_);
    singleton_ = nullptr;
  }

  static T &
  singleton(void)
  {
    assert(singleton_);
    return *singleton_;
  }

  static T *
  singletonPtr(void)
  {
    assert(singleton_);
    return singleton_;
  }

private:
  Singleton(const Singleton<T> &);
  
  Singleton &
  operator=(const Singleton<T> &);

protected:
  static T * singleton_;
};

template <typename T> T* Singleton<T>::singleton_ = nullptr;

#endif // SINGLETON_H_
