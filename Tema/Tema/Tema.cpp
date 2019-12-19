#include <iostream>
#include <GL/Glut.h>

int meniu_main, submeniu3D, submeniu2D;

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

void display2(int noVertex)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,  , 0.0);
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

void submenu_3d(int key)
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

void submenu_2d(int key)
{
	switch (key)
	{
	case 0:
		printf("Triunghi");
		break;
	case 1:
		printf("Dreptunghi");
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
	submeniu3D = glutCreateMenu(submenu_3d);
	glutAddMenuEntry("Selectie", 0);
	glutAddMenuEntry("Editare", 1);

	submeniu2D = glutCreateMenu(submenu_2d);
	glutAddMenuEntry("Triunghi", 0);
	glutAddMenuEntry("Dreptunghi", 1);

	meniu_main = glutCreateMenu(meniu_principal);//creeaza meniul
	glutAddSubMenu("Obiecte 3D", submeniu3D);
	glutAddSubMenu("Obiected 2D", submeniu2D);
	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);


	glutMainLoop();
	return 0;

}