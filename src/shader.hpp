#ifndef Shader_HPP
#define Shader_HPP
#include <glad/glad.h>
#include <vector>
#include "alm.hpp"
namespace agama {

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
    void set_bool(const char* key, bool value);
    void set_int(const char* key, int value);
    void set_float(const char* key, float value);
    void set_vec2(const char* key, const alm::vec2& value);
    void set_vec2(const char* key, float x, float y);
    void set_vec3(const char* key, const alm::vec3& value);
    void set_vec3(const char* key, float x, float y, float z);
    void set_vec4(const char* key, const alm::vec4& value);
    void set_vec4(const char* key, float x, float y, float z, float w);
    void set_mat4(const char* key, const alm::mat4& value);
};

} // namespace agama
#endif // Shader_HPP
