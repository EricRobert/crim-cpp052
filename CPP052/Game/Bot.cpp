// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Bot.hpp"
#include "World.hpp"

// glut
#include <GL/glut.h>

Bot::Bot(float _red, float _green, float _blue, float _x, float _y) : red(_red), green(_green), blue(_blue), x(_x), y(_y), dx(0), dy(0) {
}

void Bot::move(float _dx, float _dy) {
  dx = _dx;
  dy = _dy;
}

void Bot::draw() {
  glColor3f(red, green, blue);
  glLoadIdentity();
  glTranslatef(x, y, 0);
  glutSolidSphere(1.0f, 8, 8);
}

void Bot::step(World * world) {
  think(world);
  x += dx;
  y += dy;
  world->wrap(x, y);
}
