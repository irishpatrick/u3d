#include "TestMesh.hpp"
#include "gl_includes.hpp"

GLfloat vertex_data[] = {
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f,-1.0f,
	-1.0f, 0.0f, -1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, -1.0f
};

GLuint index_data[] = {
	0, 1, 2,
	3, 4, 5
};



TestMesh::TestMesh() : Mesh()
{

}

TestMesh::~TestMesh()
{

}

void TestMesh::init()
{
	unsigned int i;

	for (i = 0; i < 18; ++i)
	{
		vertices.push_back(vertex_data[i]);
	}

	for (i = 0; i < 6; ++i)
	{
		indices.push_back(index_data[i]);
	}

	triangles = 2;
}