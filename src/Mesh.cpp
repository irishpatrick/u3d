#include "Mesh.hpp"
#include <cstdio>
#include <cstdlib>
//#include <boost/lexical_cast.hpp>

Mesh::Mesh() : Object3D()
{
	vao = 0;
	vbo = 0;
	nbo = 0;
	tbo = 0;
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
		printf("v");
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	}
	
	if (texcoords.size() > 0)
	{
		printf("t");
		glGenBuffers(1, &tbo);
		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(GLfloat), &texcoords[0], GL_STATIC_DRAW);
	}
	
	if (normals.size() > 0)
	{
		printf("n");
		glGenBuffers(1, &nbo);
		glBindBuffer(GL_ARRAY_BUFFER, nbo);
		glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(GLfloat), &normals[0], GL_STATIC_DRAW);
	}

	printf("\n");
}

void Mesh::draw()
{
	glBindVertexArray(vao);

	if (vertices.size() > 0)
	{
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
	}

	if (texcoords.size() > 0)
	{
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glVertexAttribPointer(
			1,
			2,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
	}
	
	if (indices.size() > 0)
	{
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, &indices[0]);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, triangles * 3);
	}

	if (vertices.size() > 0)
	{
		glDisableVertexAttribArray(0);
	}

	if (texcoords.size() > 0)
	{
		glDisableVertexAttribArray(1);
	}

	glBindVertexArray(0);

	/*for (auto& e : children)
	{
		
	}*/
}
