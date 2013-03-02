// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef DISPLAY__INCLUDED
#define DISPLAY__INCLUDED

#include "World.hpp"

class Display
{
public:
  Display(int argc, char ** argv, int x, int y);

  void main();
  void draw();

private:
  World world;
};

#endif
