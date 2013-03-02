// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "World.hpp"

// glut
#include <GL/glut.h>

World::World(int _x, int _y) : x(_x), y(_y) {
}

void World::step() {
  // ...
}

void World::draw() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, x, 0, y, 0, 10);
  glMatrixMode(GL_MODELVIEW);

  // ...
}

void World::wrap(float & i, float & j) {
  i = std::fmod(i, float(x)) + float(i < 0 ? x : 0);
  j = std::fmod(j, float(y)) + float(j < 0 ? y : 0);
}
