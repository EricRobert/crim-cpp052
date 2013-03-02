// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef FACTORY__INCLUDED
#define FACTORY__INCLUDED

class World;
class Bot;

// interface de création de bots
class Factory
{
public:
  virtual ~Factory() {
  }

  virtual Bot * spawn(float x, float y) = 0;
  virtual void step(World * world) = 0;
};

#endif
