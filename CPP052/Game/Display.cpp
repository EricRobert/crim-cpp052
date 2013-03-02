// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include "Display.hpp"

// freeglut
#include <GL/freeglut.h>

namespace {
  Display * instance;
}

void idle() {
  glutPostRedisplay();
}

void display() {
  glClearColor(0.0f, 0.2f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  if(instance) {
    instance->draw();
  }

  glutSwapBuffers();
}

Display::Display(int argc, char ** argv, int x, int y) : world(x, y) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowSize(x * 5, y * 5);
  glutCreateWindow("CPP052");
  glutIdleFunc(idle);
  glutDisplayFunc(display);
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE , GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  instance = this;
}

void Display::main() {
  glutMainLoop();
}

void Display::draw() {
  world.step();
  world.draw();
}
