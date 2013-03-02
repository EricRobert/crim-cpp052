// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"
#include "Factory.hpp"
#include "Bot.hpp"

#include <algorithm>

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

void Plugin::spawn(float x, float y) {
  Bot * item = factory->spawn(x, y);
  if(item) {
    items.push_back(item);
  }
}

void Plugin::draw() {
  std::for_each(items.begin(), items.end(), std::mem_fun(&Bot::draw));
}

void Plugin::step(World * world) {
  factory->step(world);
}
