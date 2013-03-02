// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef PLUGIN__INCLUDED
#define PLUGIN__INCLUDED

#include "Library.hpp"

class Factory;

class Plugin : public Library
{
public:
  Plugin(char const * name);

  Factory * getFactory() const {
    return factory;
  }

private:
  Factory * factory;
};

#endif
