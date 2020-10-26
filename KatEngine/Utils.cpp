#include "Utils.h"

#include <fstream>
#include <sstream>

std::string kat::readFile(const char* path) {
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

kat::Directive kat::parseDirective(const char* line) {
	std::string type;
	std::string value;


	int p = 0;

	for (int i = 1; i < strlen(line); i++) {
		char c = line[i];
		if (p == 0) {
			if (c == ' ') {
				p = 1;
			}
			else {
				type.push_back(c);
			}
		}
		else {
			value.push_back(c);
		}
	}
	return Directive{ type,value };
}

bool kat::lineContainsDirective(const char* line) {
	return line[0] == '#';
}