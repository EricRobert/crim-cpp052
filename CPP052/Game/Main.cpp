// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Display.hpp"

#include <exception>
#include <iostream>

int main(int argc, char ** argv) {
  try {
    Display display(argc, argv, 128, 96);
    display.main();
  }
  catch(std::exception & e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  catch(...) {
    std::cerr << "Error: Fatal" << std::endl;
  }
}
