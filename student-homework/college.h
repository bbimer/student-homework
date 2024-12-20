#pragma once

class College
{
private:
	char clg_contacts[30];
	char clg_name[30];

public:
	College(const char* clg_contacts, const char* clg_name);
	~College();

	void copy(char* line, const char* link, int size);
	void show() const;
};

