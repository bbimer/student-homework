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

Contact::~Contact() {
	delete[] phone_number;
	delete[] location;
	delete[] country;
}

void Contact::show() const {
	std::cout << "phone number:\t" << phone_number << std::endl;
	std::cout << "location:\t" << location << std::endl;
	std::cout << "country:\t" << country << std::endl;
	std::cout << "----------------------" << std::endl;
}


