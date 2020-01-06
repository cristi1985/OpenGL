// Ex2Lab.cpp : Defines the entry point for the console application.
// ASTA NU MERGE 

#include "stdafx.h"
#include <GL\glut.h>
#include <math.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(50);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)//functie redesenare
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//initializare sistem de coordonate
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);//stabileste volumul de vedere folosind o proiectie ortografica
}

void display()
{
	//float rad3=0.8;
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat Pi = 2 * 3.14;
	GLfloat rad = 0.9;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 0);
	int sectiuni_i = 10;
	glVertex2f(0.0, 0.0);
	for (int i = 0; i <= sectiuni_i; ++i)
	{
		glVertex2f(rad*cos(i*Pi / sectiuni_i), rad*sin(i*Pi / sectiuni_i));
	}
	glColor3f(1, 0, 0);
	rad = 0.5;

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("2019");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
    return 0;
}

