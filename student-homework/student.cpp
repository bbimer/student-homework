#include "student.h"
#include <iostream>

void Student::copy(char* line, const char* link, int size) {
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

Student::Student(const char* pib, const char* dateOfBirth, const char* contacts, const char* college_info) {
	copy(this->pib, pib, sizeof(this->pib));
	copy(this->dateOfBirth, dateOfBirth, sizeof(this->dateOfBirth));
	copy(this->contacts, contacts, sizeof(this->contacts));
	copy(this->college_info, college_info, sizeof(this->college_info));
}

Student::~Student() {}

void Student::show() const {
	std::cout << "student pib:\t\t" << pib << std::endl;
	std::cout << "student date of birth:\t" << dateOfBirth << std::endl;
	std::cout << "student contacts:\t" << contacts << std::endl;
	std::cout << "student college info:\t" << college_info << std::endl;
	std::cout << "----------------------" << std::endl;
}


