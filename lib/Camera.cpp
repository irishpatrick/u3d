#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include "Util.hpp"

Camera::Camera() : Object3D()
{
	projection = glm::mat4(1.0f);
	target = glm::vec3(0.0f);
    front = glm::vec3(0, 0, -1);
    right = glm::vec3(-1, 0, 0);
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
    if (parent == nullptr)
    {
        direction = glm::normalize(position - target);
    }
    else
    {
        direction = glm::normalize(world_position - target);
    }
    right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);
}

void Camera::lookAt(glm::vec3& v)
{
    target = v;
}

void Camera::update()
{
    //std::cout << rotation.x << ',' << rotation.y << ',' << rotation.z << std::endl;
    front.z = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    front.y = sin(glm::radians(rotation.x));
    front.x = cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
    front = glm::normalize(front);

    right = glm::normalize(glm::cross(up, front));

    //std::cout << Util::vector_to_str(front) << std::endl;

    if (parent != nullptr)
    {
        matrix = parent->accumulateMatrices() * glm::lookAt(parent->world_position + position, parent->world_position + position + front, up);
    }
    else
    {
        matrix = glm::lookAt(position, target, up);
    }

    //decompose();

    Util::print_vec3(position);
    std::cout << "\n";
    Util::print_vec3(world_position);

    for (auto& e : children)
    {
        e->update();
    }
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projection;
}
