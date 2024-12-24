#include <iostream>
#include "contact.h"
#include "college.h"
#include "student.h"

int main() {
	Contact contact("+1777395000", "Los Angeles", "Strelkov, 11b", "18/18", "USA");
	contact.show();

	College college("+1777397777", "Harvard university", "Los Angeles", "Yablokovskaya, 14q");
	college.show();

	Student student1("Lev", "09/11/2007", "+3804770899", "Kyiv", "Armeyskaya, 9a", "14/17", "od.itstep.org");
	student1.show();

	Student student2(std::move(student1));
	student2.show();

	return 0;
}