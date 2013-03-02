// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef BOT__INCLUDED
#define BOT__INCLUDED

class World;

// base d'extension externe
class Bot
{
public:
  Bot(float _red, float _green, float _blue, float _x, float _y);

  virtual ~Bot() {
  }

  float getX() const {
    return x;
  }

  float getY() const {
    return y;
  }

  void move(float _dx, float _dy);
  void draw();
  void step(World * world);

private:
  virtual void think(World * world) = 0;

  float red;
  float green;
  float blue;
  float x;
  float y;
  float dx;
  float dy;
};

#endif
