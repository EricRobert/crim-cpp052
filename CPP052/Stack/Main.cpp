// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include <iostream>

// stack
#include "Stack.hpp"

int main() {
  try {
    Stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); // devrait lancer une exception
  }
  catch(std::exception const & e) {
    std::cout << e.what() << std::endl;
  }
  catch(...) {
    std::cout << "fail!" << std::endl;
  }
}
