#ifndef Camera_HPP
#define Camera_HPP
#include <GLFW/glfw3.h> // including glfw, therefore camera cannot be used standalone
#include "alm.hpp"

#define CAMERA_DEFAULT_POSITION {0, 0, 1}
#define CAMERA_DEFAULT_UP {0, 1, 0}
#define CAMERA_DEFAULT_YAW -90.0f
#define CAMERA_DEFAULT_PITCH 0.0f
#define CAMERA_DEFAULT_SPEED 2.5f
#define CAMERA_DEFAULT_ZOOM 45.0f
#define CAMERA_DEFAULT_ASPECT 1.0f
#define CAMERA_DEFAULT_NEAR 0.01f
#define CAMERA_DEFAULT_FAR 1000.0f
#define CAMERA_DEFAULT_SENSITIVITY 0.1f

namespace agama {
// reference: https://learnopengl.com/Getting-Started/Camera
struct Camera {
    private:
    alm::vec3 position;

    float yaw;
    float pitch;
    float zoom;
    float aspect;

    public:
    alm::vec3 world_up;
    Camera();
    ~Camera();
    alm::vec3 get_front();
    alm::vec3 get_up();
    alm::vec3 get_right();
    alm::mat4 get_view();
    alm::mat4 get_projection(float near = CAMERA_DEFAULT_NEAR, float far = CAMERA_DEFAULT_FAR);
    void move_forward(float delta, float speed);
    void move_up(float delta, float speed);
    void move_right(float delta, float speed);
    void rotate_yaw(float x_offset, float sensitivity = CAMERA_DEFAULT_SENSITIVITY);
    void rotate_pitch(float y_offset, float sensitivity = CAMERA_DEFAULT_SENSITIVITY);
    void set_zoom(float y_offset);
    void set_aspect(int w, int h);
};
} // namespace agama
#endif // Camera_HPP
