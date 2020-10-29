#pragma once
#include <GL/glew.h>

namespace kat {
	class Texture {
	private:
		unsigned int m_Handle;

	public:
		Texture(const char* path, unsigned int magmode);

		void bind();
		static void activeTexture(unsigned int unit);
		static void init();
	};
}