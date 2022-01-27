#include "ShapeScreen.h"
#include <math.h>

//Constructor
ShapeScreen::ShapeScreen()
{
	screenWidth = 800;
	screenHeight = 600;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//ViewPort
void changeViewPortShape(int w, int h)
{
	glViewport(0, 0, w, h);
}

void ShapeScreen::drawRectangle()
{
	glBegin(GL_QUADS); // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	/*Top Left*/
	glVertex2f(-0.2, -0.6);
	/*Bottom Left*/
	glVertex2f(-0.2, -0.9);
	/*Bottom Right*/
	glVertex2f(0.2, -0.9);
	/*Top Right*/
	glVertex2f(0.2, -0.6);
	glEnd();
}

void ShapeScreen::drawSquare()
{
	glBegin(GL_QUADS); // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	/*Top Left*/
	glVertex2f(-0.125, -0.6);
	/*Bottom Left*/
	glVertex2f(-0.125, -0.9);
	/*Bottom Right*/
	glVertex2f(0.125, -0.9);
	/*Top Right*/
	glVertex2f(0.125, -0.6);
	glEnd();
}

void ShapeScreen::drawTriangle()
{
	//Triangle  
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(-0.2f, -0.8f);
	glVertex2f(0.2f, -0.8f);
	glEnd();

}

void ShapeScreen::drawCircle()
{
	GLfloat x = 0.0f;
	GLfloat y = -0.75f;
	GLfloat rad = 0.15f;
	int triangleAmount = 40;
	GLfloat PI = 3.142;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	int R = 255;
	int G = 0;
	int B = 0;
	glColor3ub(R, G, B);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x + (rad * cos(i * twicePi / triangleAmount)),
			y + (rad * sin(i * twicePi / triangleAmount)));
	}
	glEnd();

}

void ShapeScreen::drawChoices()
{
	glColor3f(1, 0, 0);
	glRasterPos3f(-0.55, 0.8, 0);
	char opt1[] = "Circle";
	for (int i = 0; i < strlen(opt1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt1[i]);
	}

	glColor3f(1, 0, 0);
	glRasterPos3f(-0.25, 0.8, 0);
	char opt2[] = "Rectangle";
	for (int i = 0; i < strlen(opt2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt2[i]);
	}

	glColor3f(1, 0, 0);
	glRasterPos3f(0.05, 0.8, 0);
	char opt3[] = "Triangle";
	for (int i = 0; i < strlen(opt3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt3[i]);
	}

	glColor3f(1, 0, 0);
	glRasterPos3f(0.35, 0.8, 0);
	char opt4[] = "Square";
	for (int i = 0; i < strlen(opt4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt4[i]);
	}
}

void ShapeScreen::renderShape()
{
	ShapeScreen::drawChoices();
	ShapeScreen::drawTriangle();
	glutSwapBuffers();
}

void ShapeScreen::display(int argc, char* argv[])
{
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(screenWidth, screenHeight);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Kinder Quiz");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPortShape);
	//glutMouseFunc(processMouse);
	//glutMotionFunc(processMousePassiveMotion);
	glutDisplayFunc(renderShape);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		exit;
	}

	glutMainLoop();
}
