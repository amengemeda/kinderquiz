#include "FirstScreen.h"

//Constructor
FirstScreen::FirstScreen()
{
	screenWidth = 800;
	screenHeight = 600;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//ViewPort
void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

//Code for game title
void FirstScreen::drawGameTitle()
{
	glColor3f(1, 0, 0);
	glRasterPos3f(-0.2, 0.5, 0);
	char title[] = "Kinder Quiz";
	for (int i = 0; i < strlen(title); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
	}
}

//Code for HighScore
void FirstScreen::drawHighScore()
{
	glColor3f(1, 0, 0);
	glRasterPos3f(-0.25, 0.3, 0);
	char high_score[] = "High Score: 129";
	for (int i = 0; i < strlen(high_score); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, high_score[i]);
	}
}

//Code for fruits button 
void FirstScreen::drawFruitsButton()
{
	//Fruits Button
	glBegin(GL_QUADS); // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	/*Top Left*/
	glVertex2f(-0.6, -0.2);
	/*Bottom Left*/
	glVertex2f(-0.6, -0.5);
	/*Bottom Right*/
	glVertex2f(-0.2, -0.5);
	/*Top Right*/
	glVertex2f(-0.2, -0.2);
	glEnd();

	glColor3f(0, 0, 0);
	glRasterPos3f(-0.5, -0.375, 0);
	char fruits[] = "Fruits";
	for (int i = 0; i < strlen(fruits); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, fruits[i]);
	}
}

//Code for shapes button
void FirstScreen::drawShapesButton()
{
	//Shapes Button
	glBegin(GL_QUADS);   // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	/*Top Left*/
	glVertex2f(0.2, -0.2);
	/*Bottom Left*/
	glVertex2f(0.2, -0.5);
	/*Bottom Right*/
	glVertex2f(0.6, -0.5);
	/*Top Right*/
	glVertex2f(0.6, -0.2);
	glEnd();

	glColor3f(0, 0, 0);
	glRasterPos3f(0.3, -0.375, 0);
	char shapes[] = "Shapes";
	for (int i = 0; i < strlen(shapes); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, shapes[i]);
	}
}

//Code for exit button
void FirstScreen::drawExitButton()
{
	//Exit Button
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);
	/*Top Left*/
	glVertex2f(-0.15, -0.75);
	/*Bottom Left*/
	glVertex2f(-0.15, -0.9);
	/*Bottom Right*/
	glVertex2f(0.15, -0.9);
	/*Top Right*/
	glVertex2f(0.15, -0.75);
	glEnd();

	glColor3f(0, 0, 0);
	glRasterPos3f(-0.05, -0.85, 0);
	char exit[] = "Exit";
	for (int i = 0; i < strlen(exit); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exit[i]);
	}
	glutSwapBuffers();
}

// Code for rendering components
void render() {
	FirstScreen::drawGameTitle();
	FirstScreen::drawHighScore();
	FirstScreen::drawFruitsButton();
	FirstScreen::drawShapesButton();
	FirstScreen::drawExitButton();
}

//Code for processing mouse action
void processMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		//Code for click
		if (x >= 160 && x <= 320 && y >= 360 && y <= 450) {
			cout << "Fruits";
		}
		else if (x >= 480 && x <= 640 && y >= 360 && y <= 450) {
			cout << "Shapes";
		}
		else if (x >= 340 && x <= 460 && y >= 525 && y <= 570) {
			glutDestroyWindow(1);
		}

	}

}

//Code for displaying the screen
void FirstScreen::display(int argc, char* argv[])
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
	glutReshapeFunc(changeViewPort);
	glutMouseFunc(processMouse);
	//glutMotionFunc(processMousePassiveMotion);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		exit;
	}

	glutMainLoop();
}


