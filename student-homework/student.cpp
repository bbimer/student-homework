#include "student.h"
#include <iostream>

void Student::copy(char*& line, const char* link) {
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

Student::Student(const char* pib, const char* dateOfBirth, const char* contacts, const char* college_info)
	: pib(nullptr), dateOfBirth(nullptr), contacts(nullptr), college_info(nullptr) {
	copy(this->pib, pib);
	copy(this->dateOfBirth, dateOfBirth);
	copy(this->contacts, contacts);
	copy(this->college_info, college_info);
}

Student::~Student() {}

void Student::show() const {
	std::cout << "student pib:\t\t" << pib << std::endl;
	std::cout << "student date of birth:\t" << dateOfBirth << std::endl;
	std::cout << "student contacts:\t" << contacts << std::endl;
	std::cout << "student college info:\t" << college_info << std::endl;
	std::cout << "----------------------" << std::endl;
}


