#pragma once

#include "Shader.hpp"
#include "gl_includes.hpp"
#include <string>

class UniversalShader : public Shader
{
public:
    UniversalShader();
    ~UniversalShader();

    void create(const std::string&, const std::string&);
    void fill(Mesh&, Camera&);
private:
    GLuint projection_loc;
    GLuint view_loc;
    GLuint model_loc;
    GLuint color_src_loc;
};