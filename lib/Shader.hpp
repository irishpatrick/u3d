#pragma once

#include "gl_includes.hpp"
#include <string>
#include <map>

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

    template <typename T>
    void setUniform(const std::string&, T&);

	GLuint pid;

private:
	std::map<std::string, GLuint> uniform_cache;
};

#include "Shader.inl"
