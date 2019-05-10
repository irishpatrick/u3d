#pragma once

#include <gl/glew.h>
#include <glfw/glfw3.h>

class Context
{
public:

	Context();
	~Context();

	void init();
	void draw();
	void clear();
	void poll();

	GLFWwindow* window;
};