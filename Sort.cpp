#include "Sort.h"

Sort::Sort()
{
	for (unsigned i = 0; i < 100; i++)
	{
		this->arr.push_back(rand() % 100);
	}
	this->n = arr.size();
	this->swapCounter = 0;
	this->i = 1;
}

Sort::Sort(unsigned size, unsigned max_value)
{
	for (unsigned i = 0; i < size; i++)
	{
		this->arr.push_back(rand() % max_value);
	}
	this->n = arr.size();
	this->swapCounter = 0;
	this->i = 1;
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
			this->swapCounter++;
			break;
		}
		this->i++;
  }
	if (swapped == false)
	{
		this->i = 1;
		this->n--;
	}
	return !(std::is_sorted(arr.begin(), arr.end()));
}

void Sort::drawArray()
{
	//Draw all array with green color
	glColor3f(0, 0.9, 0);
	for (unsigned i = 0; i < arr.size(); i++)
	{
		glRectf(50 + i * 6, 100, 53 + i * 6, 100 + arr[i]);
	}

	//Draw current iteration with red color
	glColor3f(1, 0.1, 0);
	glRectf(50 + this->i * 6, 100, 53 + this->i * 6, 100 + arr[this->i]);
}
