#include <glad/glad.h>
// THIS MUST BE INCLUDED BELOW glad.h
#include <GLFW/glfw3.h>

#include <iostream>

#include "consts.h"
#include "vertexarray.hpp"
#include "shader.hpp"
#include "drawcall.hpp"

using namespace Agama;
int main ()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(INITIAL_WIDTH, INITIAL_HEIGHT, "Agama Renderer", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, INITIAL_WIDTH, INITIAL_HEIGHT);

    VertexArray va;
    va.addVertex({.position = {-0.5f, -0.5f, 0.0f}, .color = {0.5f, 0.0f, 1.0f}});
    va.addVertex({.position = { 0.5f, -0.5f, 0.0f}, .color = {0.0f, 1.0f, 0.5f}});
    va.addVertex({.position = { 0.0f,  0.5f, 0.0f}, .color = {1.f, 0.5f, 0.0f}});
    va.setData();
    ShaderProgram program("assets/basic_vert.glsl","assets/basic_frag.glsl");

    struct DrawCall drawcall = {.variant=DRAW_ARRAYS_TRIANGLE, .va=&va, .program=&program};

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw(drawcall);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
