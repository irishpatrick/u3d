#version 330 core

in vec2 texcoord;

out vec3 color;

uniform sampler2D texsampler;
uniform int has_texture;

void main()
{
	if (has_texture > 0)
	{
		color = texture(texsampler, texcoord).rgb;
	}
	else
	{
		color = vec3(1,0,0);
	}
}