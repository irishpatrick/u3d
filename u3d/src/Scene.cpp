#include "Scene.hpp"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

namespace u3d
{
    std::vector<Mesh> Scene::load(const std::string& fn)
    {
        std::vector<Mesh> out;
        Assimp::Importer importer;
        scene = importer.ReadFile(fn, 0);

        uint32_t i;
        for (i=0; i < scene->mNumMeshes; ++i)
        {
            const aiMesh* mesh = scene->mMeshes[i];
            Mesh m;
            m.load(mesh);
            out.push_back(m);
        }

        return out;
    }
}