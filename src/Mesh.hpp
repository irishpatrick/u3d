#pragma once

#include "gl_includes.hpp"
#include <vector>
#include "Object3D.hpp"
#include <cstdint>

class Mesh : public Object3D
{
public:
	Mesh();
	~Mesh();

	void init();
	void generate();
	void draw();

	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<uint32_t> indices;

protected:
	GLuint vbo;
	GLuint tbo;
	GLuint nbo;
	GLuint ibo;
	GLuint vao;
	int triangles;
};