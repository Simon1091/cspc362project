#include <iostream>
#include <string>
#include "ReviewCartFolder\ReviewCart.h"
#include <iomanip>
#include <limits>
#include "accounts.h"//for log ins
#include "LogIn.h"// to log in, returns the position of the logged in user in the accounts array
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
	ReviewCart review;
	ShoppingCart cart;
	item computer;
	computer.setName("Computer");
	computer.setCatagory("Electronic");
	computer.setQuantity(1);
	computer.setPrice(999.99);
	computer.setSerial(123);
	cart.addItem(computer);
	int mainchoice;
	do {
		std::cout << "\n----------------Home Page-----------------\n";
		std::cout << "Please select:\n";
		std::cout << "0. Exit program\n";
		std::cout << "1.Login\n";
		std::cout << "2.Register\n";
		std::cout  << "3.Browse\n";
		std::cout  << "4.ReviewCart\n";
		std::cout << "5.Edit Profile\n";
		std::cout << "6.Edit Catalog\n";
		std::cout << "\n------------------------------------------\n";
		std::cin >> mainchoice;
		switch (mainchoice) {

		case 1: //Login
			break;
		case 2: //Register
			break;
		case 3: //Browse
			break;
		case 4: // Review Cart: Delete item from Shopping Cart or Checkout
			
			review.review(cart);
			
			break;
		case 5: //Edit profile
			break;
		case 6: //Edit Catalog
			break;
		default:
			break;
		}
	} while (mainchoice != 0);
	system("pause");
	return 0;
}