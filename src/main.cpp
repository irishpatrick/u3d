#include <cstdio>
#include "gl_includes.hpp"
#include <cmath>
#include "Mesh.hpp"
#include "Context.hpp"
#include "Triangle.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Cube.hpp"
#include "Texture.hpp"
#include "Util.hpp"
#include "Assets.hpp"
#include "TestMesh.hpp"

int running = 1;
Context ctx;
Triangle test;
Cube cube;
Shader shader;
Camera camera;
GLuint model_loc;
GLuint view_loc;
GLuint projection_loc;
GLuint has_tex_loc;
Texture crate;
Mesh loaded;
TestMesh tm;

void init()
{
	ctx.init();

	test.init();
	test.generate();
	
	cube.init();
	cube.generate();

	tm.init();
	tm.generate();

	loaded = Assets::loadMesh("assets/cube.obj");
	
	loaded.generate();
	//loaded.position.z = -1;
	//loaded.position.x = -1;

	crate.load("assets/crate_diffuse.png");

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
	has_tex_loc = shader.getUniform("has_texture");
}

void update(float delta)
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
	cube.rotation.y += 0.5f * delta;
	cube.rotation.x += 0.5f * delta;

	test.rotation.y += 0.5f * delta;

	loaded.rotation.x += 0.5f * delta;

	camera.rotation.y += 0.2f * delta;

	camera.update();
	test.update();
	cube.update();
	loaded.update();
	tm.update();
}

void draw()
{
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &test.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 0);
	//printf("SANITY CHECK\n%s\n%s\n%s\n", glm::to_string(camera.getProjectionMatrix()).c_str(), glm::to_string(camera.getMatrix()).c_str(), glm::to_string(test.getMatrix()).c_str());
	test.draw();
	shader.detach();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crate.getId());
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &loaded.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 1);
	loaded.draw();
	shader.detach();

	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &tm.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 1);
	tm.draw();
	shader.detach();
	glBindTexture(GL_TEXTURE_2D, 0);
	

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crate.getId());
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &cube.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 1);
	//printf("SANITY CHECK\n%s\n%s\n%s\n", glm::to_string(camera.getProjectionMatrix()).c_str(), glm::to_string(camera.getMatrix()).c_str(), glm::to_string(test.getMatrix()).c_str());
	cube.draw();
	shader.detach();
	glBindTexture(GL_TEXTURE_2D, 0);
}

int main(int argc, char* argv[])
{
	printf("hello world!\n");

	init();

	unsigned int now, then;
	then = Util::currentTimeMillis();

	while (running)
	{
		now = Util::currentTimeMillis();
		float delta = (float)(now - then);
		update(delta/1000.0f);
		
		ctx.clear();
	
		draw();

		ctx.draw();
		ctx.poll();

		then = now;
	}
}
