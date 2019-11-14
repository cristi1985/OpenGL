// Exemplul8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <GL/glut.h>


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);//elibereaza fereastra sterge bufferul

	glBegin(GL_LINES);//creaza linii
	for (int i = 0; i < 100; i++)//liniile sunt create toate cu aceeasi origine dar cu capat diferit
	{
		glVertex3f(0, 0, 0);
		glVertex3f(1 - i / 100.0, i / 100.0, 0.0);
	}

	glEnd();//s-a terminat desenarea

	glFlush();//se afiseaza rezultatul pe ecran
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);//functie de initializare necesara pentru crearea ferestrei
	glutCreateWindow("Exemplu");//se creaza fereastra
	glutDisplayFunc(Display);//se apeleaza functia Display pentru a afisa liniile 
	glColor3f(1, 0, 0);//coloreaza liniile in rosu
	glutMainLoop();//functie callback 

    return 0;
}

