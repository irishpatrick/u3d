#include <cstdio>
#include "gl_includes.hpp"
#include <cmath>
#include "Mesh.hpp"
#include "Context.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"
#include "Util.hpp"
#include "Assets.hpp"
#include "FirstPersonCamera.hpp"
#include "Mouse.hpp"

int running = 1;

Context ctx;

Shader shader;

Camera camera;
Object3D yaw;

GLuint model_loc;
GLuint view_loc;
GLuint projection_loc;
GLuint has_tex_loc;

Texture crate;

Mesh loaded;
Mesh test;

void init()
{
	ctx.init();
	Mouse::attach(ctx.window);

	loaded = Assets::loadMesh("assets/cube.obj");
	test = Assets::loadMesh("assets/cube.obj");
	
	loaded.generate();
	test.generate();

	test.position.x = 4;

	//loaded.addChild(test);

	crate.load("assets/uv2k.png");

	shader.createShader("assets/vertex.glsl", "assets/fragment.glsl");

	camera.setup(70.0f, 16.0f / 9.0f, 0.1f, 100.0f);
    camera.position.z = -7;
    camera.position.y = 2;

	view_loc = shader.getUniform("view");
	projection_loc = shader.getUniform("projection");
	model_loc = shader.getUniform("model");
	has_tex_loc = shader.getUniform("has_texture");
}

void update(float delta)
{
	int esc = glfwGetKey(ctx.window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	int w = glfwGetKey(ctx.window, GLFW_KEY_W) == GLFW_PRESS;
	int s = glfwGetKey(ctx.window, GLFW_KEY_S) == GLFW_PRESS;
	int a = glfwGetKey(ctx.window, GLFW_KEY_A) == GLFW_PRESS;
	int d = glfwGetKey(ctx.window, GLFW_KEY_D) == GLFW_PRESS;
	int q = glfwGetKey(ctx.window, GLFW_KEY_Q) == GLFW_PRESS;
	int e = glfwGetKey(ctx.window, GLFW_KEY_E) == GLFW_PRESS;

	if (esc)
	{
		running = 0;
	}
	if (glfwWindowShouldClose(ctx.window))
	{
		running = 0;
	}

	if (w)
	{
		yaw.translateZ(10.0f * delta);
	}

	if (s)
	{
		yaw.translateZ(-10.0f * delta);
	}

	if (a)
	{
		yaw.translateX(10.0f * delta);
	}

	if (d)
	{
		yaw.translateX(-10.0f * delta);
	}

	if (q)
	{
		yaw.rotation.y -= 80.0f * delta;
	}

	if (e)
	{
		yaw.rotation.y += 80.0f * delta;
	}

    //loaded.rotation.y = M_PI / 2.0f;
    loaded.rotation.y -= 24.0f * delta;
    
    loaded.translateZ(2.0f * delta);

	//camera.rotation.y += sin(0.6f * delta);
	//camera.rotation.x += cos(0.6f * delta);

	//yaw.rotation.y += 60 * Mouse::x;
	//camera.rotation.x += 60 * Mouse::y;

	if (camera.rotation.x >= 89.0f)
	{
		camera.rotation.x = 89.0f;
	}

	if (camera.rotation.x < -89.0f)
	{
		camera.rotation.x = -89.0f;
	}

    camera.lookAt(test);

    Mouse::update();
	//yaw.update();
    camera.update();
	loaded.update();
    test.update();
}

void draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crate.getId());
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &loaded.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 1);
	loaded.draw();
	shader.detach();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, crate.getId());
	shader.attach();
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &test.getMatrix()[0][0]);
	glUniform1i(has_tex_loc, 1);
	test.draw();
	shader.detach();
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
