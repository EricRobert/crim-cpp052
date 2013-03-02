// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "../Game/Bot.hpp"
#include "../Game/Bots.hpp"

#include <algorithm>

class SampleBot : public Bot
{
public:
  SampleBot(float x, float y) : Bot(1.0f, 0.0f, 0.0f, x, y) {
    wx = 0.0001f * ((std::rand() % 100) - 50);
    wy = 0.0001f * ((std::rand() % 100) - 50);
  }

  void think(World * world) {
    move(wx, wy);
  }

private:
  float wx;
  float wy;
};

extern "C" __declspec(dllexport) Factory * initialize() {
  static Bots<SampleBot> factory;
  return &factory;
}
