#include "stdafx.h"
#include <gl/freeglut.h>
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//Se sterge ce era inainte pe ecran
	glColor3f(0, 1, 0);//seteaza culoarea ce va fi desenata
	glBegin(GL_LINES);//se initializeaza desenarea -desenam linii
	// Cadran 1
	for (int i = 0; i<20; i++)//se creaza mai multe linii fiecare cu aceeasi origine si alte coordonate finale
	{
		glVertex3f(0, 0, 0);//originea liniei
		glVertex3f(1 - i / 20.0, i / 20.0, 0);//coordonatele finale ale liniei
	} // Cadran 2
	glColor3f(1, 0.4, 0);//seteaza alta culoare
	for (int i = 0; i<20; i++)
	{
		glVertex3f(0, 0, 0);//originea liniei
		glVertex3f(-1 + i / 20.0, i / 20.0, 0);//coordonatele finale ale liniei
	} // Cadran 3
	glColor3f(1, 0.4, 1);
	for (int i = 0; i<20; i++)
	{
		glVertex3f(0, 0, 0);
		glVertex3f(-1 + i / 20.0, -i / 20.0, 0);
	}
	// Cadran 4
	glColor3f(0.8, 0.4, 0.2);
	for (int i = 0; i<20; i++)
	{
		glVertex3f(0, 0, 0);
		glVertex3f(1 - i / 20.0, -i / 20.0, 0);
	}
	glEnd();
	glFlush(); //se termina desenarea
	glColor3f(0, 0, 1);//nu face nimic pt ca este in afara procedurii de desenare
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);//se initializeaza afisarea
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//se seteaza bufferul de adancime a culorii si tipul culorii in cazul de fata o singura culorare sau RGB
	glutInitWindowSize(600, 600);//se seteaza dimensiunea initiala a ferestrei
	//se specifica modelul de culoare al ferestrei: un singur buffer si culoare RGB
	glutCreateWindow("laborator 3");//creeaza fereastra in care se reda grafica

	glutDisplayFunc(Display);//se calculeaza si se initializeaza imaginea prin chemarea functiei utilizator display
	glutMainLoop();//functie callback prin care se afiseaza fereastra creata in glutDisplayFunc
	return 0;
}
