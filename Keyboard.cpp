#include "Keyboard.h"

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
	case 51:
		sorting = true;
		mode = SortingAlg::HEAP;
		break;
	case 52:
		sorting = true;
		mode = SortingAlg::QUICK;
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
			glutReshapeWindow(w, h);
			fullscreen = false;
		}
		else
		{
			glutFullScreen();
			fullscreen = true;
		}
	}
	if (key == 'a')
	{
		if (speedX5)
		{
			sorting_speed *= 5;
			speedX5 = false;
		}
		else
		{
			sorting_speed /= 5;
			speedX5 = true;
		}
	}
}