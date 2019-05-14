#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_texcoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec2 texcoord;

void main()
{
	mat4 mvp = projection * view * model;
	gl_Position = mvp * vec4(in_position, 1);

	texcoord = in_texcoord;
}