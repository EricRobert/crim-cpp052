// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef LIBRARY__INCLUDED
#define LIBRARY__INCLUDED

#include <string>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

class Library
{
public:
  Library();
  Library(char const * filename);

  Library(Library const & other);
  Library & operator=(Library const & other);

  ~Library();

  void load(char const * filename);
  void unload();

protected:
  std::string name;
  HMODULE library;
};

#endif
