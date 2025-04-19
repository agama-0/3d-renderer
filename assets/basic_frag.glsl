#version 440 core
out vec4 FragColor;
in vec3 vColor;
in vec2 vUv;
uniform sampler2D tex_0;
void main()
{
    vec4 t_color = texture(tex_0, vUv);
    FragColor = vec4(t_color.rgb * 0.8 + vColor.rgb * 0.3, 1.0);
}
