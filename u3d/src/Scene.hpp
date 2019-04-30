#pragma once

#include <string>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <vector>
#include "Mesh.hpp"

namespace u3d
{
    class Scene
    {
    public:
        Scene() {};
        ~Scene() {};

        std::vector<Mesh> load(const std::string&);

    private:
        const aiScene *scene;
    };
}