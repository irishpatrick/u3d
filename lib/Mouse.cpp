#include "Mouse.hpp"

GLFWwindow* Mouse::window = nullptr;

float Mouse::x = 0.0f;
float Mouse::y = 0.0f;

double lx = 0.0f;
double ly = 0.0f;

void Mouse::attach(GLFWwindow* w)
{
    window = w;
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	//glfwSetCursorPosCallback(window, Mouse::move_callback);
	//glfwSetMouseButtonCallback(window, Mouse::click_callback);
	//glfwSetScrollCallback(window, Mouse::scroll_callback);
}

void Mouse::move_callback(GLFWwindow* window, double mx, double my)
{
	int w = -1;
	int h = -1;
	glfwGetWindowSize(window, &w, &h);
	float tx = (float)mx / (float)w - 0.5f;
	float ty = (float)my / (float)h - 0.5f;
	x = (float)(tx - lx);
	y = (float)(ty - ly);
	lx = tx;
	ly = ty;
}

void Mouse::click_callback(GLFWwindow*, int, int, int)
{
}

void Mouse::scroll_callback(GLFWwindow*, double, double)
{
}

void Mouse::update()
{

	int w = -1;
	int h = -1;
	glfwGetWindowSize(window, &w, &h);
    double mx, my;
    glfwGetCursorPos(window, &mx, &my);

    x = (float)(mx / (double)w - 0.5);
    y = -1.0f * (float)(my / (double)h - 0.5);

    glfwSetCursorPos(window, (double)(w)/2.0, (double)(h)/2.0);
}
