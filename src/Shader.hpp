#pragma once

#include <gl/glew.h>
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

	GLuint pid;
};