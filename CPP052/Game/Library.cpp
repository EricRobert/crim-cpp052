// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Library.hpp"

Library::Library(char const * filename) : name(filename) {
  library = LoadLibrary(name.c_str());
  if(!library) {
    throw std::exception("Cannot load dynamic library");
  }
}

Library::Library(Library const & other) : name(other.name) {
  library = LoadLibrary(name.c_str());
}

Library & Library::operator=(Library const & other) {
  if(this != &other) {
    Library copy(other);
    swap(copy);
  }

  return *this;
}

Library::~Library() {
  if(library) {
    FreeLibrary(library);
    library = 0;
  }
}

void Library::swap(Library & other) {
  std::swap(name, other.name);
  std::swap(library, other.library);
}

Library::CallType Library::getSymbol(char const * id) const {
  return GetProcAddress(library, id);
}
