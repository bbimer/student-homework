#include <iostream>
#include "contact.h"
#include "college.h"
#include "student.h"

int main() {
	Contact contact("+1777395000", "Los Angeles", "USA");
	contact.show();

	College college("t.me/harvard333", "Harvard university");
	college.show();

	Student student1("Lev", "09/11/2007", "t.me/lev", "od.itstep.org");
	student1.show();

	Student student2(std::move(student1));
	student2.show();

	return 0;
}