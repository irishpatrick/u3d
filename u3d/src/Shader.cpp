#include "Shader.hpp"
#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>

namespace u3d
{    
    uint32_t Shader::getId()
    {
        return pid;
    }

    int compile_file(const std::string& fn, GLenum type)
    {
        FILE* fp;

        fp = fopen(fn.c_str(), "rb");
        fseek(fp, 0L, SEEK_END);
        size_t size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        char* buffer = (char*)malloc(size);
        fread(buffer, 1, size, fp);
        fclose(fp);

        uint32_t id = glCreateShader(type);
        if (!id)
        {
            printf("error creating shader\n");
            return -1;
        }
        glShaderSource(id, 1, &buffer, NULL);
        glCompileShader(id);

        int status;
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            int loglen;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &loglen);
            char* logbuf = (char*)malloc(loglen+1);
            glGetShaderInfoLog(id, loglen, NULL, logbuf);

            printf("compilation failed: %s\n", logbuf);
            return -1;
        }

        return id;
    }

    void Shader::compile(const std::string& vertexFile, const std::string& fragmentFile)
    {
        uint32_t vsid = compile_file(vertexFile, GL_VERTEX_SHADER);
        uint32_t fsid = compile_file(fragmentFile, GL_FRAGMENT_SHADER);
        if (vsid < 0 || fsid < 0)
        {
            printf("serious issues\n");
        }
        pid = glCreateProgram();
        glAttachShader(pid, vsid);
        glAttachShader(pid, fsid);
        glLinkProgram(pid);

        int status;
        glGetProgramiv(pid, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            int loglen;
            glGetProgramiv(pid, GL_INFO_LOG_LENGTH, &loglen);
            char* logbuf = (char*)malloc(loglen+1);
            glGetProgramInfoLog(pid, loglen, NULL, logbuf);

            printf("linking failed: %s\n", logbuf);
        }

        glDeleteShader(vsid);
        glDeleteShader(fsid);

        glBindFragDataLocation(pid, 0, std::string("outputcolor").c_str());
    }
} // u3d