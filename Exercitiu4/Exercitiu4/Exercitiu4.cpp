#include "stdafx.h"
#include <gl/freeglut.h>
#include<math.h>
#include<stdio.h>
#include <stdlib.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(40.0);
	glShadeModel(GL_FLAT);//defines the type of shading flat so smooth
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	GLint a, b, c, i, j, x, y;
	b = 20;
	c = 20;
	y = 300;
	for (i = 0; i<3; i++) {
		a = 300;
		x = 20;
		for (j = 0; j<3; j++) {
			glVertex2i(a, b);
			glVertex2i(x, b);
			glVertex2i(x, y);
			glVertex2i(a, y);
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			a += 40;
			x += 40;
		}
		b += 2 * c;
		y += 2 * c;
	}
	glEnd();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(600, 100);
	glutCreateWindow("puncte");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
