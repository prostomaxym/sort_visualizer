#include "Sort.h"

Sort::Sort()
{
	for (unsigned i = 0; i < 100; i++)
	{
		this->arr.push_back(rand() % 100);
	}
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

	this->start = (arr_size - 2) / 2;
}

Sort::Sort(unsigned size, unsigned maxvalue, int xcoord, int ycoord, float xscale, float yscale)
{
	for (unsigned i = 0; i < size; i++)
	{
		this->arr.push_back(rand() % maxvalue);
	}
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

	this->start = (arr_size - 2) / 2;
}

void Sort::reshuffleArray()
{
	this->arr.clear();

	this->n = this->arr_size;
	this->operation_counter = 0;
	this->i = 1;

	//MergeSort setup
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;

	for (unsigned i = 0; i < this->arr_size; i++)
	{
		this->arr.push_back(rand() % this->max_value);
	}
}

bool Sort::bubbleSortTick()
{
	if (std::is_sorted(arr.begin(), arr.end()))
	{
		return false;
	}

	bool swapped = false;
	while ((this->i) < (this->n))
	{
		if (this->arr[i - 1] > this->arr[i])
		{
			std::swap(this->arr[i - 1], this->arr[i]);
			swapped = true;
			this->operation_counter++;
			break;
		}
		this->i++;
  }

	if (swapped == false)
	{
		this->i = 1;
		this->n--;
		return true;
	}
	else
	{
		return true;
	}
}

bool Sort::mergeSortTick()
{
	if (std::is_sorted(arr.begin(), arr.end()))
	{
		this->i = 0;
		return false;
	}
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
			while(MergeIterator < LeftBlockIterator + RightBlockIterator)
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
		while (start >= 0)
		{
			int root = start;
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
					i = root;
				}
			}
			start = start - 1;
		}
		
	while (n > 0)
	{
		std::swap(arr[n], arr[0]);
		operation_counter++;
		n = n - 1;

		int root = 0;
		while (2 * root + 1 <= n)
		{
			int child = 2 * root + 1;
			int swap = root;

			if (arr[swap] < arr[child]) swap = child;
			if ((child + 1 <= n) && (arr[swap] < arr[child + 1])) swap = child + 1;
			if (swap == root) break;
			else
			{
				std::swap(arr[root], arr[swap]);
				operation_counter++;
				root = swap;
			}
		}
		i = 1;
		return true;
	}
	if (std::is_sorted(arr.begin(), arr.end())) return false;
	else return true;
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