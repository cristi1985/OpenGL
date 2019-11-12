// Exemplu6.1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);//se creaza puncte
	for (int i = 0; i < 1000; ++i)
	{
		glVertex3f(cos(2 * 3.14159*i / 1000.0), sin(2 * 3.14159*i / 1000.0), 0);//se creeaza puncte pe aria unui cerc
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Exemplu");
	glutDisplayFunc(Display);//se randeaza vederea
	glutMainLoop();
    return 0;
}

