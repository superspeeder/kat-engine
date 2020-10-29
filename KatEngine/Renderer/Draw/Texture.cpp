#include "Texture.h"
#include <stb_image.h>
#include <stdexcept>



using namespace kat;

Texture::Texture(const char* path, unsigned int magmode) {
	int x, y, comp;
	
	unsigned char* imgData = stbi_load(path, &x, &y, &comp, 4);

	if (imgData == NULL) {
		throw std::runtime_error("Image was not loaded");
	}

	glGenTextures(1, &m_Handle);

	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magmode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

	stbi_image_free(imgData);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_Handle);
}

void Texture::activeTexture(unsigned int unit) {
	glActiveTexture(GL_TEXTURE0 + unit);
}

void Texture::init() {
	stbi_set_flip_vertically_on_load(true);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}