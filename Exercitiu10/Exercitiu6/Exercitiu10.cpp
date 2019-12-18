// Exercitiu6.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//eliberare buffer si reinitializre fereastra

	glBegin(GL_LINE_LOOP);//creare linie inchisa
	glVertex3f(-1, 0, 0);//coordonate vertex
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Exemplu");//creare fereastra
	glutDisplayFunc(Display);
	glutMainLoop();
    return 0;
}

