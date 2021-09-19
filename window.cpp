#include "window.h"

Window::Window()
{
	this->width = 1280;
	this->hight = 720;
	this->window_name = "Sorting algorithms visualizer";
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(this->width, this->hight);
	glutCreateWindow(this->window_name.c_str());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, this->width, 0, this->hight);
}

Window::Window(int w, int h, std::string winname)
{
	this->width = w;
	this->hight = h;
	this->window_name = winname;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(this->width, this->hight);
	glutCreateWindow(this->window_name.c_str());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, this->width, 0, this->hight);
}
