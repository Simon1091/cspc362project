#include <iostream>
#include <string>
#include "ReviewCartFolder\ReviewCart.h"
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
	
	int mainchoice;
	do {
		std::cout << "Home Page\n";
		std::cout << "Please select:\n0. Exit program\n1.Login\n2.Register\n3.Browse\n4.ReviewCart\n5.Edit Profile\n6.Edit Catalog\n";

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
			std::cout << "Price + Shipping = " << cart.getTotalPrice();
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