#include "FirstPersonCamera.hpp"

FirstPersonCamera::FirstPersonCamera()
{
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	direction = glm::vec3(0.0f, 0.0f, -1.0f);
}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::setup(float fov, float aspect, float near, float far)
{
	camera.setup(fov, aspect, near, far);
	addChild(camera);
}

void FirstPersonCamera::update()
{
	camera.rotation.x = rotation.x;
	rotation.x = 0;
	rotation.z = 0;
	Object3D::update();	
}

glm::mat4 FirstPersonCamera::getProjectionMatrix()
{
	return camera.getProjectionMatrix();
}
