#include "Object3D.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "Util.hpp"

Object3D::Object3D()
{
	matrix = glm::mat4(1.0f);
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
	right = glm::vec3();
	up = Util::jhat();
	direction = glm::vec3();

}

Object3D::~Object3D()
{

}

void Object3D::update()
{
	direction.x = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y) - (float)M_PI / 2.0f);
	direction.y = sin(glm::radians(rotation.x));
	direction.z = cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y) - (float)M_PI / 2.0f);
	direction = glm::normalize(direction);

	glm::mat4 t(1.0f);
	if (parent != nullptr)
	{
		t = glm::translate(glm::mat4(1.0f), position + (parent->position - offset));
	}
	else
	{
		t = glm::translate(glm::mat4(1.0f), position);
	}
	
	glm::mat4 rx = glm::rotate(rotation.x, Util::ihat());
	glm::mat4 ry = glm::rotate(rotation.y, Util::jhat());
	glm::mat4 rz = glm::rotate(rotation.z, Util::khat());
	glm::mat4 s = glm::scale(scale);

	matrix = t * rx * ry * rz * s;
}

glm::mat4 Object3D::getMatrix()
{
	return matrix;
}

void Object3D::addChild(Object3D& obj)
{
	children.push_back(&obj);
}

void Object3D::setParent(Object3D& obj)
{
	parent = &obj;
	offset = parent->position;
}

void Object3D::translateX(float amount)
{
	right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);

	position += amount * right;
}

void Object3D::translateZ(float amount)
{
	position += amount * direction;
}

