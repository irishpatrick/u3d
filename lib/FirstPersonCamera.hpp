#pragma once

#include "Object3D.hpp"
#include "Camera.hpp"

class FirstPersonCamera : public Object3D
{
public:
    FirstPersonCamera();
    ~FirstPersonCamera();

    void setup(float, float, float, float);
    void lookAt(Object3D&);
    void update();

    void pitch(float);
    void yaw(float);
    void pitchRate(float);
    void yawRate(float);

    glm::mat4 getProjectionMatrix();
    glm::mat4 getMatrix();

    Camera camera;

private:
};
