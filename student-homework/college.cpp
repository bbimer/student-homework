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

College::College(const char* clg_contacts, const char* clg_name) 
	: clg_contacts(nullptr), clg_name(nullptr) {
	copy(this->clg_contacts, clg_contacts);
	copy(this->clg_name, clg_name);
}

College::College(const College& other)
	: clg_contacts(nullptr), clg_name(nullptr) {
	copy(this->clg_contacts, clg_contacts);
	copy(this->clg_name, clg_name);
}

College::College(College&& move) noexcept
	: clg_contacts(nullptr), clg_name(nullptr) {
	move.clg_contacts = nullptr;
	move.clg_name = nullptr;
}

College::~College() {
	delete[] clg_contacts;
	delete[] clg_name;
}

College& College::operator=(const College& other) {
	if (this == &other) return *this;

	College T(other);
	std::swap(clg_contacts, T.clg_contacts);
	std::swap(clg_name, T.clg_name);

	return *this;
}

College& College::operator=(College&& other) noexcept {
	if (this == &other) {

		delete[] clg_contacts;
		delete[] clg_name;

		clg_contacts = other.clg_contacts;
		clg_name = other.clg_name;

		other.clg_contacts = nullptr;
		other.clg_name = nullptr;
	}
	return *this;
}

void College::show() const {
	std::cout << "college contact: " << clg_contacts << std::endl;
	std::cout << "college name:\t " << clg_name << std::endl;
	std::cout << "----------------------" << std::endl;
}


