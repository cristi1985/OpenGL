#include <iostream>
#include <GL/Glut.h>

int meniu_main, submeniu3D, submeniu2D, xrotate, yrotate, zrotate;

void idle();

void init()
{
	glPointSize(40.0);
}

//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON); // initializare desen poligon
//	glVertex2f(0.0, 0.0);//stabilire coordonate triunghi
//	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
//	glVertex2f(0.0, 200.0);//stabilire coordonate triunghi
//	glEnd();//sfarsit Desenare
//
//	glFlush();//executare functie
//
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POINTS);
//	glVertex2i(0, 0);
//	glVertex2i(200, 200);
//	glVertex2i(380, 20);
//	glEnd();
//	glFlush();
//
//}

void displayTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);//stabilire culoare triunghi
	glBegin(GL_POLYGON); // initializare desen poligon
	glVertex2f(0.0, 0.0);//stabilire coordonate triunghi
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(0.0, 200.0);//stabilire coordonate triunghi
	glEnd();//sfarsit Desenare
	glFlush();//executare functie

}

void displayRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(50.0, 0);//conteaza ordinea in care punem coordonatele, pt Quaduri se incepe din stanga jos
	glVertex2f(100.0, 0);//dreapta jos
	glVertex2f(100, 50);//stanga sus
	glVertex2f(50, 50);//dreapta sus
	glEnd();
	glFlush();
}

void displayTorus()
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8, 0.2, 1.0);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(180, 150, 0);
	/*xrotate = yrotate = zrotate = 30;
	xrotate = 33;
	yrotate = 40;
	glRotated(xrotate, 1.0, 0.0, 0.0);
	glRotated(yrotate, 0.0, 1.0, 0.0);*/
	//glRotated(20, 0.0, 15.0, 1.0);
	glutWireTorus(100.0, 25.0, 20, 20);
	glPopMatrix();
	//glutSwapBuffers();
	glEnd();
	glFlush();
	/*glBegin(GL_POINTS);
	glFlush();
	
	glutIdleFunc(idle)*/;
	glutPostRedisplay();

}

void displayTeapot()
{

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8, 0.2, 1.0);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(180, 150, 0);
	
	glutSolidTeapot(20);
	glPopMatrix();
	
	glEnd();
	glFlush();
	

	
	glutPostRedisplay();


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
			printf("Torus\n");
			displayTorus();
			//glClearColor(0.0, 0.0, 0.0, 0.0);
			glutDisplayFunc(displayTorus);
			//glutIdleFunc(idle);
			glutReshapeFunc(reshape);

			break;
		case 1:
			printf("Ceainic\n");
			glutDisplayFunc(displayTeapot);
			glutReshapeFunc(reshape);

			break;

	}
}

void submenu_2d(int key)
{
	switch (key)
	{
	case 0:
		printf("Triunghi\n");
		displayTriangle();
		glutDisplayFunc(displayTriangle);
		glutReshapeFunc(reshape);

		break;
	case 1:
		printf("Dreptunghi\n");
		displayRectangle();
		glutDisplayFunc(displayRectangle);
		glutReshapeFunc(reshape);

		break;
	}
}

void idle()
{
	yrotate += 1;
	displayTorus;
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
	glutAddMenuEntry("Deseneaza Torus", 0);
	glutAddMenuEntry("Deseneaza ceainic", 1);

	submeniu2D = glutCreateMenu(submenu_2d);
	glutAddMenuEntry("Triunghi", 0);
	glutAddMenuEntry("Dreptunghi", 1);

	meniu_main = glutCreateMenu(meniu_principal);//creeaza meniul
	glutAddSubMenu("Obiecte 3D", submeniu3D);
	glutAddSubMenu("Obiected 2D", submeniu2D);
	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//

	

	
	

	glutMainLoop();
	return 0;

}