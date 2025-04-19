#include "camera.hpp"
#include <math.h>
using namespace agama;

Camera::Camera() :
    world_up(CAMERA_DEFAULT_UP),
    position(CAMERA_DEFAULT_POSITION),
    yaw(CAMERA_DEFAULT_YAW),
    pitch(CAMERA_DEFAULT_PITCH),
    zoom(CAMERA_DEFAULT_ZOOM),
    aspect(CAMERA_DEFAULT_ASPECT)
{}

Camera::~Camera()
{}

alm::vec3
Camera::get_front()
{
    return alm::norm((alm::vec3){
        cosf(deg2rad(yaw) * cosf(deg2rad(pitch))),
        sinf(deg2rad(pitch)),
        sinf(deg2rad(yaw)) * cosf(deg2rad(pitch))
    });
}

alm::vec3
Camera::get_right()
{
    return alm::norm(alm::cross(get_front(), world_up));
}

alm::vec3
Camera::get_up()
{
    return alm::norm(alm::cross(get_right(), get_front()));
}

alm::vec3
Camera::get_target()
{
    return position + get_front();
}

alm::mat4
Camera::get_view()
{
    return alm::look_at(position, get_target(), get_up());
}

alm::mat4
Camera::get_projection(float near, float far)
{
    return alm::perspective(deg2rad(zoom), aspect, near, far);
}

void
Camera::move_forward(float delta, float speed)
{
    position = position + (get_front() * speed * delta);
}

void
Camera::move_up(float delta, float speed)
{
    position = position + (get_up() * speed * delta);
}


void
Camera::move_right(float delta, float speed)
{
    position = position + (get_right() * speed * delta);
}

void
Camera::rotate_yaw(float x_offset, float sensitivity)
{
    yaw += x_offset * sensitivity;
}
void
Camera::rotate_pitch(float y_offset, float sensitivity)
{
    pitch += y_offset * sensitivity;
    if (pitch > 89.f)
    {
        pitch = 89.f;
    }
    if (pitch < -89.f)
    {
        pitch = -89.f;
    }
}

void
Camera::set_zoom(float y_offset)
{
    zoom -= y_offset;
    if (zoom < 1.f)
    {
        zoom = 1.f;
    }
    if (zoom > 89.f)
    {
        zoom = 89.f;
    }
}

void
Camera::set_aspect(int w, int h)
{
    aspect = (float)w / (float)h;
}
