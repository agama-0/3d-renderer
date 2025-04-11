#ifndef Shader_HPP
#define Shader_HPP
#include <glad/glad.h>
#include <vector>
namespace Agama {

class Shader
{
    private:
        GLuint shader;
    public:
    Shader(const char* path,GLenum shader_type);
    ~Shader();
    GLuint getShader();
};

class ShaderProgram
{
    private:
        GLuint program;
    public:
    ShaderProgram(const char* vs_path, const char* fs_path);
    ~ShaderProgram();
    void bind();
    void unbind();
};

} // namespace Agama
#endif // Shader_HPP
