#include "Context.hpp"
#include <cstdio>
#include <cstdlib>

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

	glfwWindowHint(GLFW_SAMPLES, 16);
	glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	window = glfwCreateWindow(1024, 768, "title", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "window error\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	//glfwSwapInterval(0);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "glew error\n");
		return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

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