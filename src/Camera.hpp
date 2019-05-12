#pragma once

#include "Object3D.hpp"
#include <glm/glm.hpp>

class Camera : public Object3D
{
public:
	Camera();
	~Camera();

	void setup(float, float, float, float);
	void lookAt(Object3D*);
	void update();
	glm::mat4 getProjectionMatrix();

	glm::vec3 target;

private:
	glm::mat4 projection;
};