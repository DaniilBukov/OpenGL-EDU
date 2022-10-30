#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

int main(void)
{
    GLFWwindow* window;

		/* window properties */
		const unsigned int windowWidth = 640;
		const unsigned int windowHeight = 480;
		const char* windowName = "Hello world";


    /* Initialize the library */
    if (!glfwInit())
        return -1;
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

		if (!gladLoadGL())
		{
			std::cout << "Can't load GLAD!" << std::endl;
			return -1;
		}

		//glViewport(0, 0, windowWidth, windowHeight);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;


		/* triangle vertex array */
		float vertices[] = {
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f, 0.5f, 0.0f
		};

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
				processInput(window);
        /* Render here */
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
		glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
}
