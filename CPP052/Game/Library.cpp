// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Library.hpp"

Library::Library() : library(0) {
}

Library::Library(char const * filename) : library(0) {
  load(filename);
}

Library::Library(Library const & other) {
  load(other.name.c_str());
}

Library & Library::operator=(Library const & other) {
  if(this != &other) {
    unload();
    load(other.name.c_str());
  }

  return *this;
}

Library::~Library() {
  unload();
}

void Library::load(TCHAR const * filename) {
  unload();
  name = filename;
  library = LoadLibrary(filename);
}

void Library::unload() {
  if(library) {
    FreeLibrary(library);
    library = 0;
  }
}
