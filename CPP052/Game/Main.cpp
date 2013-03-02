// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Plugin.hpp"
#include "Display.hpp"

#include <iostream>

int main(int argc, char ** argv) {
  try {
    Plugin plugin("Plugin-Sample.dll");
    std::cout << "result: " << plugin.initialize();
    Display display(argc, argv);
    display.main();
  }
  catch(std::exception & e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  catch(...) {
    std::cerr << "Error: Fatal" << std::endl;
  }
}
