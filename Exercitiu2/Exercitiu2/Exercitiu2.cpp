#include "stdafx.h"
#include <gl/freeglut.h>

void init()//functia initiere
{
	// glClearColor (0.0, 0.0, 0.0, 0.0);//stabileste culoarea de sters
	// glShadeModel (GL_FLAT);
}
void display()//functia de desenare si afisare
{
	glClear(GL_COLOR_BUFFER_BIT);//sterge urmele de desene din fereastra curenta
	glBegin(GL_POLYGON);//initializare desen poligon
	glColor3f(1.0, 0.0, 0.0);//culoarea de desenare
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 400.0);//stabilire coordonate triunghi
	glEnd();//sfisit desenare
	glFlush();//executare functie
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);//initializare desen poligon
	glColor3f(1.0, 1.0, 0.0);//culoarea de desenare
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 0.0);//stabilire coordonate triunghi
	glVertex2f(400.0, 400.0);//stabilire coordonate triunghi
	glEnd();//sfarsit desenare
	glFlush();//executare functie

}
void reshape(int w, int h)//functia redesenare
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//stabilirea viewportului la dimensiunea ferestrei
	glMatrixMode(GL_PROJECTION);//specificare matrice modificabila la valoare argumentului de modificare
	glLoadIdentity();//initializarea sistemului de coordonate
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);//stabileste volumul de vedere folosind o proiectie ortografica
}
int main(int argc, char** argv) //creare fereastra
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//se specifica modelul de culoare al ferestrei: un singur buffer si culoare RGB
	glutInitWindowSize(600, 600);//initiaza dimensiunea ferestrei principale 600x600 pixeli
	glutInitWindowPosition(200, 10);//initiaza in fereastra principala fereastra de afisare
	glutCreateWindow("TRIUNGHIURI");
	init();
	glutDisplayFunc(display);//se reimprospateza continutul ferestrei
	glutReshapeFunc(reshape);//functia redesenare
	glutMainLoop();//bucla de procesare a evenimentelor
	return 0;
}

