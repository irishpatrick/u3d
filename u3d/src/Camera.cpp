#include "Camera.hpp"
#include <GL/glew.h>

namespace u3d
{
    void Camera::init(uint32_t program)
    {
        projection = glm::perspective(glm::radians(70.0f), 16.0f/9.0f, 0.1f, 100.0f);
        view = glm::lookAt(glm::vec3(3,3,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
        
        uint32_t projection_uniform = glGetUniformLocation(program, "projection");
        glUniformMatrix4fv(projection_uniform, 1, false, (float*)&projection[0]);
    
        uint32_t view_uniform = glGetUniformLocation(program, "view");
        glUniformMatrix4fv(view_uniform, 1, false, (float*)&view[0]);
    }
} // u3d
