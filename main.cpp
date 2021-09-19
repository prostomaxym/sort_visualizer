#include <glut.h>

#include "window.h"

void gameloop(int);
void render();
void update();
void keyboard(int key, int a, int b);

window win(1280, 720,"Sorting algorithms visualizer");

int main()
{
	glutDisplayFunc(render);
	glutTimerFunc(50, gameloop, 0);
	glutSpecialFunc(keyboard);

	//Game loop
	glutMainLoop();
	return 0;
}

void gameloop(int=0)
{
	render();
	update();
	glutTimerFunc(50, gameloop, 0);
}

void render()
{
	glClearColor(0.8, 0.8, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void update()
{

}

void keyboard(int key, int a, int b)
{
	switch (key)
	{
	}
}