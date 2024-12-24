#pragma once

class Contact
{
private:
    char* phone_number;
    char* city;
    char* street;
    char* house;
    char* country;

    const char* empty(const char* value) const;
public:
    Contact(const char* phone_number, const char* city, const char* street, const char* house, const char* country);
    Contact(const Contact& other);
    Contact(Contact&& move) noexcept;
    ~Contact();

    Contact& operator=(const Contact& other);
    Contact& operator=(Contact&& other) noexcept;

    void copy(char*& line, const char* link);
    void show() const;
};
