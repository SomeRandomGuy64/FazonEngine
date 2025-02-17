#version 460 core				
in vec3 fragColour;

out vec4 colour;

void main() {
	colour = vec4(fragColour, 1.0);
}