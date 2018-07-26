#pragma once
#include <iostream>
#include <string>
#include "CreditCard.h"
#include "ShoppingCart.h"
class Payment {
private:
	ShoppingCart cart;
	CreditCard card;
	std::string cardNum;
	int cwid;
	std::string billingAddress;
	
public:
	std::string getcardNum() {
		return cardNum;
	}
	std::string getBillingAddress() {
		return billingAddress;

	}
	int getcwid() {
		return cwid;
	}
	
	void addInfo() {
		
		std::cout << "Please add card number\n";
		std::cin >> cardNum;
		std::cout << "Please input cwid\n";
		std::cin >> cwid;
		std::cout << "Please add billing address\n";
		std::cin >> billingAddress;
		

	}
};


