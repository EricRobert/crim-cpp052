// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef FACTORY__INCLUDED
#define FACTORY__INCLUDED

class World;

// interface de création de bots
class Factory
{
public:
  virtual ~Factory() {
  }

  virtual void spawn(float x, float y) = 0;

  virtual void draw() = 0;
  virtual void step(World * world) = 0;
};

#endif
