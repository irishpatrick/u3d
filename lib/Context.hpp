#pragma once

#include "gl_includes.hpp"

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