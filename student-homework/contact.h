#pragma once

class Contact
{
private:
    char* phone_number;
    char* location;
    char* country;

public:
    Contact(const char* phone_number, const char* location, const char* country);
    ~Contact();

    void copy(char*& line, const char* link);
    void show() const;
};
