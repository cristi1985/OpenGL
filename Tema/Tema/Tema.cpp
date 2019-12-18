#include <iostream>
#include <GL/Glut.h>

int meniu_main;

void init()
{
	glPointSize(40.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON); // initializare desen poligon
	glVertex2f(0.0, 0.0);//stabilire coordonate triunghi
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(0.0, 200.0);//stabilire coordonate triunghi
	glEnd();//sfarsit Desenare

	glFlush();//executare functie

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(0, 0);
	glVertex2i(200, 200);
	glVertex2i(380, 20);
	glEnd();
	glFlush();

}

void reshape(int w, int h) //functie redesenare
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//stabiliere viewport la dimensiunea ferestrei
	glMatrixMode(GL_PROJECTION); //specificare matrice modificabila la valoare argumentului de modificare
	glLoadIdentity();//initializare sistem coordonate
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h); //stabileste volumul de vedere folosind o proiectie otrografica

}

void meniu_principal(int key)
{
	if (key == 0)
	{
		//glutDestroyWindow(window);
		exit(0);
	}

}

void submenu1(int key)
{
	switch (key)
	{
		case 0:
			printf("Selectie\n");
			break;
		case 1:
			printf("Editare\n");
			break;

	}
}

int main(int argc, char** argv)
{
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Exemplul 1");// functie creare fereastra
	init();
	//Meniuri
	meniu_main = glutCreateMenu(meniu_principal);//creeaza meniul 
	glutAddMenuEntry("Exit", 0);
	glutAddMenuEntry("Sphere", 1);
	glutAddMenuEntry("2", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);


	glutMainLoop();
	return 0;

}
