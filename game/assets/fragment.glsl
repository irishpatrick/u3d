#version 330 core

#define SRC_CLR 0
#define SRC_TEX 1

in vec2 texcoord;
out vec3 color;

uniform sampler2D texsampler;
uniform int color_src;

void main()
{
	if (color_src == SRC_TEX)
	{
		color = texture(texsampler, texcoord).rgb;
	}
	else if (color_src == SRC_CLR)
	{
		color = vec3(1, 0, 0);
	}
    else
    {
        color = vec3(1, 0, 1);
    }
}