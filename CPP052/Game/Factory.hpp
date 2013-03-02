// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef FACTORY__INCLUDED
#define FACTORY__INCLUDED

class Bot;

// interface de création de bots
class Factory
{
public:
  virtual Bot * spawn(float x, float y) = 0;
};

#endif
