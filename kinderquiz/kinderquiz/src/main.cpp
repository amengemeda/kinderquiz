
#include <Windows.h>
#include <GLEW/glew.h>
#include <GLUT\freeglut.h>
#include <iostream>
#include "../FirstScreen.h"
using namespace std;


int main(int argc, char* argv[]) {

	FirstScreen screen;
	screen.display(argc, argv);
	return 0;
}

