// Exemplu10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);//elibereaza bufferul

	glBegin(GL_LINE_LOOP);//deseneaza o linie inchisa
	glVertex3f(-1, 0, 0);//primul vertex
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);//ultimul vertex
	glEnd();//se termina desenarea

	glFlush();//se afiseaza desenul
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);//se cheama functia de initalizare
	glutCreateWindow("exemplu");//se creaza fereastra
	glutDisplayFunc(Display);//se afiseaza desenul
	glutMainLoop();//functie callback

    return 0;
}

