#include "Triangle.hpp"
#include <cstdio>
#include <cstdlib>

static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

Triangle::Triangle() : Mesh()
{

}

Triangle::~Triangle()
{

}

void Triangle::init()
{
	int i;
	for (i = 0; i < 1 * 3 * 3; ++i)
	{
		vertices.push_back(g_vertex_buffer_data[i]);
		triangles = 1;
	}
}