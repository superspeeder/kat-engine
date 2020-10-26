#pragma once

#include <GL/glew.h>
#include <cinttypes>


enum BufferUsage {
	StaticDraw, StaticRead, StaticWrite
};

enum DataType {
	Float, UInt
};


class Buffer {
public:
	Buffer(DataType type, uint32_t size, const void* data, BufferUsage usage);
};


class VertexBuffer : public Buffer {
public:
	VertexBuffer(const int count, float* data, BufferUsage usage) : Buffer(DataType::Float, count * sizeof(GLfloat), data, usage) {};
};

