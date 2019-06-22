#pragma once

#include <vector>
#include "Mesh.hpp"
#include "Camera.hpp"

class Scene
{
public:
	Scene();
	~Scene();

	void addMesh(Mesh&);
	void render(Camera&);
	const std::vector<Mesh*> getMeshes();

private:
	std::vector<Mesh*> meshes;
};