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

Contact::Contact(const char* phone_number, const char* location, const char* country)
	: phone_number(nullptr), location(nullptr), country(nullptr) {
	copy(this->phone_number, phone_number);
	copy(this->location, location);
	copy(this->country, country);
}

Contact::Contact(const Contact& other)
	: phone_number(nullptr), location(nullptr), country(nullptr) {
	copy(this->phone_number, phone_number);
	copy(this->location, location);
	copy(this->country, country);
}

Contact::Contact(Contact&& move) noexcept
	: phone_number(nullptr), location(nullptr), country(nullptr) {
	move.phone_number = nullptr;
	move.location = nullptr;
	move.country = nullptr;
}

Contact::~Contact() {
	delete[] phone_number;
	delete[] location;
	delete[] country;
}

Contact& Contact::operator=(const Contact& other) {
	if (this == &other) return *this;

	Contact T(other);
	std::swap(phone_number, T.phone_number);
	std::swap(location, T.location);
	std::swap(country, T.country);

	return *this;
}

Contact& Contact::operator=(Contact&& other) noexcept {
	if (this == &other) {

		delete[] phone_number;
		delete[] location;
		delete[] country;


		phone_number = other.phone_number;
		location = other.location;
		country = other.country;


		other.phone_number = nullptr;
		other.location = nullptr;
		other.country = nullptr;
	}
	return *this;
}

void Contact::show() const {
	std::cout << "phone number:\t" << phone_number << std::endl;
	std::cout << "location:\t" << location << std::endl;
	std::cout << "country:\t" << country << std::endl;
	std::cout << "----------------------" << std::endl;
}


