#version 130

in vec3 Colour;
out vec4 outColour;

uniform vec3 triangleColour;

void main() {
    outColour = vec4(Colour, 1.0);
}
