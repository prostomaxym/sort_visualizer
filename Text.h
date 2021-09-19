#ifndef SORT_VISUALIZER_TEXT_H_
#define SORT_VISUALIZER_TEXT_H_

#include <string>

#include <glut.h>

class Text
{
public:
	void drawOperationCount(int n, float x, float y, int arrsize);
private:
	void glWrite(float x, float y, int* font, std::string text);
};
#endif  // SORT_VISUALIZER_TEXT_H_

