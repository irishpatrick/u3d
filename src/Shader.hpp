#pragma once

#include "gl_includes.hpp"
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	int createShader(const std::string&, const std::string&);
	GLuint compileShader(const std::string&, GLuint);
	void attach();
	void detach();
	GLuint getUniform(const std::string&);

    void locateUniforms();
    void fillUniforms();

    void setViewMat(glm::mat4&);
    void setProjMat(glm::mat4&);
    void setModelMat(glm::mat4&);

	GLuint pid;

private:
    glm::mat4* view;
    glm::mat4* proj;
    glm::mat4* model;
    GLuint proj_loc;
    GLuint view_loc;
    GLuint model_loc;
};
