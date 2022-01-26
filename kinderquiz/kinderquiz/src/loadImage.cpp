#define STB_IMAGE_IMPLEMENTATION
#include "../MainScreen.h";
using namespace std;

void processInput(GLFWwindow* window);
/*
GLfloat j = 500.0f;
GLfloat k = 500.0f;
GLfloat l = 500.0f;
GLfloat m = 500.0f;
*/
int smain()
{
    //call initialize method
    MainScreen screen;
    GLFWwindow* window = screen.initializeWindow();

    Text text(screen.SCR_WIDTH, screen.SCR_HEIGHT, "./fonts/Calibri.ttf");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
        // positions          // colors           // texture coords
         0.2f,  -0.55f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.2f, -0.95f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.2f, -0.95f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.2f,  -0.55f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // Generates Shader object using shaders defualt.vert and default.frag
    ShaderClass shaderProgram("default.vert", "default.frg");

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO attributes such as coordinates and colors to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    // load and create a texture 
    GLuint texture;
    texture = screen.createTexture();

    // Load the image on the texture
    screen.loadImage();


    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // render container
        //activate the shader before any calls to glUniform
        shaderProgram.Activate();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();

        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        // render
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);


        /*
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

        */
        

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

