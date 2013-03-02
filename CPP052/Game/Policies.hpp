// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef POLICIES__INCLUDED
#define POLICIES__INCLUDED

#include <algorithm>

struct RandomSpeed
{
  RandomSpeed() {
    speed = 0.0001f * (std::rand() % 100);
  }

  float getSpeed() {
    return speed;
  }

  float speed;
};

struct RandomDirection
{
  RandomDirection() {
    random();
  }

  RandomDirection(RandomDirection const & other) {
    random();
  }

  void random() {
    x = 0.01f * ((std::rand() % 200) - 100);
    y = 0.01f * ((std::rand() % 200) - 100);
    float d = std::sqrt(x * x + y * y);
    x /= d;
    y /= d;
  }

  void getDirection(float & dx, float & dy) {
    dx = x;
    dy = y;
  }

  float x;
  float y;
};

#endif
