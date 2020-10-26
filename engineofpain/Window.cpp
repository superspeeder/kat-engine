#include "Window.h"
#include <iostream>
#include <stdexcept>


Window::Window(uint32_t width, uint32_t height, const char* caption) {
	this->width = width;
	this->height = height;
	this->caption = caption;
	m_Window = glfwCreateWindow(width, height, caption, nullptr, nullptr);
	if (!m_Window) {
		glfwTerminate();
		throw std::runtime_error("GLFW could not create window");
	}
}

Window::Window(uint32_t width, uint32_t height, const char* caption, GLFWmonitor* monitor) {
	this->width = width;
	this->height = height;
	this->caption = caption;
	m_Window = glfwCreateWindow(width, height, caption, monitor, nullptr);
	if (!m_Window) {
		glfwTerminate();
		throw std::runtime_error("GLFW could not create window");
	}
}

Window::Window(uint32_t width, uint32_t height, const char* caption, Window* share) {
	this->width = width;
	this->height = height;
	this->caption = caption;
	m_Window = glfwCreateWindow(width, height, caption, nullptr, share->m_Window);
	if (!m_Window) {
		glfwTerminate();
		throw std::runtime_error("GLFW could not create window");
	}
}

Window::Window(uint32_t width, uint32_t height, const char* caption, GLFWmonitor* monitor, Window* share) {
	this->width = width;
	this->height = height;
	this->caption = caption;
	m_Window = glfwCreateWindow(width, height, caption, monitor, share->m_Window);
	if (!m_Window) {
		glfwTerminate();
		throw std::runtime_error("GLFW could not create window");
	}
}

void Window::PollEvents() {
	glfwPollEvents();
}

void Window::SwapBuffers() {
	glfwSwapBuffers(m_Window);
}

void Window::setSwapInterval(int interval) {
	glfwSwapInterval(interval);
}

bool Window::shouldWindowClose() {
	return glfwWindowShouldClose(m_Window);
}

void Window::MakeContextCurrent() {
	glfwMakeContextCurrent(m_Window);
}

void Window::setKeyCallback(GLFWkeyfun func) {
	glfwSetKeyCallback(m_Window, func);
}

void Window::setMouseButtonCallback(GLFWmousebuttonfun func) {
	glfwSetMouseButtonCallback(m_Window, func);
}


void Window::close()
{
	glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
}

void Window::init() {

	if (!glfwInit()) {
		throw std::runtime_error("GLFW could not initialize");
	}

}
