#include <iostream>
#include <GL/Glut.h>

int meniu_main, submeniu3D, submeniu2D;

void displayTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.0, 1.0, 0.0);//stabilire culoare triunghi
	glBegin(GL_POLYGON); // initializare desen poligon
	glVertex2f(0.0, 0.0);//stabilire coordonate triunghi
	glVertex2f(200.0, 200.0);//stabilire coordonate triunghi
	glVertex2f(0.0, 200.0);//stabilire coordonate triunghi
	glEnd();//sfarsit Desenare
	glFlush();//executare functie
	glutSwapBuffers();//schimbare intre buffere 
	glutPostRedisplay();//reafisare fereastra

}

void displayRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);//incepe desenarea
	glVertex2f(50.0, 0);//conteaza ordinea in care punem coordonatele, pt Quaduri se incepe din stanga jos
	glVertex2f(100.0, 0);//dreapta jos
	glVertex2f(100, 50);//stanga sus
	glVertex2f(50, 50);//dreapta sus
	glEnd();//desenarea se termina aici
	glFlush();//golire buffere si executare comenzi de catre motorul de randare 
	glutSwapBuffers();
	glutPostRedisplay();
}

void displayTorus()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.8, 0.2, 1.0);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(180, 150, 0);
	glutWireTorus(100.0, 25.0, 20, 20);
	glPopMatrix();
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void displayTeapot()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.8, 0.2, 1.0);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(180, 150, 0.0f);
	glutWireTeapot(50);
	glPopMatrix();
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();


}

void reshape(int w, int h) //functie redesenare
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//stabiliere viewport la dimensiunea ferestrei
	glMatrixMode(GL_MODELVIEW); //specificare matrice modificabila la valoare argumentului de modificare
	glLoadIdentity();//initializare sistem coordonate
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
			glutDisplayFunc(displayTorus);//stabileste functia de callback pentru fereastra
			glutReshapeFunc(reshape);//se cheama daca se schimba dimensiunea ferestrei
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


int main(int argc, char** argv)
{
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Exemplul 1");// functie creare fereastra
	
	//Meniuri
	submeniu3D = glutCreateMenu(submenu_3d);
	glutAddMenuEntry("Deseneaza Torus", 0);
	glutAddMenuEntry("Deseneaza ceainic", 1);

	submeniu2D = glutCreateMenu(submenu_2d);
	glutAddMenuEntry("Triunghi", 0);
	glutAddMenuEntry("Dreptunghi", 1);

	meniu_main = glutCreateMenu(meniu_principal);//creeaza meniul
	glutAddSubMenu("Obiecte 3D", submeniu3D);//se creaza submeniul si se apeleaza
	glutAddSubMenu("Obiected 2D", submeniu2D);
	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//se ataseaza intrarea in meniul principal de butonul drept al mouse-ului

	glutMainLoop();//functia principala de executare a comenzilor opengl
	return 0;

}