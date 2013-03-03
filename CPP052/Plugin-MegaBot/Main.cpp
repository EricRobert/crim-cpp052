#include "../Game/Bot.hpp"
#include "../Game/Policies.hpp"
#include "../Game/Bots.hpp"

#include <algorithm>
#include <iostream>

struct MegaBot : public GenericBot<MegaBot, SwarmSpeed, RandomDirection>
{
  MegaBot(float x, float y) : GenericBot(x, y), green(0.5f), color(0.01f) {
  }

  void setColor(float & r, float & g, float & b) {
    green += color;
    if(green <= 0.25f || green >= 1.0f) {
      color = -color;
    }

    g = green;
    r = b = 0.0f;
  }

  float green;
  float color;
};

extern "C" __declspec(dllexport) Factory * initialize() {
  static Bots<MegaBot> factory;
  return &factory;
}
