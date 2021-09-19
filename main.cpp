#include <ctime>

#include <glut.h>

#include "Sort.h"
#include "Text.h"
#include "Window.h"

void gameloop(int);
void render();
void update();
void specialKeyHandler(int key, int a, int b);
void normalKeyHandler(unsigned char key, int x, int y);

Window win(1280, 720, "Sorting algorithms visualizer");

//(unsigned size, unsigned max_value, int xcoord, int ycoord, float xscale, float yscale)
Sort arr(200, 500, 50, 100, 1, 1);
Text txt;

bool sorting = false;

enum class SortingAlg
{
	BUBBLE,
	MERGE,
	RESET
}mode;

int main()
{
	srand(time(NULL)); // set random seed

	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(10, gameloop, 0);
	glutSpecialFunc(specialKeyHandler);
	glutKeyboardFunc(normalKeyHandler);

	//Game loop
	glutMainLoop();
	return 0;
}

void gameloop(int=0)
{
	render();
	update();
	glutTimerFunc(10, gameloop, 0);
}

void render()
{
	glClearColor(0.8, 0.8, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	arr.drawArray();
	txt.drawOperationCount(arr.getOperationCounter(),20,680, arr.getArraySize());
	glFlush();
}

void update()
{
	if (sorting && (mode==SortingAlg::BUBBLE))
	{
		sorting=arr.bubbleSortTick();
	}
}

void specialKeyHandler(int key, int a, int b)
{
	switch (key)
	{
	default:
		break;
	}
}

void normalKeyHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 49:
		sorting = true;
		mode = SortingAlg::BUBBLE;
		break;
	case 50:
		sorting = true;
		mode = SortingAlg::MERGE;
		break;
	case 'r':
		sorting = false;
		mode = SortingAlg::RESET;
		break;
	}
}