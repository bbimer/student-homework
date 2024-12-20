#include <iostream>
#include "contact.h"
#include "college.h"

int main() {
	Contact contact("+1777395000", "Los Angeles", "USA");
	contact.show();

	College college("t.me/harvard333", "Harvard university");
	college.show();

	return 0;
}