#include <iostream>
#include <string>

/*
a) Module name or Class name in the Design
b) Date of the code
c) Programmer's name 
d) Brief  description of the class / service / function
e)  Any important data structure in class / functions
f)  choice of a specific algorithm within service / function
e.g.choosing quick sort rather than bubble sort etc.
*/
int main() {
	std::cout << "Home Page\n";
	std::cout << "Please select 1-6\n";
	int mainchoice;
	std::cin >> mainchoice;
	switch (mainchoice) {
	case 1: //Login
		break;
	case 2: //Register
		break;
	case 3: //Browse
		break;
	case 4: // Checkout
		break;
	case 5: //Edit profile
		break;
	case 6: //Edit Catalog
		break;
	}
	system("pause");
	return 0;
}																	