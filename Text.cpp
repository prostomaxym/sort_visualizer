#include "Text.h"

void Text::glWrite(float x, float y, int* font, std::string text)
{
	glRasterPos2f(x, y);
	for (unsigned i = 0; i < text.size(); i++)
		glutBitmapCharacter(font, (int)text[i]);
}

void Text::drawOperationCount(int n, float x, float y, int arrsize)
{
	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(x, win.hight-y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Size of an array:");

	glColor3f(0.4, 0.3, 0.8);
	this->glWrite(x+20, win.hight - y-30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(arrsize));

	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(x, win.hight - y-60,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Number of permutations:");

	glColor3f(0.7, 0.2, 0.2);
	this->glWrite(x+20, win.hight - y-90,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(n));
}

void Text::drawSortName(std::string sortname, int xcoord, int ycoord)
{
	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(win.width - xcoord, win.hight-ycoord,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Sorting algorithm:");

	glColor3f(0.8, 0, 0.8);
	this->glWrite(win.width - xcoord +200, win.hight - ycoord,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, sortname);
}

void Text::drawKeyGuide(int xcoord, int ycoord)
{
	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(win.width/2-150, win.hight-ycoord,
		(int*)GLUT_BITMAP_HELVETICA_18, "Key Guide:");

	glColor3f(0.1, 0.1, 0.9);
	this->glWrite(win.width / 2 -25, win.hight - ycoord +25,
		(int*)GLUT_BITMAP_HELVETICA_18, "1 - Bubble sort");

	glColor3f(0.1, 0.1, 0.9);
	this->glWrite(win.width / 2 - 25, win.hight - ycoord,
		(int*)GLUT_BITMAP_HELVETICA_18, "2 - Merge sort");

	glColor3f(0.1, 0.1, 0.9);
	this->glWrite(win.width / 2 - 25, win.hight - ycoord -25,
		(int*)GLUT_BITMAP_HELVETICA_18, "R - Reshuffle array");

	glColor3f(0.1, 0.1, 0.9);
	this->glWrite(win.width / 2 - 25, win.hight - ycoord - 50,
		(int*)GLUT_BITMAP_HELVETICA_18, "S - Stop sorting");
}
