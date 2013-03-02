// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef PLUGIN__INCLUDED
#define PLUGIN__INCLUDED

#include "Library.hpp"

class Plugin : public Library
{
public:
  Plugin(char const * name);
  int initialize();

private:
  CallType callback;
};

#endif
