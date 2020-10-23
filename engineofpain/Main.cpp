// ENGINE OF PAIN aka KatEngine

#include "Main.h"

#include <iostream>
#include <stdexcept>

void MainApp::create() {
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
}

void MainApp::destroy() {

}

void MainApp::render() {
	glClear(GL_COLOR_BUFFER_BIT);
}



int main() {
	
	MainApp *app = new MainApp();

	try {
		app->launch();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	delete app;
	return 0;
}