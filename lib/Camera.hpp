#pragma once

#include "Object3D.hpp"
#include <glm/glm.hpp>

class Camera : public Object3D
{
public:
	Camera();
	~Camera();

	void setup(float, float, float, float);
	void lookAt(Object3D&);
    void lookAt(glm::vec3&);
    void update() override;
	glm::mat4 getProjectionMatrix();

	glm::vec3 target;

protected:
	glm::mat4 projection;
    glm::vec3 front;
    glm::vec3 right;
};
