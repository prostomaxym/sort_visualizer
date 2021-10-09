#ifndef SORT_VISUALIZER_QUICKSORT_H_
#define SORT_VISUALIZER_QUICKSORT_H_

#include <vector>

class QuickSort
{
public:
	QuickSort();
	QuickSort(std::vector <int> arr);
	bool tick(std::vector<int>& arr, int& i, int& operation_counter);
	void rebuild(std::vector <int> arr);

private:
	int l;
	int h;
	std::vector <int> stack;
	int top;
	int j;
	int t;
	int p;
};
#endif  // SORT_VISUALIZER_QUICKSORT_H_
