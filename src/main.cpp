#include <glad/glad.h>
// THIS MUST BE INCLUDED BELOW glad.h
#include <GLFW/glfw3.h>

#include <iostream>

struct Vertex {
    float position[3];
    float color[3];
};

const char* vs_shader_source = "#version 440 core\n"
" \
layout (location = 0) in vec3 aPos; \
layout (location = 1) in vec3 aColor; \
out vec3 oColor;\
void main() \
{ \
    oColor = aColor; \
    gl_Position = vec4(aPos,1.0f);\
} \
"
;
const char* fs_shader_source = "#version 440 core\n"
" \
out vec4 FragColor; \
in vec3 oColor;\
void main() \
{ \
    FragColor = vec4(oColor, 1.0f); \
} \
"
;

int main ()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(640, 640, "Agama Renderer", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, 640, 640);

    Vertex vertices[] = {
        {.position = {-0.5f, -0.5f, 0.0f}, .color = {0.5f, 0.0f, 1.0f}},
        {.position = { 0.5f, -0.5f, 0.0f}, .color = {0.0f, 1.0f, 0.5f}},
        {.position = { 0.0f,  0.5f, 0.0f}, .color = {1.f, 0.5f, 0.0f}},
    };
    GLuint vbo,vao;
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);


    int success;
    char infoLog[512];

    GLuint vs_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs_shader,1,&vs_shader_source,NULL);
    glCompileShader(vs_shader);

    glGetShaderiv(vs_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vs_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
    }

    GLuint fs_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs_shader,1,&fs_shader_source,NULL);
    glCompileShader(fs_shader);
    glGetShaderiv(fs_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fs_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
    }


    GLuint program = glCreateProgram();
    glAttachShader(program,vs_shader);
    glAttachShader(program,fs_shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
    }

    glDeleteShader(vs_shader);
    glDeleteShader(fs_shader);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);

        glUseProgram(program);
        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
