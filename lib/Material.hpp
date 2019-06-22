#pragma once

#include <cstdint>
#include "gl_includes.hpp"
#include "Texture.hpp"
#include "Shader.hpp"

#define MAT_TEXTURE 0
#define MAT_COLOR 1

#define MAT_FLAT 2
#define MAT_TOON 3
#define MAT_LAMBERT 4
#define MAT_PHONG 5

class Material
{
public:
	Material();
	~Material();

	void create(int, int);
    void setShader(Shader&);
    void setTexture(Texture&);
    void setColor(uint8_t, uint8_t, uint8_t);
    int getColorSrc();
    int getShadingType();

private:
	int color_src;
	int shading;
    Shader* shader;
    Texture* texture;
    glm::vec3 color;
};
