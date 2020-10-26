#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Application.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

class MainApp : public Application {

private:
public:
	
	MainApp() : Application(800, 800, "Hello") { };
	void create() override;
	void destroy() override;

	void render() override;

	Buffer* testBuffer;
	VertexArray* vao;
	ShaderProgram* shader;


};


class SafeGlobals {
public:
	static Application* app;

	inline static void setApp(Application* a) { app = a; };
	inline static Application* getApp() { return app; };
};