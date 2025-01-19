#include <iostream>
#include "contact.h"
#include "college.h"
#include "student.h"

int main() {
	Contact contact("+1777395000", "Los Angeles", "Strelkov, 11b", "18/18", "USA");
	//contact.show();

	contact.saveToFile("contact");

	College college("+1777397777", "Harvard university", "Los Angeles", "Yablokovskaya, 14q");
	//college.show();

	Student student1("Lev", "09/11/2007", college, contact);
	student1.show();

	student1.saveToFile("student");

	std::cout << std::endl << "====================================" << std::endl;
	Student student2(std::move(student1));
	student2.show();

	return 0;
}