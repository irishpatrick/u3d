#pragma once


#include <glm/glm.hpp>

class Object3D
{
public:
	Object3D();
	~Object3D();

	void update();
	glm::mat4 getMatrix();

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

protected:
	glm::mat4 matrix;
};