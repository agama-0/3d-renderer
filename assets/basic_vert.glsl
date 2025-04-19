#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aUv;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 vColor;
out vec2 vUv;
void main()
{
    vColor = aColor;
    vUv = aUv;
    // why this works
	// gl_Position = vec4(aPos, 1.0f) * model * view * projection;
	// but in reality this should work instead
	gl_Position =  vec4(aPos, 1.0f) * model * view * projection;
}
