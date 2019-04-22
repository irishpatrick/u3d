#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace u3d
{
    class Mesh
    {
    public:
        Mesh() {}
        ~Mesh() {}

        void create(int);
        void update();
        void draw();

        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        uint32_t vbo;
        uint32_t vao;
        uint32_t vattrib;
        uint32_t tattrib;
        uint32_t nattrib;
        int32_t faces;
        std::vector<float> buffer;
        glm::mat4 matrix;
        uint32_t pid;
        uint32_t uniform;
    private:
    };
} // u3d
