// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include <iostream>

extern "C" {
  __declspec(dllexport) int initialize();
}

int initialize() {
  std::cout << "initialize" << std::endl;
  return 0;
}
