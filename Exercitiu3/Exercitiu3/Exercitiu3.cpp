#include "stdafx.h"
#include <gl/freeglut.h>
#include<math.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//stergere ferestrei
	glPointSize(40);//marime in pixeli a punctului

	double x = 0.5;
	glPointSize(60);
	glBegin(GL_POINTS);//incepem sa definim punctele

	for (GLint i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
			glColor3d(x, 0, x); break;//set color of the vertex
		case 1:
			glColor3d(x, 1, x); break;
		case 2:
			glColor3d(x, x, 0); break;
		case 3:
			glColor3d(0, x, x); break;
		case 4:
			glColor3d(1, x, 1); break;
		}
		glVertex2f(270 - (GLfloat)i * 60, 30);//set the position of the vertex
		x = x + 0.2;
	}
	glEnd();//terminam definirea punctelor
	glFlush();
	glBegin(GL_POINTS);
	x = 0.5;
	for (int i = 1; i<4; i++)
	{
		switch (i)
		{
		case 0:
			glColor3d(x, 0, x); break;
		case 1:
			glColor3d(x, 1, x); break;
		case 2:
			glColor3d(0.3, 0.1, 1); break;
		case 3:
			glColor3d(1, 0, 0.3); break;
		case 4:
			glColor3d(1, x, 1); break;
		}
		glVertex2f(270 - (GLfloat)i * 60, 90);
		x = x + 0.6;
	}
	glEnd();
	glFlush();
	glBegin(GL_POINTS);
	glColor3d(1, 0, 1);
	glVertex2f(150, 150);
	glEnd();
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//seteaza pozitia x si y a ferestrei dupa care steaza width si height
	glMatrixMode(GL_PROJECTION); //specifica ce matrice va fi folosita pentru urmatoarele operatii
	glLoadIdentity(); //initalizare sistem de coordonate
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h); //specifica o regiune ortografica bidimensional 
}//end reshape()

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Multiple Puncte");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
