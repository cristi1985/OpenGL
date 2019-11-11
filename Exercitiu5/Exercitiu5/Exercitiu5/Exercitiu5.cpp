#include <stdio.h>
#include <GL/glut.h>

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//Clear the buffer 

	glBegin(GL_POINTS);//Start drawing using points 
	glVertex3f(0, 0, 0);//Specify the 3d  coordinates with float
	glVertex3f(1, 1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(-1, -1, 0);
	glEnd();//End the drawing 

	glFlush();//Executes the drawing
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//This is necessary to initialize the OpenGl window
	glutCreateWindow("Example");//Create the window
	glutDisplayFunc(Display);//Callback function to the current window to display the vertices

	//Set Point Size to 10 from default 1
	glPointSize(10);

	glutMainLoop();

	return 0;
}