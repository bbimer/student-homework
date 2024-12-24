#pragma once

class College
{
private:
	char* clg_phone_number;
	char* clg_name;
	char* clg_city;
	char* clg_street;

public:
	College(const char* clg_phone_number, const char* clg_name, const char* clg_city, const char* clg_street);
	College(const College& other);
	College(College&& move) noexcept;
	~College();

	College& operator=(const College& other);
	College& operator=(College&& other) noexcept;

	void copy(char*& line, const char* link);
	void show() const;
};

