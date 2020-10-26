#include "Buffer.h"

using namespace kat;

Buffer::Buffer(unsigned int size, BufferType target, const void* data, Usage usage) {
	switch (target) {
	case BufferType::ArrayBuffer:
		m_target = GL_ARRAY_BUFFER;
		break;
	case BufferType::ElementArrayBuffer:
		m_target = GL_ELEMENT_ARRAY_BUFFER;
		break;
	}

	glGenBuffers(1, &m_BufferHandle);

	bind();
	setData(size, data, usage);
	unbind();
}

Buffer::Buffer(unsigned int size, BufferType target, const void* data) {
	switch (target) {
	case BufferType::ArrayBuffer:
		m_target = GL_ARRAY_BUFFER;
		break;
	case BufferType::ElementArrayBuffer:
		m_target = GL_ELEMENT_ARRAY_BUFFER;
		break;
	}
	
	glGenBuffers(1, &m_BufferHandle);

	bind();
	setData(size, data, Usage::StaticDraw);
	unbind();
}

Buffer::Buffer(BufferType target) {
	switch (target) {
	case BufferType::ArrayBuffer:
		m_target = GL_ARRAY_BUFFER;
		break;
	case BufferType::ElementArrayBuffer:
		m_target = GL_ELEMENT_ARRAY_BUFFER;
		break;
	}
	
	glGenBuffers(1, &m_BufferHandle);

	bind();
	unbind();
}

void Buffer::bind() {
	glBindBuffer(m_target, m_BufferHandle);
}

void Buffer::unbind() {
	glBindBuffer(m_target, 0);
}

void Buffer::setData(unsigned int size, const void* data, Usage usage) {
	unsigned int u;
	
	switch (usage) {
	case Usage::DynamicCopy:
		u = GL_DYNAMIC_COPY;
		break;
	case Usage::DynamicDraw:
		u = GL_DYNAMIC_DRAW;
		break;
	case Usage::DynamicRead:
		u = GL_DYNAMIC_READ;
		break;
	case Usage::StaticCopy:
		u = GL_STATIC_COPY;
		break;
	case Usage::StaticDraw:
		u = GL_STATIC_DRAW;
		break;
	case Usage::StaticRead:
		u = GL_STATIC_READ;
		break;
	case Usage::StreamCopy:
		u = GL_STREAM_COPY;
		break;
	case Usage::StreamDraw:
		u = GL_STREAM_DRAW;
		break;
	case Usage::StreamRead:
		u = GL_STREAM_READ;
		break;
	}

	bind();
	glBufferData(m_target, size, data, u);
	unbind();
}