#include "VertexArray.h"


VertexArray::VertexArray() {
	glGenVertexArrays(1, &m_Handle);
}

void VertexArray::attribute(GLuint index, GLint size, DataType type_, bool normalized, GLuint stride, const void* pointer) {
	bind();
	GLenum type;
	switch (type_) {
	case DataType::Float:
		type = GL_FLOAT;
		break;
	case DataType::UnsignedInt:
		type = GL_UNSIGNED_INT;
		break;
	}

	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	unbind();
}

void VertexArray::enable(GLuint index) {
	bind();
	glEnableVertexAttribArray(index);
	unbind();
}

void VertexArray::bind() {
	glBindVertexArray(m_Handle);
}

void VertexArray::unbind() {
	glBindVertexArray(0);
}