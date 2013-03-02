// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#include <GL/glut.h>

void idle() {
  glutPostRedisplay();
}

void display() {
  glClearColor(0.0f, 0.2f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

int main(int argc, char ** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutCreateWindow("CPP052");
  glutIdleFunc(idle);
  glutDisplayFunc(display);
  glutMainLoop();
}
