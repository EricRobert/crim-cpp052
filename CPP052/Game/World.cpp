// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "World.hpp"
#include "Bot.hpp"
#include "Factory.hpp"

// glut
#include <GL/glut.h>
#include <algorithm>

World::World(int _x, int _y) : x(_x), y(_y) {
  dlls.push_back("Plugin-Sample.dll");
  Bot * item = dlls.back().getFactory()->spawn(x / 2.0f, y / 2.0f);
  items.push_back(item);
}

void World::step() {
  for(std::vector<Bot *>::iterator i = items.begin(); i != items.end(); ++i) {
    (*i)->step(this);
  }
}

void World::draw() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, x, 0, y, 0, 10);
  glMatrixMode(GL_MODELVIEW);

  for(std::vector<Bot *>::iterator i = items.begin(); i != items.end(); ++i) {
    (*i)->draw();
  }
}

void World::wrap(float & i, float & j) {
  i = std::fmod(i, float(x)) + float(i < 0 ? x : 0);
  j = std::fmod(j, float(y)) + float(j < 0 ? y : 0);
}
