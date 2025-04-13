#include <glad/glad.h>
// THIS MUST BE INCLUDED BELOW glad.h
#include <GLFW/glfw3.h>
#include "consts.h"
#include "vertexarray.hpp"
#include "shader.hpp"
#include "drawcall.hpp"
#include "alm.hpp"
using namespace agama;
using namespace alm;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    VertexArray va;
    // triangle 1
    va.addVertex({{-1, -1, 0}, {1, 0, 1}});
    va.addVertex({{ 1, -1, 0}, {0, 1, 1}});
    va.addVertex({{ 0,  1, 0}, {1, 1, 0}});
    // triangle 2
    va.addVertex({{ 0, -1, -1}, {1, 0, 1}});
    va.addVertex({{ 0, -1,  1}, {0, 1, 1}});
    va.addVertex({{ 0,  1,  0}, {1, 1, 0}});
    va.setData();
    ShaderProgram program("assets/basic_vert.glsl","assets/basic_frag.glsl");

    struct DrawCall drawcall = {.variant=DRAW_ARRAYS_TRIANGLE, .va=&va, .program=&program};

    glEnable(GL_DEPTH_TEST);

    int wx, wy;

    while (!glfwWindowShouldClose(window))
    {

        glfwGetWindowSize(window, &wx, &wy);
        processInput(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 model = {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1,
        };
        model =  translate({0,0,0}) * model;
        model = rotate(deg2rad(glfwGetTime() * 30 * PI),{1, 0, 0}) * model;
        model =  scale({0.25, 0.25, 0.25}) * model;

        mat4 view = look_at({1,0,1}, {0,0,0}, {0,1,0});
        mat4 projection = perspective(deg2rad(45), (float)wx / wy, 0.01, 100);

        program.bind();
        program.set_mat4("model", model);
        program.set_mat4("view", view);
        program.set_mat4("projection", projection);
        draw(drawcall);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
