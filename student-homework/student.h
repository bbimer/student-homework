#pragma once

class Student
{
protected:

private:
	char* pib;
	char* dateOfBirth;
	char* phone_number;
	char* city;
	char* street;
	char* house;
	char* college_info;

	const char* empty(const char* value) const;
public:
	Student(const char* pib, const char* dateOfBirth, const char* phone_number, const char* city,
		const char* street, const char* house, const char* college_info);
	Student(const Student& other);
	Student(Student&& move) noexcept;
	~Student();

	Student& operator=(const Student& other);
	Student& operator=(Student&& other) noexcept;

	void copy(char*& line, const char* link);
	void show() const;
};

