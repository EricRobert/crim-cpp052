// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef WORLD__INCLUDED
#define WORLD__INCLUDED

#include "Plugin.hpp"

#include <vector>

class Bot;

// repr�sentation du monde de bots
class World
{
public:
  World(int _x, int _y);

  void step();
  void draw();
  void wrap(float & i, float & j);

  int getWidth() const {
    return x;
  }

  int getHeight() const {
    return y;
  }

private:
  std::vector<Plugin> dlls;
  std::vector<Bot *> items;

  int x;
  int y;
};

#endif