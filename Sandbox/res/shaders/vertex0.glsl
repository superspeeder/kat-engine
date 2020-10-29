#shader vertex
#version 450

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv_;

out vec2 uv;

void main() {
	gl_Position = vec4(vertex, 1.0f);
	uv = uv_;
}