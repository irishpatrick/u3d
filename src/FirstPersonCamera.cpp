#include "FirstPersonCamera.hpp"

FirstPersonCamera::FirstPersonCamera()
{
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	direction = glm::vec3(0.0f, 0.0f, -1.0f);
}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::update()
{
	Object3D::update();
	matrix = glm::lookAt(position, position + direction, up);
	//matrix = glm::lookAt(position, glm::vec3(0, 0, 0), up);
}
