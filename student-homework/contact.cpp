#include "contact.h"
#include <iostream>

void Contact::copy(char* line, const char* link, int size) {
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

Contact::Contact(const char* phone_number, const char* location, const char* country) {
	copy(this->phone_number, phone_number, sizeof(this->phone_number));
	copy(this->location, location, sizeof(this->location));
	copy(this->country, country, sizeof(this->country));
}

Contact::~Contact() {}

void Contact::show() const {
	std::cout << "phone number:\t" << phone_number << std::endl;
	std::cout << "location:\t" << location << std::endl;
	std::cout << "country:\t" << country << std::endl;
	std::cout << "----------------------" << std::endl;
}


