#include "Mesh.hpp"
#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
namespace u3d
{
    void Mesh::create(int program)
    {
        pid = program;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, buffer.size()*4, &buffer[0], GL_STATIC_DRAW);

        vattrib = glGetAttribLocation(program, "vert");
        glEnableVertexAttribArray(vattrib);
        glVertexAttribPointer(vattrib, 3, GL_FLOAT, false, 8*4, (void*)(0));

        tattrib = glGetAttribLocation(program, "tex");
        glEnableVertexAttribArray(tattrib);
        glVertexAttribPointer(tattrib, 2, GL_FLOAT, false, 8*4, (void*)(3*4));

        nattrib = glGetAttribLocation(program, "norm");
        glEnableVertexAttribArray(nattrib);
        glVertexAttribPointer(nattrib, 3, GL_FLOAT, false, 8*4, (void*)(5*4));

        uniform = glGetUniformLocation(pid, std::string("model").c_str());
    }

    void Mesh::update()
    {
        glm::vec3 ihat = glm::vec3(1, 0, 0);
        glm::vec3 jhat = glm::vec3(0, 1, 0);
        glm::vec3 khat = glm::vec3(0, 0, 1);
        matrix = glm::mat4(1.0f);
        glm::mat4 t = glm::translate(position);
        glm::mat4 rx = glm::rotate(rotation.x, ihat);
        glm::mat4 ry = glm::rotate(rotation.y, jhat);
        glm::mat4 rz = glm::rotate(rotation.z, khat);
        glm::mat4 s = glm::scale(scale);

        matrix = t * rx * ry * rz * s;
        
    }

    void Mesh::draw()
    {
        glUseProgram(pid);
        glUniformMatrix4fv(uniform, 1, false, (float*)&matrix[0]);

        glBindVertexArray(vao);
        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, texture);
        glDrawArrays(GL_TRIANGLES, 0, faces * 2 * 4);
    }
} // u3d
