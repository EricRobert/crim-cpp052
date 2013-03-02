// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"

Plugin::Plugin(char const * name) : Library(name) {
  typedef Factory * (* CallType)();
  CallType function = reinterpret_cast<CallType>(getSymbol("initialize"));
  if(!function) {
    throw std::exception("Cannot find 'initialize' symbol");
  }

  factory = function();
  if(!factory) {
    throw std::exception("Cannot create factory");
  }
}
