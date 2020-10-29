#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Application.h>
#include <Renderer/Draw/VertexArray.h>
#include <Renderer/Draw/Buffer.h>
#include <Renderer/Draw/Shader.h>
#include <Renderer/Draw/Texture.h>

using namespace kat;

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
	Texture* texture;


};


class SafeGlobals {
public:
	static Application* app;

	inline static void setApp(Application* a) { app = a; };
	inline static Application* getApp() { return app; };
};