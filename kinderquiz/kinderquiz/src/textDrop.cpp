// Std. Includes
#include <iostream>
#include <map>
#include <string>
// GLEW
//#define GLEW_STATIC
//#include <GLEW/glew.h>
#include <GLEW/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// GLM
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "../Shader.h"
#include "../text.h"

// Properties
const unsigned int WIDTH = 800, HEIGHT = 600;


GLfloat j = 500.0f;
GLfloat k = 500.0f;
GLfloat l = 500.0f;
GLfloat m = 500.0f;


using namespace std;
// The MAIN function, from here we start our application and run the Game loop
int main()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "KinderQuiz", nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);

    // Initialize GLEW to setup the OpenGL Function pointers
    glewExperimental = GL_TRUE;
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, WIDTH, 0, HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    Text text(WIDTH, HEIGHT, "./fonts/Calibri.ttf");

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check and call events
        glfwPollEvents();
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        string f1("apple");
        string f2("mango");
        string f3("orange");
        string f4("banana");

        for (int i = 0; i <= 1; i++)
        {
            j -= 0.08;
            k -= 0.08;
            l -= 0.08;
            m -= 0.08;

            text.RenderText(f1, (GLfloat)250.0f, j, 0.6f, glm::vec3(0.5, 0.8f, 0.2f));
            text.RenderText(f2, (GLfloat)400.0f, k, 0.6f, glm::vec3(0.5, 0.8f, 0.2f));
            text.RenderText(f3, (GLfloat)100.0f, l, 0.6f, glm::vec3(0.5, 0.8f, 0.2f));
            text.RenderText(f4, (GLfloat)550.0f, m, 0.6f, glm::vec3(0.5, 0.8f, 0.2f));
        }

        // Swap the buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
