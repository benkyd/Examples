#version 130

in vec2 position;
in vec2 texcoord;
in vec3 colour;

out vec3 Colour;
out vec2 TexCoord;

void main() {
    Colour = colour;
    TexCoord = texcoord;
    gl_Position = vec4(position, 0.0, 1.0);
    // Equivilent to vec4(position.x, position.y, 0.0, 1.0)
}
