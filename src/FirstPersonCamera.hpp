#pragma once

#include "Object3D.hpp"
#include "Camera.hpp"

class FirstPersonCamera : public Object3D
{
public:
	FirstPersonCamera();
	~FirstPersonCamera();
	void setup(float, float, float, float);
	void update();
	glm::mat4 getProjectionMatrix();

private:
    Object3D yaw;
	Camera camera;
};
