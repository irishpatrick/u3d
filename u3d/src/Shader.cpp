#include "Shader.hpp"
#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>

namespace u3d
{    
    void Shader::compile(const std::string& vertexFile, const std::string& fragmentFile)
    {
        FILE* fp;

        fp = fopen(vertexFile.c_str(), "rb");
        fseek(fp, 0L, SEEK_END);
        size_t size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        char* buffer = (char*)malloc(size);
        fread(buffer, 1, size, fp);

        vsid = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vsid, size, &buffer, NULL);
        glCompileShader(vsid);
    }
} // u3d