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
  Library(char const * filename);

  Library(Library const & other);
  Library & operator=(Library const & other);

  ~Library();

  void swap(Library & other);

  typedef int (__stdcall * CallType)();
  CallType getSymbol(char const * id) const;

private:
  std::string name;
  HMODULE library;
};

#endif
