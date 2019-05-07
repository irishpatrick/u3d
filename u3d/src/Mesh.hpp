#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <assimp/mesh.h>

namespace u3d
{
    class Mesh
    {
    public:
        Mesh() {}
        ~Mesh() {}

        void load(const aiMesh *);
        void setProgram(uint32_t);
    private:
        std::vector<uint32_t> m_faces;
        std::vector<uint32_t> m_texcoords;
        uint32_t vbo, nbo, tbo, ibo;
        uint32_t vattrib, nattrib, tattrib;
        uint32_t program;
    };
} // u3d
