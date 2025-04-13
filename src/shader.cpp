#include "shader.hpp"
#include <fstream>
#include <iostream>

using namespace agama;

int success;
char infoLog[512];

ShaderProgram::ShaderProgram(const char* vs_path, const char* fs_path)
{
    program = glCreateProgram();
    Shader vs(vs_path,GL_VERTEX_SHADER);
    Shader fs(fs_path,GL_FRAGMENT_SHADER);

    glAttachShader(program,vs.getShader());
    glAttachShader(program,fs.getShader());

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED\n\tLOGS: " << infoLog << "\n";
    }
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program);
}

void
ShaderProgram::bind()
{
    glUseProgram(program);
}

void
ShaderProgram::unbind()
{
    glUseProgram(0);
}


void
ShaderProgram::set_bool(const char* key, bool value)
{
    glUniform1i(glGetUniformLocation(program, key), (int)value);
}
void
ShaderProgram::set_int(const char* key, int value)
{
    glUniform1i(glGetUniformLocation(program, key), value);
}
void
ShaderProgram::set_float(const char* key, float value)
{
    glUniform1f(glGetUniformLocation(program, key), value);
}
void
ShaderProgram::set_vec2(const char* key, const alm::vec2& value)
{
    glUniform2fv(glGetUniformLocation(program, key), 1, &value.x);
}
void
ShaderProgram::set_vec2(const char* key, float x, float y)
{
    glUniform2f(glGetUniformLocation(program, key), x, y);
}
void
ShaderProgram::set_vec3(const char* key, const alm::vec3& value)
{
    glUniform3fv(glGetUniformLocation(program, key), 1, &value.x);
}
void
ShaderProgram::set_vec3(const char* key, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(program, key), x, y, z);
}
void
ShaderProgram::set_vec4(const char* key, const alm::vec4& value)
{
    glUniform4fv(glGetUniformLocation(program, key), 1, &value.x);
}
void
ShaderProgram::set_vec4(const char* key, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(program, key), x, y, z, w);
}

void
ShaderProgram::set_mat4(const char* key, const alm::mat4& value)
{
    glUniformMatrix4fv(glGetUniformLocation(program, key), 1, GL_FALSE, &value.a11);
}

Shader::Shader(const char* path,GLenum shader_type)
{
    shader = glCreateShader(shader_type);
    std::FILE *fp = std::fopen(path, "rb");
    if (!fp)
    {
        std::cout << "DEBUG::SHADER::FAILED TO OPEN FILE\n\tAT PATH: " << path << "\n";
        return;
    }
    std::string contents;
    std::fseek(fp, 0, SEEK_END);
    contents.resize(std::ftell(fp));
    std::rewind(fp);
    std::fread(&contents[0], 1, contents.size(), fp);
    std::fclose(fp);

    const char* source = contents.c_str();
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "DEBUG::SHADER::COMPILATION FAILED \n\tAT PATH: " << path <<"\n\tLOGS: "<< infoLog << "\n";
    }
}

Shader::~Shader()
{
    glDeleteShader(shader);
}

GLuint Shader::getShader()
{
    return shader;
}
