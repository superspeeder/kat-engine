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


	GLfloat data[3 * 3]{
		0,0,0,
		1,1,0,
		1,0,0
	};

	testBuffer = new Buffer(3 * 3 * sizeof(GLfloat), BufferType::ArrayBuffer, data);

	vao = new VertexArray();
	vao->bind();
	testBuffer->bind();
	vao->attribute(0, 3, DataType::Float, false, 3 * sizeof(float), 0);
	vao->enable(0);
	vao->unbind();
	testBuffer->unbind();
}

void MainApp::destroy() {

}

void MainApp::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	vao->bind();
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