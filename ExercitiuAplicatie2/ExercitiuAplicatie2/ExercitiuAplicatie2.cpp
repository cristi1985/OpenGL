
#include <stdlib.h>
#include "stdafx.h"
#include <GL/glut.h>

void roteste_Y(int p_grade)//functie rotire pe axa Y
{
	glRotatef(p_grade, .0, 1, .0);
	glutPostRedisplay();//se reinitializeaza continutul ferestrei
}
void roteste_X(int p_grade)
{
	glRotatef(p_grade, 1., 0., .0);
	glutPostRedisplay();
}
void OnKeyPress(unsigned char key, int x, int y)
{
	if (key == 27)//iesire program daca se apasa Escape
		exit(0);
	switch (key)
	{
	case 'q':
	case 'Q':

		roteste_Y(3);//Rotire axa Y in sensul acelor de ceasornic daca se apasa Q
		break;
	case 'w':
	case 'W':
		roteste_Y(-3);//Rotire axa Y invers acelor de ceasornic daca se apasa W
		break;

	case 'a':
	case 'A':

		roteste_X(3);//Rotire axa X in sensul acelor de ceasornic daca se apasa A 
		break;
	case 's':
	case 'S':
		roteste_X(-3);//Rotire axa X invers acelor de ceasornic daca se apasa S
		break;
	}
}
void OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//verificare daca se apasa left mouse button se roteste pe axa Y
	{
		roteste_Y(20);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//verificare daca se apasa right mouse button se roteste pe axa X
	{
		roteste_Y(-20);
	}
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	int l = 10;

	for (double i = 0; i <= l; i++) {
		glBegin(GL_LINE_LOOP); //se creeaza o linie inchisa
		glColor3f(1 - i / 10, i / 20, 1);
		glVertex3f(1 - i / l, 0, 0);
		glVertex3f(0, 1 - i / l, 0);
		glVertex3f(-(1 - i / l), 0, 0);
		glVertex3f(0, -(1 - i / l), 0);
		glEnd();
	}

	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//se specifica modelul de culoare al ferestrei: un singur buffer si culoare RGB
	glutCreateWindow("Curs 3");
	glutKeyboardFunc(OnKeyPress);
	glutMouseFunc(OnMouseClick);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

