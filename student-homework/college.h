#pragma once

class College
{
private:
	char* clg_contacts;
	char* clg_name;

public:
	College(const char* clg_contacts, const char* clg_name);
	~College();

	void copy(char*& line, const char* link);
	void show() const;
};

