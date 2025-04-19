#include <glad/glad.h>
// THIS MUST BE INCLUDED BELOW glad.h
#include <GLFW/glfw3.h>
#define  STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "consts.h"
#include "vertexarray.hpp"
#include "shader.hpp"
#include "drawcall.hpp"
#include "camera.hpp"
#include "alm.hpp"
using namespace agama;
using namespace alm;

void cursor_enter_callback(GLFWwindow* window, int entered);
void scroll_callback(GLFWwindow* window, double sx, double sy);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow *window);
void set_cursor_pos_callback(GLFWwindow* window, double mx, double my);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_btn_callback(GLFWwindow* window, int button, int action, int mods);

int window_width = INITIAL_WIDTH, window_height = INITIAL_HEIGHT;
Camera cam;
int enable_cursor_movement = false;
std::vector<vec4> objs;
int main ()
{
    glfwInit();
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Agama Renderer", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, window_width, window_height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorEnterCallback(window,cursor_enter_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_btn_callback);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("assets/sample_texture.jpg", &width, &height, &nrChannels, 0);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    VertexArray va;

    // -z
    va.addVertex({{+1, +1, -1}, {1, 1, 0}, {0, 0}});
    va.addVertex({{+1, -1, -1}, {1, 1, 0}, {0, 1}});
    va.addVertex({{-1, -1, -1}, {1, 1, 0}, {1, 1}});
    va.addVertex({{+1, +1, -1}, {1, 1, 0}, {0, 0}});
    va.addVertex({{-1, -1, -1}, {1, 1, 0}, {1, 1}});
    va.addVertex({{-1, +1, -1}, {1, 1, 0}, {1, 0}});

    // + z
    va.addVertex({{+1, +1, +1}, {0, 0, 1}, {0, 0}});
    va.addVertex({{-1, -1, +1}, {0, 0, 1}, {1, 1}});
    va.addVertex({{+1, -1, +1}, {0, 0, 1}, {0, 1}});
    va.addVertex({{+1, +1, +1}, {0, 0, 1}, {0, 0}});
    va.addVertex({{-1, +1, +1}, {0, 0, 1}, {1, 0}});
    va.addVertex({{-1, -1, +1}, {0, 0, 1}, {1, 1}});

    // -y
    va.addVertex({{+1, -1, -1}, {1, 0, 1}, {0, 0}});
    va.addVertex({{-1, -1, +1}, {1, 0, 1}, {1, 1}});
    va.addVertex({{-1, -1, -1}, {1, 0, 1}, {0, 1}});
    va.addVertex({{+1, -1, -1}, {1, 0, 1}, {0, 0}});
    va.addVertex({{+1, -1, +1}, {1, 0, 1}, {1, 0}});
    va.addVertex({{-1, -1, +1}, {1, 0, 1}, {1, 1}});

    // +y
    va.addVertex({{+1, +1, -1}, {0, 1, 0}, {0, 0}});
    va.addVertex({{-1, +1, -1}, {0, 1, 0}, {0, 1}});
    va.addVertex({{-1, +1, +1}, {0, 1, 0}, {1, 1}});
    va.addVertex({{+1, +1, -1}, {0, 1, 0}, {0, 0}});
    va.addVertex({{-1, +1, +1}, {0, 1, 0}, {1, 1}});
    va.addVertex({{+1, +1, +1}, {0, 1, 0}, {1, 0}});

    // -x
    va.addVertex({{-1, -1, -1}, {0, 1, 1}, {0, 0}});
    va.addVertex({{-1, +1, +1}, {0, 1, 1}, {1, 1}});
    va.addVertex({{-1, +1, -1}, {0, 1, 1}, {0, 1}});
    va.addVertex({{-1, -1, -1}, {0, 1, 1}, {0, 0}});
    va.addVertex({{-1, -1, +1}, {0, 1, 1}, {1, 0}});
    va.addVertex({{-1, +1, +1}, {0, 1, 1}, {1, 1}});

    // +x
    va.addVertex({{+1, -1, -1}, {1, 0, 0}, {0, 0}});
    va.addVertex({{+1, +1, -1}, {1, 0, 0}, {0, 1}});
    va.addVertex({{+1, +1, +1}, {1, 0, 0}, {1, 1}});
    va.addVertex({{+1, -1, -1}, {1, 0, 0}, {0, 0}});
    va.addVertex({{+1, +1, +1}, {1, 0, 0}, {1, 1}});
    va.addVertex({{+1, -1, +1}, {1, 0, 0}, {1, 0}});

    va.setData();
    ShaderProgram program("assets/basic_vert.glsl","assets/basic_frag.glsl");
    struct DrawCall drawcall = {.variant=DRAW_ARRAYS_TRIANGLE, .va=&va, .program=&program};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    objs.push_back({0, 0, -5, 3.14});
    while (!glfwWindowShouldClose(window))
    {
        cam.set_aspect(window_width, window_height);
        process_input(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (size_t i = 0; i < objs.size(); ++i) {
            vec4 obj = objs[i];
            vec3 obj_pos = {obj.x, obj.y, obj.z};

            mat4 model = {
                1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1,
            };
            // Transformation Operation Must be Performed in this order: Scale -> Rotate -> Translate
            model =  scale({1, 1, 1}) * model;
            model = rotate(obj.w + deg2rad(glfwGetTime() * 30 * PI), {1, 1, 1}) * model;
            model =  translate(obj_pos) * model;
            mat4 view = cam.get_view();
            mat4 projection = cam.get_projection();
            program.bind();
            program.set_mat4("model", model);
            program.set_mat4("view", view);
            program.set_mat4("projection", projection);
            draw(drawcall);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}

double prev_mx, prev_my;
bool first_mouse = true;
void process_input(GLFWwindow *window)
{
    // WSAD
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        cam.move_forward(1, CAMERA_DEFAULT_SPEED / 60.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        cam.move_forward(1, -CAMERA_DEFAULT_SPEED / 60.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        cam.move_right(1, -CAMERA_DEFAULT_SPEED / 60.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        cam.move_right(1, CAMERA_DEFAULT_SPEED / 60.0f);
    }
    // cursor move
    if (enable_cursor_movement)
    {
        double pmx = int(window_width/2.f), pmy = int(window_height/2.f);
        if (first_mouse)
        {
            glfwSetCursorPos(window, pmx, pmy);
            first_mouse = false;
        }
        double mx, my;
        glfwGetCursorPos(window, &mx, &my);
        cam.rotate_yaw(mx - pmx, 0.1);
        cam.rotate_pitch(pmy - my, 0.1);
        glfwSetCursorPos(window, pmx, pmy);
    }
}

void mouse_btn_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
    {
        vec3 target = cam.get_target();
        target = target + (norm(cam.get_front()) * 10);
        float angle = (float)deg2rad(glfwGetTime() * 30 * PI);
        objs.push_back({target.x, target.y, target.z, angle});
    }
}

// for only key "down" events
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    if (key == GLFW_KEY_P && action == GLFW_PRESS)
    {
        enable_cursor_movement = !enable_cursor_movement;
        if (enable_cursor_movement)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void cursor_enter_callback(GLFWwindow* window, int entered)
{
    first_mouse = !entered;
}

void scroll_callback(GLFWwindow* window, double sx, double sy)
{
    cam.set_zoom(sy);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    window_width = width;
    window_height = height;
    cam.set_aspect(width, height);
    glViewport(0, 0, width, height);
}
