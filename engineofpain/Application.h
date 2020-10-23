#pragma once

#ifndef KAT_WINDOW_WIDTH
#define KAT_WINDOW_WIDTH 800
#endif

#ifndef KAT_WINDOW_HEIGHT
#define KAT_WINDOW_HEIGHT 800
#endif

#ifndef KAT_WINDOW_TITLE
#define KAT_WINDOW_TITLE "Kat Game"
#endif


#include "Window.h"
#include <cinttypes>
#include <string>

class Application
{
private:
	void init();
#ifndef KAT_USE_WINDOW_MACROS
	uint32_t m_WindowWidth;
	uint32_t m_WindowHeight;
	std::string m_WindowTitle;
#endif

protected:
	Window* m_Window;
public:

#ifdef KAT_USE_WINDOW_MACROS
	Application();
#else
	Application(uint32_t windowWidth, uint32_t windowHeight, const char* windowTitle);
#endif

	void launch();

	virtual void create() { };
	virtual void destroy() { };
	
	virtual void render() { };
};

