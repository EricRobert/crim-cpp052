// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef PLUGIN__INCLUDED
#define PLUGIN__INCLUDED

#include "Library.hpp"

class World;
class Factory;

class Plugin : public Library
{
public:
  Plugin(char const * name);

  void spawn(World * world);
  void spawn(float x, float y);
  void draw();
  void step(World * world);

private:
  Factory * factory;
};

#endif
