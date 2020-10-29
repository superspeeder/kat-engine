// ENGINE OF PAIN aka KatEngine

#include "Main.h"

#include <iostream>
#include <stdexcept>


Application* SafeGlobals::app;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_ESCAPE) {
		SafeGlobals::getApp()->getWindow()->close();
	}
}

void MainApp::create() {
	m_Window->setKeyCallback(key_callback);
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);


	GLfloat data[6 * 5]{
		-1,-1,0,0,0,
		 1, 1,0,1,1,
		 1,-1,0,1,0,
		-1,-1,0,0,0,
		-1, 1,0,0,1,
		 1, 1,0,1,1
	};

	testBuffer = new Buffer(6 * 5 * sizeof(GLfloat), BufferType::ArrayBuffer, data);

	vao = new VertexArray();
	vao->bind();
	testBuffer->bind();
	vao->attribute(0, 3, DataType::Float, false, 5 * sizeof(float), 0);
	vao->attribute(1, 2, DataType::Float, false, 5 * sizeof(float), (const void*)(3 * sizeof(float)));
	vao->enable(0);
	vao->enable(1);
	vao->unbind();
	testBuffer->unbind();

	shader = new ShaderProgram();
	Shader* vsh = new Shader("res/shaders/vertex0.glsl");
	Shader* fsh = new Shader("res/shaders/fragment0.glsl");

	shader->pushShader(vsh);
	shader->pushShader(fsh);
	shader->linkProgram();

	texture = new Texture("res/textures/tile0.png", GL_NEAREST);


}

void MainApp::destroy() {

}

void MainApp::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	shader->use();
	vao->bind();
	texture->bind();
	glDrawArrays(GL_TRIANGLES, 0, 9);
	vao->unbind();
}




int main() {
	
	MainApp *app = new MainApp();
	SafeGlobals::setApp(app);


	try {
		app->launch();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	delete app;
	
	return 0;
}