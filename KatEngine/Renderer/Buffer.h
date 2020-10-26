#pragma once

#include <GL/glew.h>

#include <cinttypes>

namespace kat {

	enum Usage {
		StaticDraw, StaticRead, StaticCopy,
		DynamicDraw, DynamicRead, DynamicCopy,
		StreamDraw, StreamRead, StreamCopy
	};

	enum BufferType {
		ArrayBuffer,
		ElementArrayBuffer
	};

	class Buffer {
	private:
		unsigned int m_BufferHandle;
		unsigned int m_target;
	public:

		Buffer(unsigned int size, BufferType target, const void* data, Usage usage);
		Buffer(unsigned int size, BufferType target, const void* data);
		Buffer(BufferType type);

		void bind();
		void unbind();

		void setData(unsigned int size, const void* data, Usage usage);

	};
}