#pragma once

class Student
{
private:
	char* pib;
	char* dateOfBirth;
	char* contacts;
	char* college_info;

public:
	Student(const char* pib, const char* dateOfBirth, const char* contacts, const char* college_info);
	~Student();

	void copy(char*& line, const char* link);
	void show() const;
};

