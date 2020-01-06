// Ex3Lab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL\glut.h>
#include<math.h>

void display()
{

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON); // initializare desen poligon
	glVertex2f(0.0, 0.0);//
	glVertex2f(200.0, 200.0);//
	glVertex2f(0.0, 200.0);//
	glVertex2f(100.0, 300.0);//
	glEnd();//sfarsit Desenare
	glFlush();//executare functie

	glBegin(GL_TRIANGLES);//initializare desen poligon
	glColor3f(1.0, 0.0, 0.0);//culoarea de desenare
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 400.0);//stabilire coordonate triunghi
	glEnd();//sfisit desenare
	glFlush();//executare functie

	glBegin(GL_LINE_LOOP);//initializare desen poligon
	glColor3f(1.0, 1.0, 0.0);//culoarea de desenare
	glVertex2f(100.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(200.0, 0.0);//stabilire coordonate triunghi
	glVertex2f(300.0, 400.0);//stabilire coordonate triunghi
	glEnd();//sfarsit desenare
	glFlush();//executare functie
	
	glPointSize(50);
	glBegin(GL_POINTS);//se creaza puncte pentru un cerc
	glVertex2f(200.0, 200.0);
	glEnd();
	glFlush();


}
void reshape(int w, int h)//functie redesenare
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//initializare sistem de coordonate
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);//stabileste volumul de vedere folosind o proiectie ortografica
}

int meniu_1, meniu_2,  meniu_main;

void meniu_principal(int key)
{
	if (key == 0)
	{
		exit(0);
	}
}

void callback_1(int key)
{
	switch (key)
	{
	case 0:
		printf("Polygon\n");
		break;
	case 1:
		printf("Polygon\n");
		break;
	}
}

void callback_2(int key)
{
	switch (key)
	{
	case 0:
		printf("Triunghiuri\n");
		break;
	case 1:
		printf("Triunghiuri\n");
		break;
	}
}

void callback_3(int key)
{
	switch (key)
	{
	case 0:
		printf("Line loop\n");
		break;
	case 1:
		printf("Line loop\n");
		break;

	}
}

GLint x = 10;
GLint y = 20;
GLint WindowWidth = 400;
GLint WindowHight = 400;


void mouseHandler(int button, int state, int mouse_x, int mouse_y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x = mouse_x;
		y = WindowHight - mouse_y;
		glColor3f(1, 0, 0);
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		printf("x=%d , y=%d \n", x, y);
		glEnd();
		glFlush();
		glClear(GL_COLOR_BUFFER_BIT);
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Cristian Simion");
	
	glutDisplayFunc(display);//se randeaza vederea
	glutReshapeFunc(reshape);

	meniu_1 = glutCreateMenu(callback_1);
	glutAddMenuEntry("Polygon", 0);
	glutAddMenuEntry("Polygon", 1);
	meniu_2 = glutCreateMenu(callback_2);
	glutAddMenuEntry("Triunghiuri", 0);
	glutAddMenuEntry("Triunghiuri", 1);



	meniu_main = glutCreateMenu(meniu_principal);
	glutAddSubMenu("Polygon", meniu_1);
	glutAddSubMenu("Triunghi", meniu_2);

	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}

