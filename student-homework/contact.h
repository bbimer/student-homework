#pragma once

class Contact
{
private:
	char phone_number[20];
	char location[20];
	char country[20];

public:
	Contact(const char* phone_number, const char* location, const char* country);
	~Contact();

	void copy(char* line, const char* link, int size);
	void show() const;
};

