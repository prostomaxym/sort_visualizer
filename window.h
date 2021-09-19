#ifndef SORT_VISUALIZER_WINDOW_H_
#define SORT_VISUALIZER_WINDOW_H_

#include <string>
#include <glut.h>

#include "Sort.h"

class Window
{
public:
	Window();
	Window(int w, int h, std::string winname);
private:
	friend class Sort;
	int width, hight;
	std::string window_name;
};
#endif  // SORT_VISUALIZER_WINDOW_H_

