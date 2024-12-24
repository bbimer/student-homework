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

College::College(const char* clg_phone_number, const char* clg_name, const char* clg_city, const char* clg_street)
	: clg_phone_number(nullptr), clg_name(nullptr), clg_city(nullptr), clg_street(nullptr) {
	copy(this->clg_phone_number, clg_phone_number);
	copy(this->clg_name, clg_name);
	copy(this->clg_city, clg_city);
	copy(this->clg_street, clg_street);
}

College::College(const College& other)
	: clg_phone_number(nullptr), clg_name(nullptr), clg_city(nullptr), clg_street(nullptr) {
	copy(this->clg_phone_number, clg_phone_number);
	copy(this->clg_name, clg_name);
	copy(this->clg_city, clg_city);
	copy(this->clg_street, clg_street);
}

College::College(College&& move) noexcept
	: clg_phone_number(nullptr), clg_name(nullptr), clg_city(nullptr), clg_street(nullptr) {
	move.clg_phone_number = nullptr;
	move.clg_name = nullptr;
	move.clg_city = nullptr;
	move.clg_street = nullptr;
}

College::~College() {
	delete[] clg_phone_number;
	delete[] clg_name;
	delete[] clg_city;
	delete[] clg_street;
}

College& College::operator=(const College& other) {
	if (this == &other) return *this;

	College T(other);
	std::swap(clg_phone_number, T.clg_phone_number);
	std::swap(clg_name, T.clg_name);
	std::swap(clg_city, T.clg_city);
	std::swap(clg_street, T.clg_street);

	return *this;
}

College& College::operator=(College&& other) noexcept {
	if (this == &other) {

		delete[] clg_phone_number;
		delete[] clg_name;
		delete[] clg_city;
		delete[] clg_street;


		clg_phone_number = other.clg_phone_number;
		clg_name = other.clg_name;
		clg_city = other.clg_city;
		clg_street = other.clg_street;


		other.clg_phone_number = nullptr;
		other.clg_name = nullptr;
		other.clg_city = nullptr;
		other.clg_street = nullptr;
	}
	return *this;
}

void College::show() const {
	std::cout << "College" << std::endl;
	std::cout << "college phone number: " << clg_phone_number << std::endl;
	std::cout << "college name:\t " << clg_name << std::endl;
	std::cout << "college city:\t " << clg_city << std::endl;
	std::cout << "college street:\t " << clg_street << std::endl;
	std::cout << "----------------------" << std::endl;
}


