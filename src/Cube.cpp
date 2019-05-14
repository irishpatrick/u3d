#include "Cube.hpp"

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
};

static const GLfloat g_texture_buffer_data[] = {
	0.625f, 0.25f,
	0.375f, 0.5f,
	0.375f, 0.25f,
	0.625f, 0.5f,
	0.375f, 0.75f,
	0.625f, 0.75f,
	0.375f, 1.0f,
	0.375f, 0.5f,
	0.125f, 0.75f,
	0.125f, 0.5f,
	0.875f, 0.5f,
	0.625f, 0.5f,
	0.625f, 0.25f,
	0.625f, 0.75f,
	0.625f, 1.0f,
	0.375f, 0.75f,
	0.875f, 0.75f,

};

Cube::Cube() : Mesh()
{

}

Cube::~Cube()
{

}

void Cube::init()
{
	triangles = 12;

	int i;

	for (i = 0; i < 12 * 3 * 3; ++i)
	{
		vertices.push_back(g_vertex_buffer_data[i]);
	}

	for (i = 0; i < 16 * 2; ++i)
	{
		texcoords.push_back(g_texture_buffer_data[i]);
	}
}