#ifndef SORT_VISUALIZER_TEXT_H_
#define SORT_VISUALIZER_TEXT_H_

#include <string>
#include "Window.h"

#include <glut.h>

extern Window win;

class Text
{
public:
	void drawOperationCount(int n, float x, float y, int arrsize);
	void drawSortName(std::string sortname, int xcoord, int ycoord);
	void drawKeyGuide(int xcoord, int ycoord);

private:
	void glWrite(float x, float y, int* font, std::string text);
};
#endif  // SORT_VISUALIZER_TEXT_H_

