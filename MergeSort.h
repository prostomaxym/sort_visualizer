#ifndef SORT_VISUALIZER_MERGESORT_H_
#define SORT_VISUALIZER_MERGESORT_H_

#include <vector>

class MergeSort
{
public:
	MergeSort();
	bool tick(std::vector <int> &arr, int &i, int &operation_counter);
	void rebuild();

private:
	int BlockSizeIterator;
	int BlockIterator;
	int LeftBlockIterator;
	int RightBlockIterator;
	int MergeIterator;
	int LeftBorder;
	int MidBorder;
	int RightBorder;
	std::vector <int>SortedBlock;
};
#endif  // SORT_VISUALIZER_MERGESORT_H_
