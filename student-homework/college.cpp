#include "college.h"
#include <iostream>

void College::copy(char*& line, const char* link) {
	delete[] line;
	if (link)
	{
		size_t length = std::strlen(link);
		line = new char[length + 1];
		int i = 0;
		for (; i < length; ++i)
		{
			line[i] = link[i];
		}
		line[i] = '\0';
	}
	else
	{
		line = nullptr;
	}
}

College::College(const char* clg_contacts, const char* clg_name) {
	copy(this->clg_contacts, clg_contacts);
	copy(this->clg_name, clg_name);
}

College::~College() {}

void College::show() const {
	std::cout << "college contact: " << clg_contacts << std::endl;
	std::cout << "college name:\t " << clg_name << std::endl;
	std::cout << "----------------------" << std::endl;
}


