#pragma once

#include <gl/glew.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	void load(const std::string&);
	GLuint getId();

private:
	GLuint id;
};