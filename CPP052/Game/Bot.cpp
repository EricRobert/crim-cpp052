// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Bot.hpp"
#include "World.hpp"

// glut
#include <GL/glut.h>

Bot::Bot(float _red, float _green, float _blue, float _x, float _y, float _growth) : red(_red), green(_green), blue(_blue), x(_x), y(_y), dx(0), dy(0), growth(_growth), energy(0.5f) {
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
  float d = std::sqrt(dx * dx + dy * dy);
  energy = energy + (1.0f - d * 400.0f) * growth * 0.001f;
  x += dx;
  y += dy;
  world->wrap(x, y);
}

bool Bot::split() {
  if(energy < 1.0f) {
    return false;
  }

  energy /= 2.0f;
  return true;
}
