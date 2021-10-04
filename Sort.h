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

	void reshuffleArray();
	bool bubbleSortTick();
	bool mergeSortTick();
	void drawArray();
	int getOperationCounter();
	int getArraySize();

private:
	std::vector <int> arr;
	int arr_size; //initial size of array
	int n;  // decremental size of array
	int max_value;
	int x, y;	//drawArray bottom left coordinates
	float x_scale, y_scale;	//size scale

	unsigned i; // current iteration
	int operation_counter;  //number of swap operation done
};
#endif  // SORT_VISUALIZER_SORT_H_
