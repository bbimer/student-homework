#include "contact.h"
#include <iostream>

void Contact::copy(char*& line, const char* link) {
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

Contact::Contact(const char* phone_number, const char* city, const char* street, const char* house, const char* country)
	: phone_number(nullptr), city(nullptr), street(nullptr), house(nullptr), country(nullptr) {
	copy(this->phone_number, phone_number);
	copy(this->city, city);
	copy(this->street, street);
	copy(this->house, house);
	copy(this->country, country);
}

Contact::Contact(const Contact& other)
	: phone_number(nullptr), city(nullptr), street(nullptr), country(nullptr) {
	copy(this->phone_number, phone_number);
	copy(this->city, city);
	copy(this->street, street);
	copy(this->house, house);
	copy(this->country, country);
}

Contact::Contact(Contact&& move) noexcept
	: phone_number(nullptr), city(nullptr), street(nullptr), country(nullptr) {
	move.phone_number = nullptr;
	move.city = nullptr;
	move.street = nullptr;
	move.house = nullptr;
	move.country = nullptr;
}

Contact::~Contact() {
	delete[] phone_number;
	delete[] city;
	delete[] street;
	delete[] house;
	delete[] country;
}

Contact& Contact::operator=(const Contact& other) {
	if (this == &other) return *this;

	Contact T(other);
	std::swap(phone_number, T.phone_number);
	std::swap(city, T.city);
	std::swap(street, T.street);
	std::swap(house, T.house);
	std::swap(country, T.country);

	return *this;
}

Contact& Contact::operator=(Contact&& other) noexcept {
	if (this == &other) {

		delete[] phone_number;
		delete[] city;
		delete[] street;
		delete[] house;
		delete[] country;


		phone_number = other.phone_number;
		city = other.city;
		street = other.street;
		house = other.house;
		country = other.country;


		other.phone_number = nullptr;
		other.city = nullptr;
		other.street = nullptr;
		other.house = nullptr;
		other.country = nullptr;
	}
	return *this;
}

const char* Contact::empty(const char* value) const {
	return (value && value[0] != '\0') ? value : "none";
}

void Contact::show() const {
	std::cout << "Contacts" << std::endl;
	std::cout << "phone number:\t" << empty(phone_number) << std::endl;
	std::cout << "city:\t\t" << empty(city) << std::endl;
	std::cout << "street:\t\t" << empty(street) << std::endl;
	std::cout << "house:\t\t" << empty(house) << std::endl;
	std::cout << "country:\t" << empty(country) << std::endl;
	std::cout << "----------------------" << std::endl;
}


