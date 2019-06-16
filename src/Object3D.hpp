#pragma once

#include "gl_includes.hpp"
#include <vector>

class Object3D
{
public:
	Object3D();
	~Object3D();

	virtual void update();

	glm::mat4 getMatrix();
	glm::mat4 accumulateMatrices();
    void updateQuaternion();
    void decompose();

	void addChild(Object3D&);
	void setParent(Object3D&);

	glm::vec3 getRealPos();

	void translateX(float);
	void translateZ(float);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

    glm::vec3 world_position;
    glm::vec3 world_rotation;
    glm::vec3 world_scale;
    glm::quat world_quaternion;

protected: 
	glm::mat4 matrix;
	std::vector<Object3D*> children;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 direction;
	Object3D* parent;
    glm::quat quaternion;
};
