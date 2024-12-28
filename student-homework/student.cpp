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

Student::Student(const char* pib, const char* dateOfBirth, const College& college, const Contact& contact)
	: college(college), contact(contact), pib(nullptr), dateOfBirth(nullptr) {
	copy(this->pib, pib);
	copy(this->dateOfBirth, dateOfBirth);
}

Student::Student(const Student& other)
	: college(college), contact(contact), pib(nullptr), dateOfBirth(nullptr) {
	copy(this->pib, other.pib);
	copy(this->dateOfBirth, other.dateOfBirth);
}

Student::Student(Student&& move) noexcept
	: college(std::move(move.college)), contact(std::move(move.contact)), pib(move.pib), dateOfBirth(move.dateOfBirth) {
	move.pib = nullptr;
	move.dateOfBirth = nullptr;
}

Student::~Student() {
	delete[] pib;
	delete[] dateOfBirth;
}

Student& Student::operator=(const Student& other) {
	if (this == &other) return *this;

	Student temp(other);
	std::swap(pib, temp.pib);
	std::swap(dateOfBirth, temp.dateOfBirth);

	return *this;
}

Student& Student::operator=(Student&& other) noexcept {
	if (this == &other) return *this;

	delete[] pib;
	delete[] dateOfBirth;

	pib = other.pib;
	dateOfBirth = other.dateOfBirth;

	other.pib = nullptr;
	other.dateOfBirth = nullptr;

	return *this;
}
		
const char* Student::empty(const char* value) const {
	return (value && value[0] != '\0') ? value : "none";
}

void Student::show() const {
	std::cout << "[1] Student" << std::endl;
	std::cout << "student PIB:\t\t" << empty(pib) << std::endl;
	std::cout << "date of Birth:\t\t" << empty(dateOfBirth) << std::endl;
	college.show();
	contact.show();
}


