// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"

Plugin::Plugin(char const * name) : Library(name) {
  if(library) {
    callback = GetProcAddress(library, "initialize");
  }
}

int Plugin::initialize() {
  return callback ? (*callback)() : 0;
}
