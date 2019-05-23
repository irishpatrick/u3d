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
	parent = nullptr;
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

    updateQuaternion();

    glm::mat4 t = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 r = glm::toMat4(quaternion);
	glm::mat4 s = glm::scale(scale);

	matrix = t * r * s;

	for (auto& e : children)
	{
		e->update(*this);
	}

    decompose();
}

void Object3D::update(Object3D& parent)
{
	direction.x = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y) - (float)M_PI / 2.0f);
	direction.y = sin(glm::radians(rotation.x));
	direction.z = cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y) - (float)M_PI / 2.0f);
	direction = glm::normalize(direction);

    glm::mat4 t = glm::translate(glm::mat4(1.0f), position);

    updateQuaternion();
    glm::mat4 r = glm::toMat4(quaternion);

	glm::mat4 s = glm::scale(scale);

	matrix = parent.getMatrix() * t * r * s;
    
    decompose();

	for (auto& e : children)
	{
		e->update(*this);
	}
}

void Object3D::decompose()
{

    glm::vec3 skew;
    glm::vec4 persp;
    glm::decompose(matrix, world_scale, world_quaternion, world_position, skew, persp);
    world_rotation = glm::eulerAngles(world_quaternion);
    world_rotation = Util::to_degrees(world_rotation);
}

glm::mat4 Object3D::getMatrix()
{
	return matrix;
}

glm::mat4 Object3D::accumulateMatrices()
{
	if (parent != nullptr)
	{
		return parent->accumulateMatrices()* matrix;
	}
	return matrix;
}

void Object3D::addChild(Object3D& obj)
{
	obj.setParent(*this);
	children.push_back(&obj);
}

void Object3D::setParent(Object3D& obj)
{
	parent = &obj;
	position = position - obj.position;
	rotation = rotation - obj.rotation;
}

glm::vec3 Object3D::getRealPos()
{
	if (parent != nullptr)
	{
		return glm::vec3(parent->accumulateMatrices() * glm::vec4(position, 1));
	}
	return position;
}

/*void Object3D::translateX(float amount)
{
	right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);

	position += amount * right;
}

void Object3D::translateZ(float amount)
{
	position += amount * direction;
}*/

void Object3D::updateQuaternion()
{
    quaternion = glm::quat(Util::to_radians(rotation));
}


void Object3D::translateX(float amount)
{
    updateQuaternion();
    glm::vec3 axis(1.0f, 0, 0);
    glm::vec4 dir = glm::vec4(axis, 1.0f) * glm::toMat4(quaternion);
    glm::vec3 dir3 = glm::vec3(dir.x, dir.y, dir.z);
    position += amount * dir3;
}


void Object3D::translateZ(float amount)
{
    updateQuaternion();
    glm::vec3 axis(0, 0, 1.0f);
    glm::vec4 dir = glm::vec4(axis, 1.0f) * glm::toMat4(quaternion);
    glm::vec3 dir3 = glm::vec3(dir.x, dir.y, dir.z);

    printf("%s -> %s\n", Util::vector_to_str(axis).c_str(), Util::vector_to_str(dir3).c_str());

    position += amount * dir3;
}

