// Exemplu9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <GL/glut.h>
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);//elibereaza bufferul 
	glBegin(GL_LINE_STRIP);//creaza o linie care este compusa din mai multi vertecsi
	glVertex3f(-1, 0, 0);//punctul de start al liniei
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);//prima inflexiune a liniei
	glVertex3f(1, 0, 0);//ultimul vertex din linie
	glEnd();

	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Exemplu");
	glutDisplayFunc(Display);
	glColor3f(1, 0, 0);
	glutMainLoop();

    return 0;
}

