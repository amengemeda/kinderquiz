#include "Scoreboard.h"
#include <iostream>

int main()
{
    MainScreen screen;
    GLFWwindow* window = screen.initializeWindow();  
    const unsigned int WIDTH = 800, HEIGHT = 600;
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

        // Swap the buffers
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

