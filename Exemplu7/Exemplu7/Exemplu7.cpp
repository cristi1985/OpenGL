// Exemplu7.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//elibereaza bufferul si rescrie imaginea
	glBegin(GL_LINES);//se deseneaza linii in fereastra
	glVertex3f(-1, 0, 0);//punctul de inceput al liniei
	glVertex3f(1, 0, 0);//capatul liniei
	glEnd();//se termina desenarea

	glFlush();//se executa desenarea in fereastra
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);//se initializeaza fereastra de OPENGL
	glutCreateWindow("Example");//se creaza fereastra
	glutDisplayFunc(Display);//functie callback pentru desenare
	glutMainLoop();
    return 0;
}

