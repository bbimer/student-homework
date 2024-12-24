#pragma once

class Contact
{
private:
    char* phone_number;
    char* location;
    char* country;

public:
    Contact(const char* phone_number, const char* location, const char* country);
    Contact(const Contact& other);
    Contact(Contact&& move) noexcept;
    ~Contact();

    Contact& operator=(const Contact& other);
    Contact& operator=(Contact&& other) noexcept;

    void copy(char*& line, const char* link);
    void show() const;
};
