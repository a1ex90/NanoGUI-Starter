#version 120

attribute vec3 position;

uniform mat4 camera;
uniform mat4 model;

void main() {
	gl_Position = camera * model * vec4(position, 1.0);
}