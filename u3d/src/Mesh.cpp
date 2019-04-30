#include "Mesh.hpp"
#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

namespace u3d
{
    // process faces
    void Mesh::load(const aiMesh *mesh)
    {
        uint32_t i, j;
        uint32_t tmp[3];
        for (i = 0; i < mesh->mNumFaces; ++i)
        {
            const aiFace *cur_face = &mesh->mFaces[i];
            memcpy(&tmp, cur_face, sizeof(uint32_t));
            for (j = 0; j < 3; ++j)
            {
                m_faces.push_back(tmp[i]);
            }
        }
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mesh->mNumFaces * 3, &m_faces[0], GL_STATIC_DRAW);

        // vertices
        if (mesh->HasPositions())
        {
            glGenBuffers(1, &vbo);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * mesh->mNumVertices, mesh->mVertices, GL_STATIC_DRAW);
        }

        if (mesh->HasNormals())
        {
            glGenBuffers(1, &nbo);
            glBindBuffer(GL_ARRAY_BUFFER, nbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * mesh->mNumVertices, mesh->mNormals, GL_STATIC_DRAW);
        }

        if (mesh->HasTextureCoords(0))
        {
            glGenBuffers(1, &tbo);
            glBindBuffer(GL_ARRAY_BUFFER, tbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * mesh->mNumVertices, mesh->mTextureCoords, GL_STATIC_DRAW);
        }
    }

    void Mesh::setProgram(uint32_t id)
    {
        
    }

    // normals

    // textures
} // u3d
