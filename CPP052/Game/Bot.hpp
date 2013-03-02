// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef BOT__INCLUDED
#define BOT__INCLUDED

class World;

// interface de librairie dynamique
#ifndef GAME_EXPORTS
  #define DLLAPI __declspec(dllimport)
#else
  #define DLLAPI __declspec(dllexport)
#endif

// base d'extension externe
class DLLAPI Bot
{
public:
  Bot(float _red, float _green, float _blue, float _x, float _y, float _growth = 0.5f);

  virtual ~Bot() {
  }

  float getX() const {
    return x;
  }

  float getY() const {
    return y;
  }

  float getEnergy() const {
    return energy;
  }

  bool isOk() const {
    return energy > 0;
  }

  void move(float _dx, float _dy);
  void draw();
  void step(World * world);
  bool split();
  void kill(Bot * other);
  void wipe(World * world);

  virtual float attack(Bot * other);
  virtual float defend(Bot * other);

private:
  float red;
  float green;
  float blue;
  float x;
  float y;
  float dx;
  float dy;
  float growth;
  float energy;
};

template<typename T, typename SpeedPolicy, typename DirectionPolicy>
  class GenericBot
    : public Bot, public SpeedPolicy, public DirectionPolicy
  {
  public:
    GenericBot(float _red, float _green, float _blue, float _x, float _y, float _growth = 0.5f) : Bot(_red, _green, _blue, _x, _y, _growth) {
    }

    GenericBot(GenericBot const & other) : Bot(other), SpeedPolicy(other), DirectionPolicy(other) {
    }

    T * clone() const {
      return new T(static_cast<T const &>(*this));
    }

    void think(World * world) {
      float dx;
      float dy;
      this->getDirection(dx, dy);
      float w = this->getSpeed();
      dx *= w;
      dy *= w;
      move(dx, dy);
    }
  };

#endif
