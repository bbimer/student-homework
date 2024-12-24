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

Student::Student(const char* pib, const char* dateOfBirth, const char* phone_number, const char* city,
	const char* street, const char* house, const char* college_info)
	: pib(nullptr), dateOfBirth(nullptr), phone_number(nullptr), city(nullptr),
	street(nullptr), house(nullptr), college_info(nullptr) {
	copy(this->pib, pib);
	copy(this->dateOfBirth, dateOfBirth);
	copy(this->phone_number, phone_number);
	copy(this->city, city);
	copy(this->street, street);
	copy(this->house, house);
	copy(this->college_info, college_info);
}

Student::Student(const Student& other)
	: pib(nullptr), dateOfBirth(nullptr), phone_number(nullptr), city(nullptr),
	street(nullptr), house(nullptr), college_info(nullptr) {
	copy(this->pib, other.pib);
	copy(this->dateOfBirth, other.dateOfBirth);
	copy(this->phone_number, other.phone_number);
	copy(this->city, other.city);
	copy(this->street, other.street);
	copy(this->house, other.house);
	copy(this->college_info, other.college_info);
}

Student::Student(Student&& move) noexcept
	: pib(move.pib), dateOfBirth(move.dateOfBirth), phone_number(move.phone_number), city(move.city),
	street(move.street), house(move.house), college_info(move.college_info) {
	move.pib = nullptr;
	move.dateOfBirth = nullptr;
	move.phone_number = nullptr;
	move.city = nullptr;
	move.street = nullptr;
	move.house = nullptr;
	move.college_info = nullptr;
}

Student::~Student() {
	delete[] pib;
	delete[] dateOfBirth;
	delete[] phone_number;
	delete[] city;
	delete[] street;
	delete[] house;
	delete[] college_info;
}

Student& Student::operator=(const Student& other) {
	if (this == &other) return *this;

	Student temp(other);
	std::swap(pib, temp.pib);
	std::swap(dateOfBirth, temp.dateOfBirth);
	std::swap(phone_number, temp.phone_number);
	std::swap(city, temp.city);
	std::swap(street, temp.street);
	std::swap(house, temp.house);
	std::swap(college_info, temp.college_info);

	return *this;
}

Student& Student::operator=(Student&& other) noexcept {
	if (this == &other) return *this;

	delete[] pib;
	delete[] dateOfBirth;
	delete[] phone_number;
	delete[] city;
	delete[] street;
	delete[] house;
	delete[] college_info;

	pib = other.pib;
	dateOfBirth = other.dateOfBirth;
	phone_number = other.phone_number;
	city = other.city;
	street = other.street;
	house = other.house;
	college_info = other.college_info;

	other.pib = nullptr;
	other.dateOfBirth = nullptr;
	other.phone_number = nullptr;
	other.city = nullptr;
	other.street = nullptr;
	other.house = nullptr;
	other.college_info = nullptr;

	return *this;
}
						
void Student::show() const {
	std::cout << "Student" << std::endl;
	std::cout << "student PIB:\t\t" << pib << std::endl;
	std::cout << "date of Birth:\t\t" << dateOfBirth << std::endl;
	std::cout << "phone Number:\t\t" << phone_number << std::endl;
	std::cout << "city:\t\t\t" << city << std::endl;
	std::cout << "street:\t\t\t" << street << std::endl;
	std::cout << "house:\t\t\t" << house << std::endl;
	std::cout << "college Info:\t\t" << college_info << std::endl;
	std::cout << "----------------------" << std::endl;
}


