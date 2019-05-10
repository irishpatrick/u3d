#pragma once

#include <gl/glew.h>
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

protected:
	GLuint vbo;
	GLuint vno;
	GLuint vto;
	GLuint ibo;
	GLuint vao;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<uint32_t> indices;
	int triangles;
};