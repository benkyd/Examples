#version 130

in vec3 Colour;
in vec2 TexCoord;
out vec4 outColour;

uniform vec3 triangleColour;

uniform sampler2D tex;

void main() {
    outColour = texture(tex, TexCoord);// * vec4(Colour, 1.0);
}
