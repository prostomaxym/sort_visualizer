#ifndef SORT_VISUALIZER_SORT_H_
#define SORT_VISUALIZER_SORT_H_

#include <cstdlib>

#include <algorithm>
#include <vector>

#include <glut.h>

#include "Window.h"


class Window;

class Sort
{
public:
	Sort();
	Sort(unsigned size, unsigned max_value);

	bool bubbleSortTick();
	void drawArray();
private:
	std::vector <int> arr;
	int n;
	unsigned i;
	int swapCounter;
};
#endif  // SORT_VISUALIZER_SORT_H_
