#include "Scene.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::addMesh(Mesh& mesh)
{
	meshes.push_back(&mesh);
}

void Scene::render(Camera& camera)
{
	for (auto& e : meshes)
	{
		e->draw();
	}
}

const std::vector<Mesh*> Scene::getMeshes()
{
	return meshes;
}


