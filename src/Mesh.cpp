#include "Mesh.hpp"
#include <cstdio>
#include <cstdlib>

Mesh::Mesh() : Object3D()
{
	vao = 0;
	vbo = 0;
	vno = 0;
	vto = 0;
	ibo = 0;
	triangles = 0;
}

Mesh::~Mesh()
{

}

void Mesh::init()
{

}

void Mesh::generate()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	if (vertices.size() > 0)
	{
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	}
	
	if (texcoords.size() > 0)
	{
		glGenBuffers(1, &vto);
		glBindBuffer(GL_ARRAY_BUFFER, vto);
		glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(GLfloat), &texcoords[0], GL_STATIC_DRAW);
	}
	
	if (normals.size() > 0)
	{
		glGenBuffers(1, &vno);
		glBindBuffer(GL_ARRAY_BUFFER, vno);
		glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(GLfloat), &normals[0], GL_STATIC_DRAW);
	}	
}

void Mesh::draw()
{
	//printf("base class\n");
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glDrawArrays(GL_TRIANGLES, 0, triangles * 3);
	glDisableVertexAttribArray(0);
}