#include "Material.hpp"

Material::Material()
{
	type = -1;
	shading = -1;
	shader = nullptr;
}

Material::~Material()
{

}

void Material::create(int t, int s)
{
	type = t;
	shading = s;
}

void Material::use()
{

}