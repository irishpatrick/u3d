#include "Context.hpp"
#include <cstdio>
#include <iostream>

void glfwErrorCallback(int, const char* err)
{
	std::cout << "GLFW Error: " << err << std::endl;
}

Context::Context()
{
	window = nullptr;
}

Context::~Context()
{

}

void Context::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "init failed\n");
	}

	glfwSetErrorCallback(glfwErrorCallback);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	glfwWindowHint(GLFW_SAMPLES, 16);
	glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	//window = glfwCreateWindow(mode->width, mode->height, "title", glfwGetPrimaryMonitor(), NULL);
    window = glfwCreateWindow(800, 600, "title", NULL, NULL);
    if (window == NULL)
	{
		fprintf(stderr, "window error\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "glew error\n");
		return;
	}

	if (glGenVertexArrays == NULL)
	{
		printf("big issues\n");
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glClearColor(0.87f, 0.87f, 0.87f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void Context::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::draw()
{
	glfwSwapBuffers(window);
}

void Context::poll()
{
	glfwPollEvents();
}
