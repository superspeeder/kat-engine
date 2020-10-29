#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>

namespace kat {

	struct GLFWCallback {
		struct Key { GLFWkeyfun func; };
		struct CursorPos { GLFWcursorposfun func; };
		struct CursorEnter { GLFWcursorenterfun func; };
		struct MouseButton { GLFWmousebuttonfun func; };
		struct Scroll { GLFWscrollfun func; };
		struct PathDrop { GLFWdropfun func; };
	};


	class Window
	{
	private:
		GLFWwindow* m_Window;

		uint32_t width, height;
		const char* caption;


	public:

		Window(uint32_t width, uint32_t height, const char* caption);
		Window(uint32_t width, uint32_t height, const char* caption, GLFWmonitor* monitor);
		Window(uint32_t width, uint32_t height, const char* caption, GLFWmonitor* monitor, Window* share);
		Window(uint32_t width, uint32_t height, const char* caption, Window* share);

		void PollEvents();
		void SwapBuffers();
		void setSwapInterval(int interval);

		bool shouldWindowClose();
		void MakeContextCurrent();

		void setKeyCallback(GLFWkeyfun func);
		void setMouseButtonCallback(GLFWmousebuttonfun func);

		void close();

		static void init();
	};

}