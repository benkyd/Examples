#version 150 core

in vec2 position;

void main() {
    gl_position = vec4(position, 0.0, 1.0);
    // Equivilent to vec4(position.x, position.y, 0.0, 1.0)
}
