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
}

Object3D::~Object3D()
{

}

void Object3D::update()
{
	glm::mat4 t = glm::translate(glm::mat4(1.0f), position);
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