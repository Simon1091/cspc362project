#include <iostream>
#include <string>
#include "ReviewCartFolder\ReviewCart.h"
#include <iomanip>
#include <limits>
#include "Accounts.h"//for log ins
#include "LogIn.h"// to log in, returns the position of the logged in user in the accounts array
#include "ModifyCatalog.h"
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
	//for log in by Derek
	int accountNumber;// gets its value from LogInMenu; this refers to the position of the logged in user in the account array!


	ReviewCart review;
	ShoppingCart cart;
	Item computer;
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
			accountNumber = logInMenu();//takes you to log in menu, performs complete log in from there.
			break;
		case 2: //Register *NOTE - from Derek* -> this can probably be deleted since the log in function handles registering!
			break;
		case 3: //Browse
			break;
		case 4: // Review Cart: Delete item from Shopping Cart or Checkout
			
			review.review(cart);
			
			break;
		case 5: //Edit profile
			break;
		case 6: //Edit Catalog
			bool adminBool = accountArray[accountNumber].getAdmin();
			if (adminBool == true) {
				//make sure the header file with the modify catalogue menu is included and
				//just call it here.
			}
			else {
				cout << "\nYou are NOT logged in as Admin.\n";
			}
			break;
		default:
			break;
		}
	} while (mainchoice != 0);
	system("pause");
	return 0;
}