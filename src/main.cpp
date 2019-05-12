#include <cstdio>
#include <gl/glew.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include "Mesh.hpp"
#include "Context.hpp"
#include "Triangle.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Cube.hpp"
#include <cmath>

int running = 1;
Context ctx;
Triangle test;
Cube cube;
Shader shader;
Camera camera;
GLuint model_loc;
GLuint view_loc;
GLuint projection_loc;


void init()
{
	ctx.init();
	test.init();
	test.generate();
	cube.init();
	cube.generate();

	//cube.position.x = 2;
	//cube.position.z = -4;

	shader.createShader("assets/vertex.glsl", "assets/fragment.glsl");

	camera.setup(70.0f, 16.0f / 9.0f, 0.1f, 100.0f);
	camera.position.x = 4;
	camera.position.y = 3;
	camera.position.z = 3;

	camera.target = glm::vec3(0, 0, 0);

	view_loc = shader.getUniform("view");
	projection_loc = shader.getUniform("projection");
	model_loc = shader.getUniform("model");
}

void update()
{
	int esc = glfwGetKey(ctx.window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	if (esc)
	{
		running = 0;
	}
	if (glfwWindowShouldClose(ctx.window))
	{
		running = 0;
	}

	cube.position.x = 3 * sin(2 * cube.rotation.y);
	cube.position.y = 3 * cos(2 * cube.rotation.y);
	cube.rotation.y += 0.01f;
	cube.rotation.x += 0.01f;

	test.rotation.y += 0.01f;

	camera.update();
	test.update();
	cube.update();
}

void draw()
{
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &test.getMatrix()[0][0]);
	//printf("SANITY CHECK\n%s\n%s\n%s\n", glm::to_string(camera.getProjectionMatrix()).c_str(), glm::to_string(camera.getMatrix()).c_str(), glm::to_string(test.getMatrix()).c_str());
	test.draw();
	shader.detach();

	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &cube.getMatrix()[0][0]);
	//printf("SANITY CHECK\n%s\n%s\n%s\n", glm::to_string(camera.getProjectionMatrix()).c_str(), glm::to_string(camera.getMatrix()).c_str(), glm::to_string(test.getMatrix()).c_str());
	cube.draw();
	shader.detach();
}

int main(int argc, char* argv[])
{
	printf("hello world!\n");

	init();

	while (running)
	{
		update();
		
		ctx.clear();
		
		draw();

		ctx.draw();
		ctx.poll();
	}
}