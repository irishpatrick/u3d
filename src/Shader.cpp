#include "Shader.hpp"
#include <fstream>
#include <streambuf>
#include <vector>
#include <cstdio>

Shader::Shader()
{
	pid = 0;
}

Shader::~Shader()
{

}

int Shader::createShader(const std::string& vs_fn, const std::string& fs_fn)
{
	GLuint vsid = compileShader(vs_fn, GL_VERTEX_SHADER);
	GLuint fsid = compileShader(fs_fn, GL_FRAGMENT_SHADER);
	
	pid = glCreateProgram();
	glAttachShader(pid, vsid);
	glAttachShader(pid, fsid);
	glLinkProgram(pid);

	int result;
	int infologlen;

	glGetProgramiv(pid, GL_LINK_STATUS, &result);
	glGetProgramiv(pid, GL_INFO_LOG_LENGTH, &infologlen);
	if (infologlen > 0)
	{
		std::vector<char> err_msg(infologlen + 1);
		glGetProgramInfoLog(pid, infologlen, NULL, &err_msg[0]);
		printf("%s\n", &err_msg[0]);
	}

	return 0;
}

GLuint Shader::compileShader(const std::string& fn, GLuint type)
{
	GLuint id = glCreateShader(type);
	std::ifstream in(fn);
	std::string src((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	char const* src_p = src.c_str();

	glShaderSource(id, 1, &src_p, NULL);
	glCompileShader(id);

	int result;
	int infologlen;

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infologlen);
	if (infologlen > 0)
	{
		std::vector<char> err_msg(infologlen + 1);
		glGetShaderInfoLog(id, infologlen, NULL, &err_msg[0]);
		printf("%s\n", &err_msg[0]);
	}

	return id;
}

void Shader::attach()
{
	glUseProgram(pid);
}

void Shader::detach()
{
	glUseProgram(0);
}

GLuint Shader::getUniform(const std::string& name)
{
	glUseProgram(pid);
	GLuint loc = glGetUniformLocation(pid, name.c_str());
	printf("location of %s = %u\n", name.c_str(), loc);
	glUseProgram(0);
	return loc;
}