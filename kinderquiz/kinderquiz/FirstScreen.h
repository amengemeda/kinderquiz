#pragma once
#include <Windows.h>
#include <GLEW/glew.h>
#include <GLUT\freeglut.h>
#include <iostream>

using namespace std;
class FirstScreen
{
public:

	int screenWidth;
	int screenHeight;
	FirstScreen();
	//void changeViewPort(int w, int h);
	static void drawGameTitle();
	static void drawHighScore();
	static void drawFruitsButton();
	static void drawShapesButton();
	static void drawExitButton();
	//void processMouse(int button, int state, int x, int y);
	void display(int argc, char* argv[]);

private:

};




