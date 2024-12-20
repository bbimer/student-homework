#include "college.h"
#include <iostream>

void College::copy(char* line, const char* link, int size) {
	if (!link)
	{
		line[0] = '\0';
		return;
	}

	int i = 0;
	for (; i < size - 1 && link[i] != '\0'; ++i) {
		line[i] = link[i];
	}
	line[i] = '\0';
}

College::College(const char* clg_contacts, const char* clg_name) {
	copy(this->clg_contacts, clg_contacts, sizeof(this->clg_contacts));
	copy(this->clg_name, clg_name, sizeof(this->clg_name));
}

College::~College() {}

void College::show() const {
	std::cout << "college contact: " << clg_contacts << std::endl;
	std::cout << "college name:\t " << clg_name << std::endl;
	std::cout << "----------------------" << std::endl;
}


