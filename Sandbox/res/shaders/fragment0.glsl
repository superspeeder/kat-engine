#shader fragment
#version 450

in vec2 uv;

out vec4 color;

uniform sampler2D tex0;

void main() {
	color = texture(tex0, uv);
}
