#include "FirstPersonCamera.hpp"
#include "Util.hpp"

FirstPersonCamera::FirstPersonCamera()
{
	
}

FirstPersonCamera::~FirstPersonCamera()
{

}

void FirstPersonCamera::setup(float fov, float aspect, float near, float far)
{
    camera.setup(fov, aspect, near, far);
    addChild(camera);
}

void FirstPersonCamera::update()
{
    camera.rotation.x = rotation.x;
    //rotation.x = 0;

    glm::vec3 dir;
    dir.x = cos(glm::radians(rotation.y)) * cos(glm::radians(camera.rotation.x));
    dir.y = sin(glm::radians(camera.rotation.x));
    dir.z = sin(glm::radians(rotation.y)) * cos(glm::radians(camera.rotation.x));
    
    glm::vec3 tmp = position + dir;
    camera.lookAt(tmp);

    glm::mat4 t(1.0f);
	glm::mat4 rx(1.0f), ry(1.0f), rz(1.0f);

	t = glm::translate(glm::mat4(1.0f), position);
	rx = glm::rotate(0.0f, Util::ihat());
	ry = glm::rotate(rotation.y, Util::jhat());
	rz = glm::rotate(rotation.z, Util::khat());
	
	glm::mat4 s = glm::scale(scale);

	matrix = t * rx * ry * rz * s;

	for (auto& e : children)
	{
		e->update(*this);
	}
}

glm::mat4 FirstPersonCamera::getMatrix()
{
    return matrix;
}

glm::mat4 FirstPersonCamera::getViewMatrix()
{
    return camera.accumulateMatrices();
}

glm::mat4 FirstPersonCamera::getProjectionMatrix()
{
    return camera.getProjectionMatrix();	
}
