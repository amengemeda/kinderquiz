#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

//#include<glad/glad.h>
#include <GLEW/glew.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include<string>
using namespace std;
string get_file_contents(const char* filename);

class ShaderClass
{
public:
	// Reference ID of the Shader Program
	int ID;
	// Constructor that build the Shader Program from 2 different shaders
	ShaderClass(const char* vertexFile, const char* fragmentFile);

	// Activates the Shader Program
	void Activate();
	// Deletes the Shader Program
	void Delete();
};
#endif