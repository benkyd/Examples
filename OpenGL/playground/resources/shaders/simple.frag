#version 330

// in vec3 Colour;
// in vec2 TexCoord;
out vec4 outColour;

uniform vec3 triangleColour;

uniform sampler2D tex;

void main() {
    outColour = vec4(0.23, 0.58, 0.12, 1.0);
}
