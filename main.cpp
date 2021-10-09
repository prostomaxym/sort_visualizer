#include <ctime>

#include <string>

#include <glut.h>

#include "Keyboard.h"
#include "main.h"
#include "Sort.h"
#include "Text.h"
#include "Window.h"

const int w = 1280, h = 720;  //default screen resolution
bool fullscreen = false;  //default screen mode
bool sorting = false;  //default program state
int sorting_speed = 5;  //milliseconds beetween gameloop ticks
bool speedX5 = false;  //increase render speed x5

//win(Width resolusion, Hight resolusion, window name)
Window win(w, h, "Sorting algorithms visualizer");

//arr(array_size, max_value, xcoord, ycoord, float x_scale, float y_scale)
Sort arr(200, 500, 50, 50, 1, 1); //array to be sorted settings
Text ui; //on screen text UI 
SortingAlg mode = SortingAlg::RESET;  //default sorting mode

//convert enum to screen text
inline std::string enumToString(SortingAlg alg)
{
	switch (alg)
	{
	case SortingAlg::BUBBLE: return "Bubble sort";
	case SortingAlg::MERGE: return "Merge sort";
	case SortingAlg::HEAP: return "Heap sort";
	case SortingAlg::QUICK: return "Quick sort";
	case SortingAlg::RESET: return "Array is reshuffled";
	case SortingAlg::STOP: return "Sorting stopped";
	default:      return "[algorithm is not selected]";
	}
}

int main()
{
	srand(time(NULL));

	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(sorting_speed, gameloop, 0);
	glutKeyboardUpFunc(normalKeyReleaseHandler);
	glutKeyboardFunc(normalKeyHandler);

	//Game loop
	glutMainLoop();
	return 0;
}

void gameloop(int=0)
{
	render();
	update();
	glutTimerFunc(sorting_speed, gameloop, 0);
}

void render()
{
	glClearColor(0.8, 0.8, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	arr.drawArray();

	ui.drawOperationCount(arr.getOperationCounter(), 20, 40, arr.getArraySize());
	ui.drawSortName(enumToString(mode), 400, 50);
	ui.drawKeyGuide(25, 90);
	ui.drawRenderSpeed(-25, 40, speedX5);

	glFlush();
}

void update()
{
	if (sorting && (mode == SortingAlg::RESET))
	{
		sorting = false;
		arr.reshuffleArray();
	}
	else if (sorting && (mode == SortingAlg::STOP))
	{
		sorting = false;
	}
	else if (sorting)
	{
		sorting = arr.tick(mode);
	}
}