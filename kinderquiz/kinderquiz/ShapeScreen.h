#pragma once
#include <Windows.h>
#include <GLEW/glew.h>
#include <GLUT\freeglut.h>
#include <iostream>

using namespace std;
class ShapeScreen
{
public:

	int screenWidth;
	int screenHeight;
	ShapeScreen();
	//void changeViewPort(int w, int h);
	static void drawCircle();
	static void drawRectangle();
	static void drawTriangle();
	static void drawSquare();
	static void renderShape();
	static void drawChoices();
	void display(int argc, char* argv[]);

private:

};

