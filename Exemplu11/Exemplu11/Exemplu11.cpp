// Exemplu11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <GL/glut.h>

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);//elibereaza bufferul

	glBegin(GL_TRIANGLES);//creeaza doua triunghiuri
	glColor3f(1, 1, 1);//seteaza culoarea alba
	glVertex3f(0, 0, 0);//creeaza primul vetez
	glVertex3f(-1, 0, 0);//creeaza al doilea vertex
	glVertex3f(0, 1, 0);//creeaza al treilea vertex

	glColor3f(1, 0, 0);//seteaza culoarea rosie
	glVertex3f(0, 0, 0);//creeaza primul vertex
	glVertex3f(1, 0, 0);//creeaza al doilea vertex
	glVertex3f(0, -1, 0);//creeaza al treile vertex

	glEnd();//se termina desenarea
	glFlush();//se afiseaza desenul
}


int main(int argv, char **argc)
{
	glutInit(&argv, argc);//functie de initializeaza
	glutCreateWindow("Exemplu");//functie de creare fereastra
	glutDisplayFunc(Display);//afisare desenului
	glutMainLoop();//functie de callback
    return 0;
}

