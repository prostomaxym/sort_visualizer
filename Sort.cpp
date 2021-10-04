#include "Sort.h"

Sort::Sort()
{
	for (unsigned i = 0; i < 100; i++)
	{
		this->arr.push_back(rand() % 100);
	}
	this->n = arr.size();
	this->arr_size = arr.size();
	this->max_value = 100;
	this->x = 50;
	this->y = 100;
	this->x_scale = 1;
	this->y_scale = 1;

	this->i = 1;
	this->operation_counter = 0;
}

Sort::Sort(unsigned size, unsigned maxvalue, int xcoord, int ycoord, float xscale, float yscale)
{
	for (unsigned i = 0; i < size; i++)
	{
		this->arr.push_back(rand() % maxvalue);
	}
	this->n = arr.size();
	this->arr_size = arr.size();
	this->max_value = maxvalue;
	this->x = xcoord;
	this->y = ycoord;
	this->x_scale = xscale;
	this->y_scale = yscale;

	this->i = 1;
	this->operation_counter = 0;
}

void Sort::reshuffleArray()
{
	this->arr.clear();

	this->n = this->arr_size;
	this->operation_counter = 0;
	this->i = 1;

	for (unsigned i = 0; i < this->arr_size; i++)
	{
		this->arr.push_back(rand() % this->max_value);
	}
}
bool Sort::bubbleSortTick()
{
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

	if (std::is_sorted(arr.begin(), arr.end()))
	{
		return false;
	}
	else if (swapped == false)
	{
		this->i = 1;
		this->n--;
	}
	else
	{
		return true;
	}
}

bool Sort::mergeSortTick()
{
	size_t BlockSizeIterator;
	size_t BlockIterator;
	size_t LeftBlockIterator;
	size_t RightBlockIterator;
	size_t MergeIterator;

	size_t LeftBorder;
	size_t MidBorder;
	size_t RightBorder;
	for (BlockSizeIterator = 1; BlockSizeIterator < this->arr_size; BlockSizeIterator *= 2)
	{
		for (BlockIterator = 0; BlockIterator < arr_size - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
		{
			//ѕроизводим сли€ние с сортировкой пары блоков начинающуюс€ с элемента BlockIterator
			//левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < arr_size) ? RightBorder : arr_size;
			int* SortedBlock = new int[RightBorder - LeftBorder];

			//ѕока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
					RightBlockIterator += 1;
				}
			}
			//ѕосле этого заносим оставшиес€ элементы из левого или правого блока
			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
				LeftBlockIterator += 1;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
				RightBlockIterator += 1;
			}

			for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
			{
				arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
			}
			delete[] SortedBlock;
		}
	}
	return false;
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