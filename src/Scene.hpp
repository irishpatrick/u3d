#pragma once

#include <vector>
#include "Mesh.hpp"

class Scene
{
public:
	Scene();
	~Scene();

	void addMesh(Mesh&);
	void draw();
	const std::vector<Mesh*> getMeshes();

private:
	std::vector<Mesh*> meshes;
};