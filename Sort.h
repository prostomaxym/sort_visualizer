#ifndef SORT_VISUALIZER_SORT_H_
#define SORT_VISUALIZER_SORT_H_

#include <cstdlib>

#include <algorithm>
#include <vector>

#include <glut.h>

class Sort
{
public:
	Sort();
	Sort(unsigned size, unsigned max_value, int xcoord, int ycoord, float xscale, float yscale);

	bool bubbleSortTick();
	void drawArray();
	int getOperationCounter();
	int getArraySize();
private:
	std::vector <int> arr;
	int n;  // size
	unsigned i; // current iteration
	int operation_counter;  //number of swap operation done
	int x, y;	//drawArray bottom left coordinates
	float x_scale, y_scale;	//size scale
};
#endif  // SORT_VISUALIZER_SORT_H_
