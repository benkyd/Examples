#version 330

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
vec3 viewPos = vec3(0.0, 0.0, 0.0);

out vec4 outColour;

vec3 objectColour = vec3(0.58, 0.61, 0.627);
vec3 lightColour = vec3(1.0, 0.0, 1.0);

void main() {
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColour;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;



    float specularStrength = 0.5;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColour;



    vec3 result = (ambient + diffuse + specular) * objectColour;
    outColour = vec4(result, 1.0);
}
