#version 330 

in vec3 position;
// in vec2 texcoord;
// in vec3 colour;

// out vec3 Colour;
// out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    // Colour = colour;
    // TexCoord = texcoord;
    gl_Position = proj * view * model * vec4(position, 1.0);
}
