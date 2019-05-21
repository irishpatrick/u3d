#include "Mouse.hpp"

float Mouse::x = 0.0f;
float Mouse::y = 0.0f;

void Mouse::attach(GLFWwindow* window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	glfwSetCursorPosCallback(window, Mouse::move_callback);
	glfwSetMouseButtonCallback(window, Mouse::click_callback);
	glfwSetScrollCallback(window, Mouse::scroll_callback);
}

void Mouse::move_callback(GLFWwindow* window, double mx, double my)
{
	int w = -1;
	int h = -1;
	glfwGetWindowSize(window, &w, &h);
	x = (float)mx / (float)w - 0.5f;
	y = (float)my / (float)h - 0.5f;
}

void Mouse::click_callback(GLFWwindow*, int, int, int)
{
}

void Mouse::scroll_callback(GLFWwindow*, double, double)
{
}
