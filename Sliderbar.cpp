#include "Sliderbar.h"

Sliderbar::Sliderbar()
{
	this->xpos = 50;
	this->ypos = 50;
	this->value = 0;
	this->max_value = 1;
}

Sliderbar::Sliderbar(int x, int y, int val, float maxval)
{
	this->xpos = x;
	this->ypos = y;
	this->value = val;
	this->max_value = maxval;
}

void Sliderbar::drawSlider()
{
	glColor3f(0.5, 0.5, 0.5);
	glRectf(this->xpos, this->ypos, this->xpos+ slider_length, this->ypos + 10);
	this->drawValue();
}

void Sliderbar::drawValue()
{
	glColor3f(0, 0, 0);
	glRectf(this->xpos + this->value, this->ypos - 10, this->xpos + this->value + 5, this->ypos + 20);
}

void Sliderbar::setValue(float x)
{
	this->max_value = x;
}

int Sliderbar::getSliderSize()
{
	return this->slider_length;
}

int Sliderbar::isClicked(int x, int y)
{
	y = glutGet(GLUT_SCREEN_HEIGHT) - y;
	if (((x > this->xpos) && (x < this->xpos + this->slider_length)) &&
		((y > this->ypos - 20) && (y < this->ypos + 40)))
	{
		return this->max_value * (x - this->xpos) / this->slider_length;
	}
	else return -1;
}