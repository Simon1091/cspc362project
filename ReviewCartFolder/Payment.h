#pragma once
/*
a) Payment
b) 7 / 28 / 2018
c) Simon Lee
d) Add payment information and displays it
e)  none
f)  none
*/
#include <iostream>
#include <string>

class Payment {
private:
	std::string name;
	
	
	std::string cardNum;
	std::string expdate;
	std::string cwid;
	std::string billingAddress;
	
public:
	Payment() {
		name = "";
		cardNum = "";
		expdate = "";
		billingAddress = "";
		cwid = "";
	}
	std::string getcardNum() {
		return cardNum;
	}
	std::string getBillingAddress() {
		return billingAddress;

	}
	std::string getcwid() {
		return cwid;
	}
	std::string getPaymentname() {
		return name;
	}
	std::string getExpDate() {
		return expdate;
	}
	void addInfo() {
		std::string userInput;
		std::cout << "Please add name\n";
		while (name == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding name\n";
			}
			else
				name = userInput;
		}
		
		std::cout << "Please add card number\n";
		while (cardNum == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding cardNumber\n";
			}
			else
				cardNum = userInput;
		}
		
		std::cout << "Please input cwid\n";
		while (cwid == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding CWID\n";
			}
			else
				cwid = userInput;
		}
		
		std::cout << "Please add expiration date\n";
		while (expdate == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding expiration date\n";
			}
			else
				expdate = userInput;
		}
		
		std::cout << "Please add billing address\n";
		while (billingAddress == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding billing address\n";
			}
			else
				billingAddress = userInput;
		}
		
		

	}
	void displayPayment() {
		std::cout << "CardHolder Name: " << name << "\n";
		std::cout << "Card Number: " << cardNum << "\n";
		std::cout << "cwid: " << cwid << "\n";
		std::cout << "expiration date: " << expdate << "\n";
		std::cout << "Billing address: " << billingAddress << "\n";

	}
};


