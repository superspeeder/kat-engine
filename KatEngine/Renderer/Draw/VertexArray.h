#pragma once

#include <GL/glew.h>

namespace kat {

	enum DataType {
		Float, UnsignedInt
	};


	class VertexArray
	{

	private:
		unsigned int m_Handle;
	public:

		VertexArray();

		void enable(GLuint index);
		void attribute(GLuint index, GLint size, DataType type, bool normalized, GLuint stride, const void* pointer);

		void bind();
		void unbind();
	};

}