#include "Texture.hpp"
#include <cstdint>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Texture::Texture()
{
	id = 0;
    ready = false;
}

Texture::~Texture()
{

}

void Texture::load(const std::string& fn)
{
    ready = false;
	printf("load texture %s\n", fn.c_str());

	SDL_Surface* surface = IMG_Load(fn.c_str());
	if (surface == nullptr)
	{
		printf("texture error: %s\n", IMG_GetError());
		return;
	}

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	int mode = GL_RGB;

	if (surface->format->BytesPerPixel == 4)
	{
		mode = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

    ready = true;
}

GLuint Texture::getId()
{
	return id;
}
