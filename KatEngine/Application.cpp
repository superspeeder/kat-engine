#include "Application.h"
#include <stdexcept>

#include "Renderer/Draw/Texture.h"

using namespace kat;

#ifdef KAT_USE_WINDOW_MACROS
Application::Application() {
}


#else
Application::Application(uint32_t windowWidth, uint32_t windowHeight, const char* windowTitle) {
	m_WindowHeight = windowHeight;
	m_WindowWidth = windowWidth;
	m_WindowTitle = windowTitle;
}
#endif

void Application::init() {
	Window::init();

#ifdef KAT_USE_WINDOW_MACROS
	m_Window = new Window(KAT_WINDOW_WIDTH, KAT_WINDOW_HEIGHT, KAT_WINDOW_TITLE);
#else
	m_Window = new Window(m_WindowWidth, m_WindowHeight, m_WindowTitle.c_str());
#endif

	m_Window->MakeContextCurrent();

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		throw std::runtime_error("GLEW could not initialize");
	}

	Texture::init();
}

void Application::launch() {
	init();

	create();

	while (!m_Window->shouldWindowClose()) {
		m_Window->PollEvents();
		render();
		m_Window->SwapBuffers();
	}

	destroy();
	delete m_Window;

}