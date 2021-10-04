#include "Keyboard.h"

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
			glutReshapeWindow(w, h);
			fullscreen = false;
		}
		else
		{
			glutFullScreen();
			fullscreen = true;
		}
	}
}