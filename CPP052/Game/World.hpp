// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef WORLD__INCLUDED
#define WORLD__INCLUDED

#include "Plugin.hpp"

#include <vector>

class Bot;

// représentation du monde de bots
class World
{
public:
  World(int _x, int _y);

  void step();
  void draw();
  void wrap(float & i, float & j);

  void move(float & i, float & j, float dx, float dy, Bot * bot);
  void wipe(Bot * bot);

  int getWidth() const {
    return x;
  }

  int getHeight() const {
    return y;
  }

  int getCell(float i, float j) const;

private:
  std::vector<Plugin> items;

  typedef std::vector<Bot *> GridType;
  GridType grid;

  int x;
  int y;
};

#endif
