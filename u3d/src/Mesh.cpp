#include "Mesh.hpp"
#include <GL/glew.h>

namespace u3d
{
    void Mesh::create(int program)
    {
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
    }
} // u3d
