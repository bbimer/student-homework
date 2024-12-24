#pragma once

class College
{
private:
	char* clg_contacts;
	char* clg_name;

public:
	College(const char* clg_contacts, const char* clg_name);
	College(const College& other);
	College(College&& move) noexcept;
	~College();

	College& operator=(const College& other);
	College& operator=(College&& other) noexcept;

	void copy(char*& line, const char* link);
	void show() const;
};

