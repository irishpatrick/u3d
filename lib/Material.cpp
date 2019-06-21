#include "Material.hpp"

Material::Material()
{
	type = -1;
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
	type = t;
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

void Material::use()
{
    shader->attach();

    if (type == MAT_TEXTURE)
    {
        if (texture != nullptr)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture->getId());
        }
        else
        {

        }
    }
    else if (type == MAT_COLOR)
    {

    }

    shader->detach();
}
