#include "Material.hpp"

Material::Material()
{
	color_src = -1;
	shading = -1;
	shader = nullptr;
    texture = nullptr;
    color = glm::vec3(0, 0, 0);
}

Material::~Material()
{

}

void Material::create(int t, int s)
{
	color_src = t;
	shading = s;
}

void Material::setShader(Shader& s)
{
    shader = &s;
}

void Material::setTexture(Texture& t)
{
    texture = &t;
}

void Material::setColor(uint8_t r, uint8_t g, uint8_t b)
{
    color.x = r;
    color.y = g;
    color.z = b;
    color = glm::normalize(color);
}

int Material::getColorSrc()
{
    return color_src;
}

int Material::getShadingType()
{
    return shading;
}
