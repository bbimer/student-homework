#pragma once

class Student
{
private:
	char pib[20];
	char dateOfBirth[20];
	char contacts[20];
	char college_info[20];

public:
	Student(const char* pib, const char* dateOfBirth, const char* contacts, const char* college_info);
	~Student();

	void copy(char* line, const char* link, int size);
	void show() const;
};

