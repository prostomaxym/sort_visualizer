#include "Sort.h"

Sort::Sort()
{
	for (unsigned i = 0; i < 100; i++)
	{
		this->arr.push_back(rand() % 100);
	}
	this->n = arr.size();
	this->operation_counter = 0;
	this->i = 1;
	this->x_scale = 1;
	this->y_scale = 1;
	this->x = 50;
	this->y = 100;
}

Sort::Sort(unsigned size, unsigned max_value, int xcoord, int ycoord, float xscale, float yscale)
{
	for (unsigned i = 0; i < size; i++)
	{
		this->arr.push_back(rand() % max_value);
	}
	this->n = arr.size();
	this->operation_counter = 0;
	this->i = 1;
	this->x_scale = xscale;
	this->y_scale = yscale;
	this->x = xcoord;
	this->y = ycoord;
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