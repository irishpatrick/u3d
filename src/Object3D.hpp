#pragma once

#include "gl_includes.hpp"
#include <vector>

class Object3D
{
public:
	Object3D();
	~Object3D();

	void update();
	glm::mat4 getMatrix();

	void addChild(Object3D&);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

protected:
	glm::mat4 matrix;
	std::vector<Object3D*> children;
};