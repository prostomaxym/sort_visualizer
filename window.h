#ifndef SORT_VISUALIZER_WINDOW_H
#define SORT_VISUALIZER_WINDOW_H

#include <string>
#include <glut.h>
class window
{
public:
	window();
	window(int w, int h, std::string winname);
private:
	int width, hight;
	std::string window_name;
};
#endif  // SORT_VISUALIZER_WINDOW_H

