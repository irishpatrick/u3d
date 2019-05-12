#pragma once

#include <string>
#include "Mesh.hpp"

#include <assimp/Importer.hpp>

class Assets
{
public:
	Mesh loadMesh(const std::string&);
	Scene loadScene(const std::string&);
};