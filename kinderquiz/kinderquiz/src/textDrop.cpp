// Std. Includes
#include "../MainScreen.h"

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
    MainScreen screen;
    GLFWwindow* window = screen.initializeWindow();
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

