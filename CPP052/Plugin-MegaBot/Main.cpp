#include "../Game/Bot.hpp"
#include "../Game/Policies.hpp"
#include "../Game/Bots.hpp"

#include <algorithm>
#include <iostream>

struct MegaBot : public GenericBot<MegaBot, SwarmSpeed, RandomDirection>
{
  MegaBot(float x, float y) : GenericBot(0.0f, 1.0f, 0.0f, x, y) {
  }
};

extern "C" __declspec(dllexport) Factory * initialize() {
  static Bots<MegaBot> factory;
  return &factory;
}
