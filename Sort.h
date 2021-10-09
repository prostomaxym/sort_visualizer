#ifndef SORT_VISUALIZER_SORT_H_
#define SORT_VISUALIZER_SORT_H_

#include <cstdlib>

#include <algorithm>
#include <vector>

#include <glut.h>

#include "main.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

class Sort
{
public:
	Sort();
	Sort(unsigned size, unsigned max_value, int xcoord, int ycoord, float xscale, float yscale);

	void reshuffleArray();
	bool tick(SortingAlg alg);

	void drawArray();
	int getOperationCounter();
	int getArraySize();

private:
	std::vector <int> arr;
	int arr_size; //initial size of array
	int max_value; //max value of array element
	int x, y;	//drawArray bottom left coordinates
	float x_scale, y_scale;	//size scale
	int n;  //size of subarray
	int i;  //current iteration
	int operation_counter;  //number of swap operation done

	BubbleSort bubble;
	MergeSort merge;
	HeapSort heap;
	QuickSort quick;
};
#endif  // SORT_VISUALIZER_SORT_H_
