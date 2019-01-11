#version 130

in vec2 position;
in vec3 colour;

out vec3 Colour;

void main() {
    Colour = colour;
    gl_Position = vec4(position, 0.0, 1.0);
    // Equivilent to vec4(position.x, position.y, 0.0, 1.0)
}
