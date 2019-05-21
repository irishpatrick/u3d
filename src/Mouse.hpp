#pragma once

#include "gl_includes.hpp"

class Mouse
{
public:
	static void attach(GLFWwindow*);
	static void move_callback(GLFWwindow*, double, double);
	static void click_callback(GLFWwindow*, int, int, int);
	static void scroll_callback(GLFWwindow*, double, double);
    static void update();

	static float x;
	static float y;

private:
    static GLFWwindow* window;
};
