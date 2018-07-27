#pragma once
#include <iostream>
#include <string>
#include "CreditCard.h"
#include "ShoppingCart.h"
class Payment {
private:
	std::string name;
	ShoppingCart cart;
	//CreditCard card;
	std::string cardNum;
	std::string expdate;
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
	std::string getPaymentname() {
		return name;
	}
	std::string getExpDate() {
		return expdate;
	}
	void addInfo() {
		std::cout << "Please add name\n";
		std::cin >> name;
		std::cout << "Please add card number\n";
		std::cin >> cardNum;
		std::cout << "Please input cwid\n";
		std::cin >> cwid;
		std::cout << "Please add expiration date\n";
		std::cin >> expdate;
		std::cout << "Please add billing address\n";
		std::cin >> billingAddress;
		

	}
};


