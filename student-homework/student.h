#pragma once

#include "college.h"
#include "contact.h"

class Student
{
protected:

private:
	College college;
	Contact contact;
	char* pib;
	char* dateOfBirth;

	const char* empty(const char* value) const;
public:
	Student(const char* pib, const char* dateOfBirth, const College& college, const Contact& contact);
	Student(const Student& other);
	Student(Student&& move) noexcept;
	~Student();

	Student& operator=(const Student& other);
	Student& operator=(Student&& other) noexcept;

	void copy(char*& line, const char* link);
	void show() const;

	void saveToFile(std::ofstream& outFile) const;
	//void loadFromFile(const std::string& filename);
};

