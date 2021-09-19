#include "Text.h"

void Text::glWrite(float x, float y, int* font, std::string text)
{
	glRasterPos2f(x, y);
	for (size_t i = 0; i < text.size(); i++)
		glutBitmapCharacter(font, (int)text[i]);
}

void Text::drawOperationCount(int n, float x, float y, int arrsize)
{
	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(x, y,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "Size of an array:");

	glColor3f(0.4, 0.3, 0.8);
	this->glWrite(x + 20, y - 30,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(arrsize));

	glColor3f(0.2, 0.2, 0.2);
	this->glWrite(x, y-70,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, "The number of permutations:");

	glColor3f(0.7, 0.2, 0.2);
	this->glWrite(x+20, y-100,
		(int*)GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(n));
}
