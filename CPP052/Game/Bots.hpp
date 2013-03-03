// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef BOTS__INCLUDED
#define BOTS__INCLUDED

#include "Factory.hpp"

#include <vector>
#include <memory>

template<typename T>
  class Bots : public Factory
  {
  public:
    void spawn(float x, float y) {
      T * item = new T(x, y);
      items.push_back(std::unique_ptr<T>(item));
    }

    template<typename U>
      typename std::enable_if<U::DynamicColor::Result == false>::type
      draw(U & item) {
        item.draw();
      }

    template<typename U>
      typename std::enable_if<U::DynamicColor::Result != false>::type
      draw(U & item) {
        float r, g, b;
        item.setColor(r, g, b);
        item.draw(r, g, b);
      }

    void draw() {
      for(ListType::iterator i = items.begin(); i != items.end(); ++i) {
        T & item = **i;
        draw(item);
      }
    }

    void step(World * world) {
      int i = 0;
      while(i != items.size()) {
        T * item = items[i].get();
        if(item->isOk()) {
          item->think(world);
          item->step(world);

          if(item->split()) {
            items.push_back(std::unique_ptr<T>(item->clone()));
          }

          ++i;
        }
        else {
          items[i]->wipe(world);
          std::swap(items[i], items.back());
          items.pop_back();
        }
      }
    }

  private:
    typedef std::vector<std::unique_ptr<T>> ListType;
    ListType items;
  };

#endif
