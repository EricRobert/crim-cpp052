// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"
#include "Factory.hpp"
#include "World.hpp"

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

void Plugin::spawn(World * world) {
  int x = std::rand() % world->getWidth();
  int y = std::rand() % world->getHeight();
  factory->spawn((float) x, (float) y);
}

void Plugin::spawn(float x, float y) {
  factory->spawn(x, y);
}

void Plugin::draw() {
  factory->draw();
}

void Plugin::step(World * world) {
  factory->step(world);
}
