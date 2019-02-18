#version 330

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;

out vec4 outColour;

vec3 objectColour = vec3(0.58, 0.61, 0.627);
vec3 lightColour = vec3(0.0, 1.0, 1.0);

void main() {
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColour;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;

    vec3 result = (ambient + diffuse) * objectColour;
    outColour = vec4(result, 1.0);
}
