#pragma once
#include <iostream>

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <map>
#include <string>
#include <math.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H

// GL includes
#include "Shader.h"
#include "text.h"


#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
using namespace std;

class MainScreen
{
public:
	 unsigned int SCR_WIDTH;
	 unsigned int SCR_HEIGHT;
	MainScreen();
	GLFWwindow* initializeWindow();
	GLuint createTexture();
	void loadImage();

private:

};




