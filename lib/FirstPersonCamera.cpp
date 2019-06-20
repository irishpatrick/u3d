#include "FirstPersonCamera.hpp"
#include "Util.hpp"

FirstPersonCamera::FirstPersonCamera()
{
    addChild(camera);
}

FirstPersonCamera::~FirstPersonCamera()
{

}

void FirstPersonCamera::setup(float fov, float aspect, float near, float far)
{
    camera.setup(fov, aspect, near, far);
}

void FirstPersonCamera::lookAt(Object3D& obj)
{
    camera.lookAt(obj);
    rotation.y = camera.rotation.y;
    camera.rotation.y = 0;
    camera.updateQuaternion();
    updateQuaternion();
}

void FirstPersonCamera::update()
{
    Object3D::update();
}

glm::mat4 FirstPersonCamera::getProjectionMatrix()
{
    return camera.getProjectionMatrix();
}

glm::mat4 FirstPersonCamera::getMatrix()
{
    return camera.accumulateMatrices();
}
