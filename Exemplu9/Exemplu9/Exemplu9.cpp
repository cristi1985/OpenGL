// Exemplu9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
//#include <math.h>>
#include <GL/glut.h>

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	glFlush();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutCreateWindow("Exemplu");
	glutDisplayFunc(Display);
	glutMainLoop;
    return 0;
}

