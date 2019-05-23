#include "FirstPersonCamera.hpp"
#include "Util.hpp"

FirstPersonCamera::FirstPersonCamera()
{
	
}

FirstPersonCamera::~FirstPersonCamera()
{

}

void FirstPersonCamera::setup(float fov, float aspect, float near, float far)
{

}

void FirstPersonCamera::update()
{

}

glm::mat4 FirstPersonCamera::getMatrix()
{
	return glm::mat4(1.0f);
}

glm::mat4 FirstPersonCamera::getViewMatrix()
{
	return glm::mat4(1.0f);
}

glm::mat4 FirstPersonCamera::getProjectionMatrix()
{
	return glm::mat4(1.0f);
}
