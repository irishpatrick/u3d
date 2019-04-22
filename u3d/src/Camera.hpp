#pragma once

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <cstdint>

namespace u3d
{
    class Camera
    {
    public:
        Camera() {}
        ~Camera() {}

        void init(uint32_t);
    private:
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 model;
    }; 
} // u3d
