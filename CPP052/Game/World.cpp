// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "World.hpp"
#include "Factory.hpp"
#include "Bot.hpp"

// glut
#include <GL/glut.h>
#include <algorithm>

World::World(int _x, int _y) : x(_x), y(_y), grid(_x * _y, 0) {
  items.push_back("Plugin-Sample.dll");
  items.push_back("Plugin-MegaBot.dll");
  std::for_each(items.begin(), items.end(), std::bind2nd(std::mem_fun_ref(&Plugin::spawn), this));
}

void World::step() {
  std::for_each(items.begin(), items.end(), std::bind2nd(std::mem_fun_ref(&Plugin::step), this));
}

void World::draw() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, x, 0, y, 0, 10);
  glMatrixMode(GL_MODELVIEW);

  std::for_each(items.begin(), items.end(), std::mem_fun_ref(&Plugin::draw));
}

void World::wrap(float & i, float & j) {
  i = std::fmod(i, float(x)) + float(i < 0 ? x : 0);
  j = std::fmod(j, float(y)) + float(j < 0 ? y : 0);
}

float limit(float value, float energy) {
  return value < energy ? value : energy;
}

void World::move(float & i, float & j, float dx, float dy, Bot * item) {
  int last = getCell(i, j);
  i += dx;
  j += dy;
  wrap(i, j);
  int next = getCell(i, j);
  if(last != next) {
    Bot * cell = grid[next];
    if(cell) {
      float a = limit(item->attack(cell), item->getEnergy());
      float b = limit(cell->defend(item), cell->getEnergy());
      if(a < b) {
        cell->kill(item);
      }
      else {
        item->kill(cell);
        grid[next] = item;
      }
    }
    else {
      grid[next] = item;
    }

    grid[last] = 0;
  }
}

void World::wipe(Bot * bot) {
  grid[getCell(bot->getX(), bot->getY())] = 0;
}

int World::getCell(float i, float j) const {
  return int(i) + (int(j) * x);
}
