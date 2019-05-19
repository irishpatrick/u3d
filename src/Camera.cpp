#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "Util.hpp"

Camera::Camera() : Object3D()
{
	projection = glm::mat4(1.0f);
}

Camera::~Camera()
{

}

void Camera::setup(float fov, float aspect, float near, float far)
{
	projection = glm::perspective(glm::radians(fov), aspect, near, far);
}

void Camera::lookAt(Object3D* obj)
{
	target = obj->position;
	matrix = glm::lookAt(position, target, Util::jhat());
}

void Camera::update()
{
	matrix = glm::lookAt(position, target, Util::jhat());
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projection;
}