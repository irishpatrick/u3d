#include "UniversalShader.hpp"

UniversalShader::UniversalShader()
{
}

UniversalShader::~UniversalShader()
{
}

void UniversalShader::create(const std::string& vfn, const std::string& ffn)
{
    Shader::createShader(vfn, ffn);
    projection_loc = Shader::getUniform("projection");
    view_loc = Shader::getUniform("view");
    model_loc = Shader::getUniform("model");
    color_src_loc = Shader::getUniform("color_src");
}

void UniversalShader::fill(Mesh& mesh, Camera& camera)
{
    Material& mat = mesh.getMaterial();
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &camera.getProjectionMatrix()[0][0]);
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, &camera.getMatrix()[0][0]);
    glUniformMatrix4fv(model_loc, 1, GL_FALSE, &mesh.getMatrix()[0][0]);
    glUniform1i(color_src_loc, mat.getColorSrc());
}
