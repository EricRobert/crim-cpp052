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
    Bot * spawn(float x, float y) {
      T * item = new T(x, y);
      items.push_back(std::unique_ptr<T>(item));
      return item;
    }

  private:
    std::vector<std::unique_ptr<T>> items;
  };

#endif
