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

Student::Student(const Student& other) 
	: pib(nullptr), dateOfBirth(nullptr), contacts(nullptr), college_info(nullptr) {
	copy(this->pib, other.pib);
	copy(this->dateOfBirth, other.dateOfBirth);
	copy(this->contacts, other.contacts);
	copy(this->college_info, other.college_info);
}

Student::Student(Student&& move) noexcept
	: pib(move.pib), dateOfBirth(move.dateOfBirth), contacts(move.contacts), college_info(move.college_info) {
	move.pib = nullptr;
	move.dateOfBirth = nullptr;
	move.contacts = nullptr;
	move.college_info = nullptr;
}

Student::~Student() {
	delete[] pib;
	delete[] dateOfBirth;
	delete[] contacts;
	delete[] college_info;
}

Student& Student::operator=(const Student& other) {
	if (this == &other) return *this;

	Student T(other);
	std::swap(pib, T.pib);
	std::swap(dateOfBirth, T.dateOfBirth);
	std::swap(contacts, T.contacts);
	std::swap(college_info, T.college_info);

	return *this;
}

Student& Student::operator=(Student&& other) noexcept {
	if (this == &other) {
		
		delete[] pib;
		delete[] dateOfBirth;
		delete[] contacts;
		delete[] college_info;

		pib = other.pib;
		dateOfBirth = other.dateOfBirth;
		contacts = other.contacts;
		college_info = other.college_info;

		other.pib = nullptr;
		other.dateOfBirth = nullptr;
		other.contacts = nullptr;
		other.college_info = nullptr;
	}
	return *this;
}
						
void Student::show() const {
	std::cout << "student pib:\t\t" << pib << std::endl;
	std::cout << "student date of birth:\t" << dateOfBirth << std::endl;
	std::cout << "student contacts:\t" << contacts << std::endl;
	std::cout << "student college info:\t" << college_info << std::endl;
	std::cout << "----------------------" << std::endl;
}


