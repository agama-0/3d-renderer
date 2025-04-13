#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 oColor;
void main()
{
    oColor = aColor;
	gl_Position = vec4(aPos, 1.0f) * model * view * projection;
}
