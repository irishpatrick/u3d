#include "Material.hpp"

Material::Material()
{
	type = -1;
	shading = -1;
	shader = nullptr;
    texture = nullptr;
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

void Material::use()
{
    shader->attach();

    if (type == MAT_TEXTURE)
    {

    }
    else if (type == MAT_COLOR)
    {

    }

    shader->detach();
}
