#ifndef SORT_VISUALIZER_KEYBOARD_H_
#define SORT_VISUALIZER_KEYBOARD_H_

#include <glut.h>

#include "main.h"

void specialKeyHandler(int key, int a, int b);
void normalKeyHandler(unsigned char key, int x, int y);
void normalKeyReleaseHandler(unsigned char key, int x, int y);

#endif  // SORT_VISUALIZER_KEYBOARD_H_
