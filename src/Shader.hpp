#pragma once

#include "gl_includes.hpp"
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	int createShader(const std::string&, const std::string&);
	GLuint compileShader(const std::string&, GLuint);
	void attach();
	void detach();
	GLuint getUniform(const std::string&);

    void locateUniforms();
    void fillUniforms();

    template <typename T>
    void setUniform(GLuint, T&);

	GLuint pid;
};
