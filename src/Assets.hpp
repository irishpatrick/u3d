#pragma once

#include <string>
#include "Mesh.hpp"
#include "Scene.hpp"

class Assets
{
public:
	static Mesh loadMesh(const std::string&);
	static Scene loadScene(const std::string&);
};