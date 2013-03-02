// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"

Plugin::Plugin(char const * name) : Library(name) {
  callback = getSymbol("initialize");
  if(!callback) {
    throw std::exception("Cannot find 'initialize' symbol");
  }
}

int Plugin::initialize() {
  return (*callback)();
}
