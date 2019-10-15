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
        direction = glm::normalize(target - position);
    }
    else
    {
        direction = glm::normalize(target - world_position);
    }
    right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);
    target = position + direction;

    std::cout << "OLD ";
    Util::print_vec3(position);
    //localMatrix = glm::lookAt(position, target, up);
    //decompose();
    std::cout << "NEW ";
    Util::print_vec3(position);
}

void Camera::lookAt(glm::vec3& v)
{
    target = v;
}

void Camera::update()
{
    //std::cout << rotation.x << ',' << rotation.y << ',' << rotation.z << std::endl;
    front.x = cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
    front.y = sin(glm::radians(rotation.x));
    front.z = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    front = glm::normalize(front);

    right = glm::normalize(glm::cross(up, front));
    //up = glm::cross(front, right);

    /*if (parent != nullptr)
    {
        matrix = parent->accumulateMatrices() * glm::lookAt(parent->world_position + position, parent->world_position + position + front, up);
    }
    else
    {
        matrix = glm::lookAt(position, position + front, up);
    }*/

    //matrix = glm::lookAt(position, position + front, up);

    matrix = glm::lookAt(position, target, up);
}

void Camera::translateX(float amount)
{
    position += amount * right;
}

void Camera::translateZ(float amount)
{
    glm::vec3 front_flat = front;
    front_flat.y = 0;
    front_flat = glm::normalize(front_flat);
    position += amount * front_flat;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projection;
}
