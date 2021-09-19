#include <glut.h>


void gameloop(int);
void render();
void update();
void keyboard(int key, int a, int b);

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Sorting algorithms visualizer");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0,720);

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