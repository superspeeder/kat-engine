#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "Application.h"

class MainApp : public Application {

public:
	
	MainApp() : Application(800, 800, "Hello Haydon") {};

	void create() override;
	void destroy() override;

	void render() override;
};