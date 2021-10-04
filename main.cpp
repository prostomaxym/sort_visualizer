#include <ctime>

#include <string>

#include <glut.h>

#include "Sort.h"
#include "Text.h"
#include "Window.h"

void gameloop(int);
void render();
void update();
void specialKeyHandler(int key, int a, int b);
void normalKeyHandler(unsigned char key, int x, int y);
void normalKeyReleaseHandler(unsigned char key, int x, int y);

//Default settings
/*initialization params - win(Width resolusion, Hight resolusion, window name)*/
const int w = 1280, h = 720;  //default screen resolution
Window win(w, h, "Sorting algorithms visualizer");

/*initialization params - arr(unsigned array_size, unsigned max_value, 
	int xcoord, int ycoord, float x_scale, float y_scale)*/
Sort arr(200, 500, 50, 100, 1, 1); //array to be sorted settings
Text txt; //on screen text UI class

bool fullscreen = false;  //default screen mode
bool sorting = false;  //default program state
int sorting_speed = 1;  //milliseconds beetween gameloop ticks

//Toggle sorting algorithm
enum class SortingAlg
{
	BUBBLE,
	MERGE,
	RESET,
	STOP
};
SortingAlg mode = SortingAlg::RESET;

inline std::string enumToString(SortingAlg alg)
{
	switch (alg)
	{
	case SortingAlg::BUBBLE:   return "Bubble sort";
	case SortingAlg::MERGE:   return "Merge sort";
	case SortingAlg::RESET: return "Array is reshuffled";
	case SortingAlg::STOP: return "Sorting stopped";
	default:      return "[algorithm is not selected]";
	}
}

int main()
{
	srand(time(NULL)); // set random seed

	//GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(sorting_speed, gameloop, 0);
	glutSpecialFunc(specialKeyHandler);
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

	txt.drawOperationCount(arr.getOperationCounter(), 20, 40, arr.getArraySize());
	txt.drawSortName(enumToString(mode), 400, 50);
	txt.drawKeyGuide(0, 75);

	glFlush();
}

void update()
{
	if (sorting && (mode==SortingAlg::BUBBLE))
	{
		sorting=arr.bubbleSortTick();
	}
	else if (sorting && (mode == SortingAlg::RESET))
	{
		sorting = false;
		arr.reshuffleArray();
	}
	else if (sorting && (mode == SortingAlg::STOP))
	{
		sorting = false;
	}
}

void specialKeyHandler(int key, int a, int b)
{
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
		sorting = true;
		mode = SortingAlg::RESET;
		break;
	case 's':
		sorting = true;
		mode = SortingAlg::STOP;
		break;
	}
}

void normalKeyReleaseHandler(unsigned char key, int x, int y)
{
	if (key == 'f')
	{
		if (fullscreen)
		{
			glutReshapeWindow(1280, 720);
			fullscreen = false;
		}
		else
		{
			glutFullScreen();
			fullscreen = true;
		}
	}
}