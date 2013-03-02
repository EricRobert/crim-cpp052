// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef PLUGIN__INCLUDED
#define PLUGIN__INCLUDED

#include "Library.hpp"

#include <vector>

class World;
class Bot;
class Factory;

class Plugin : public Library
{
public:
  Plugin(char const * name);

  void spawn(float x, float y);
  void draw();
  void step(World * world);

private:
  Factory * factory;

  typedef std::vector<Bot *> ListType;
  ListType items;
};

#endif
