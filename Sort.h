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
	bool heapSortTick();
	bool quickSortTick();
	void drawArray();
	int getOperationCounter();
	int getArraySize();

private:
	std::vector <int> arr;
	int arr_size; //initial size of array
	int max_value; //max value of array elements
	int x, y;	//drawArray bottom left coordinates
	float x_scale, y_scale;	//size scale

	int n;  //size of subarray
	int i;  //current iteration
	int operation_counter;  //number of swap operation done

	//Merge sort fields
	size_t BlockSizeIterator;
	size_t BlockIterator;
	size_t LeftBlockIterator;
	size_t RightBlockIterator;
	size_t MergeIterator;
	size_t LeftBorder;
	size_t MidBorder;
	size_t RightBorder;
	std::vector <int>SortedBlock;

	//Heap sort fields
	int start;
	int root;

	//Quick sort fields
	size_t l;
	size_t h;
	std::vector <int> stack;
	int top;
	int j;
	int t;
	int p;
};
#endif  // SORT_VISUALIZER_SORT_H_
