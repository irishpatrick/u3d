#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "Util.hpp"

Camera::Camera() : Object3D()
{
	projection = glm::mat4(1.0f);
	target = glm::vec3(0.0f);
}

Camera::~Camera()
{

}

void Camera::setup(float fov, float aspect, float near, float far)
{
	projection = glm::perspective(glm::radians(fov), aspect, near, far);
	up = Util::jhat();
}

void Camera::lookAt(Object3D& obj)
{
	target = obj.getRealPos();
	direction = glm::normalize(position - target);
	right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);
}

void Camera::lookAt(glm::vec3& v)
{
    target = v;
}

void Camera::update()
{
    printf("wrong\n");
	matrix = glm::lookAt(position, target, up);
}

void Camera::update(Object3D& parent)
{
    printf("update\n");
	matrix = parent.getMatrix() * glm::lookAt(position, getRealPos() + target, up);
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projection;
}
