#include "Texture.hpp"
#include <IL/il.h>
#include <cstdint>
#include <cstdio>

Texture::Texture()
{
	id = 0;
}

Texture::~Texture()
{

}

void Texture::load(const std::string& fn)
{
	printf("load texture %s\n", fn.c_str());
	ILuint il_id;
	ilGenImages(1, &il_id);
	ilBindImage(il_id);
	ilLoadImage(fn.c_str());
	uint32_t width = ilGetInteger(IL_IMAGE_WIDTH);
	uint32_t height = ilGetInteger(IL_IMAGE_HEIGHT);
	uint8_t* pixmap = new uint8_t[width * height * 3];
	ilCopyPixels(0, 0, 0, width, height, 1, IL_RGB, IL_UNSIGNED_BYTE, pixmap);
	ilBindImage(0);
	ilDeleteImage(il_id);

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixmap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	delete[] pixmap;
}

GLuint Texture::getId()
{
	return id;
}