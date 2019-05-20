#include "Texture.hpp"
#include <cstdint>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
	/*ILuint il_id;
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

	delete[] pixmap;*/

	/*id = SOIL_load_OGL_texture(fn.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (id <= 0)
	{
		printf("possible error %s\n", SOIL_last_result());
	}*/

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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

GLuint Texture::getId()
{
	return id;
}
