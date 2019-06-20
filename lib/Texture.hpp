#pragma once

#include "gl_includes.hpp"
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	void load(const std::string&);
	GLuint getId();

    bool ready;

private:
	GLuint id;
};
