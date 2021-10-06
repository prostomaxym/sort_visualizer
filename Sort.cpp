#include "Sort.h"

Sort::Sort()
{
	for (unsigned i = 0; i < 100; i++)
	{
		this->arr.push_back(rand() % 100);
	}

	//array setup
	this->n = arr.size()-1;
	this->arr_size = arr.size();
	this->max_value = 100;
	this->x = 50;
	this->y = 100;
	this->x_scale = 1;
	this->y_scale = 1;
	this->i = 1;
	this->operation_counter = 0;

	//MergeSort setup
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;

	//HeapSort setup
	this->start = (arr_size - 2) / 2;
	this->root = start;

	//QuickSort setup
	this->l = 0;
	this->h = arr_size - 1;
	this->stack=std::vector <int>(h - l + 1);
	this->top = -1;
	this->t = arr[h];
	this->p = (l - 1);
	this->j = l;

}

Sort::Sort(unsigned size, unsigned maxvalue, int xcoord, int ycoord, float xscale, float yscale)
{
	for (unsigned i = 0; i < size; i++)
	{
		this->arr.push_back(rand() % maxvalue);
	}

	//array setup
	this->n = arr.size()-1;
	this->arr_size = arr.size();
	this->max_value = maxvalue;
	this->x = xcoord;
	this->y = ycoord;
	this->x_scale = xscale;
	this->y_scale = yscale;
	this->i = 1;
	this->operation_counter = 0;

	//MergeSort setup
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;

	//HeapSort setup
	this->start = (arr_size - 2) / 2;
	this->root = start;

	//QuickSort setup
	this->l = 0;
	this->h = arr_size - 1;
	this->stack = std::vector <int>(h - l + 1);
	this->top = -1;
	this->t = arr[h];
	this->p = (l - 1);
	this->j = l;
}

void Sort::reshuffleArray()
{
	this->arr.clear();
	for (int i = 0; i < this->arr_size; i++)
	{
		this->arr.push_back(rand() % this->max_value);
	}

	//array setup
	this->n = arr_size - 1;
	this->operation_counter = 0;
	this->i = 1;

	//MergeSort setup
	this->SortedBlock.clear();
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;

	//HeapSort setup
	this->start = (arr_size - 2) / 2;
	this->root = start;

	//QuickSort setup
	this->stack.clear();
	this->l = 0;
	this->h = arr_size - 1;
	this->stack = std::vector <int>(h - l + 1);
	this->top = -1;
	this->t = arr[h];
	this->p = (l - 1);
	this->j = l;
}

bool Sort::bubbleSortTick()
{
	if (std::is_sorted(arr.begin(), arr.end())) return false;

	bool swapped = false;
	while (i < n + 1)
	{
		if (arr[i - 1] > arr[i])
		{
			std::swap(arr[i - 1], arr[i]);
			swapped = true;
			operation_counter++;
			break;
		}
		i++;
	}
	if (swapped == false)
	{
		i = 1;
		n--;
		return true;
	}
	return true;
}

bool Sort::mergeSortTick()
{
	if (std::is_sorted(arr.begin(), arr.end())) return false;
		
	while (BlockSizeIterator < arr_size)
	{
		while (BlockIterator < arr_size - BlockSizeIterator)
		{
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < arr_size) ? RightBorder : arr_size;
			SortedBlock.resize(RightBorder - LeftBorder);

			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;

					i = LeftBorder + LeftBlockIterator;
					operation_counter++;
					return true;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
					i = MidBorder + RightBlockIterator;
					operation_counter++;
					RightBlockIterator += 1;
					return true;
				}
			}
			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
				i = LeftBorder + LeftBlockIterator;
				operation_counter++;
				LeftBlockIterator += 1;
				return true;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
				i = MidBorder + RightBlockIterator;
				operation_counter++;
				RightBlockIterator += 1;
				return true;
			}
			while (MergeIterator < LeftBlockIterator + RightBlockIterator)
			{
				arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
				i = LeftBorder + MergeIterator;
				operation_counter++;
				MergeIterator++;
				return true;
			}
			MergeIterator = 0;
			SortedBlock.clear();
			BlockIterator += 2 * BlockSizeIterator;
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
		}
		BlockIterator = 0;
		BlockSizeIterator *= 2;
	}
	return true;
}

bool Sort::heapSortTick()
{
	if (std::is_sorted(arr.begin(), arr.end())) return false;

	//make max heap
	while (start >= 0)
	{
		while (2 * root + 1 <= arr_size - 1)
		{
			int child = 2 * root + 1;
			int swap = root;

			if (arr[swap] < arr[child]) swap = child;
			if ((child + 1 <= arr_size - 1) && (arr[swap] < arr[child + 1])) swap = child + 1;
			if (swap == root) break;
			else
			{
				std::swap(arr[root], arr[swap]);
				root = swap;
				operation_counter++;
				i = swap;
				return true;
			}
		}
		start = start - 1;
		root = start;
	}

	//skip make max heap step when heap is already made
	if (start == -1)
	{
		this->root = 0;
		start = -2;
	}

	while (n > 0)
	{
		if (root == 0 || (2 * root + 1) > n)
		{
			std::swap(arr[n], arr[0]);
			operation_counter++;
			n = n - 1;
			this->root = 0;
		}
		
		while (2 * root + 1 <= n)
		{
			int child = 2 * root + 1;
			int swap = root;

			if (arr[swap] < arr[child]) swap = child;
			if ((child + 1 <= n) && (arr[swap] < arr[child + 1])) swap = child + 1;
			if (swap == root)
			{
				root = 0;
				break;
			}
			else
			{
				std::swap(arr[root], arr[swap]);
				operation_counter++;
				root = swap;
				i = swap;
				return true;
			}
		}
		return true;
	}
	return true;
}

bool Sort::quickSortTick()
{
	if (std::is_sorted(arr.begin(),arr.end()))	return false;

	if (j <= h - 1)
	{
		if (arr[j] <= t)
		{
			p++;
			std::swap(arr[p], arr[j]);
			operation_counter++;
		}
		j++;
		i = j;
		return true;
	}
	if (j > h - 1)
	{
		std::swap(arr[p + 1], arr[h]);
		i = p + 1;
		operation_counter++;
		p = p + 1;

		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
		if (top < 1) return true;

		h = stack[top--];
		l = stack[top--];
		t = arr[h];
		p = (l - 1);
		j = l;
		return true;
	}
	return true;
}

void Sort::drawArray()
{
	//Draw all array with green color
	glColor3f(0, 0.9, 0);
	for (unsigned j = 0; j < arr.size(); j++)
	{
		glRectf(/*x1 point*/this->x+(this->x_scale *j * 6), /*y1 point*/this->y,
			/*x2 point*/this->x+3 + (this->x_scale *j * 6), /*y2 point*/this->y + this->y_scale * arr[j]);
	}

	//Draw current iteration with red color
	glColor3f(1, 0.1, 0);
	glRectf(/*x1 point*/this->x + (this->x_scale*this->i * 6), /*y1 point*/this->y,
		/*x2 point*/this->x + 3+(this->x_scale * this->i * 6), /*y2 point*/this->y + this->y_scale * arr[this->i]);
}

int Sort::getOperationCounter()
{
	return this->operation_counter;
}

int Sort::getArraySize()
{
	return this->arr.size();
}