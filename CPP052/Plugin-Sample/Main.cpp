// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "../Game/Bot.hpp"
#include "../Game/Policies.hpp"
#include "../Game/Bots.hpp"

#include <algorithm>
#include <iostream>

struct SampleBot : public GenericBot<SampleBot, RandomSpeed, RandomDirection>
{
  SampleBot(float x, float y) : GenericBot(1.0f, 0.0f, 0.0f, x, y) {
  }
};

extern "C" __declspec(dllexport) Factory * initialize() {
  static Bots<SampleBot> factory;
  return &factory;
}
