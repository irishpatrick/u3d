#pragma once

#include "Camera.hpp"

class FirstPersonCamera : public Camera
{
public:
	FirstPersonCamera();
	~FirstPersonCamera();
	void update();

private:
    Object3D yaw;
};
