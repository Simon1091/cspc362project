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
	std::string pinNum;
	std::string billingAddress;
	
public:
	Payment() {
		name = "";
		cardNum = "";
		expdate = "";
		billingAddress = "";
		pinNum = "";
	}
	std::string getcardNum() {
		return cardNum;
	}
	std::string getBillingAddress() {
		return billingAddress;

	}
	std::string getPin() {
		return pinNum;
	}
	std::string getPaymentname() {
		return name;
	}
	std::string getExpDate() {
		return expdate;
	}
	void setName(std::string name_) {
		name = name_;
	}
	void setbillingAddress(std::string billingAddress_) {
		billingAddress = billingAddress_;
	}
	void setCardNum(std::string cardNum_) {
		cardNum = cardNum_;
	}
	void setExpDate(std::string expDate_) {
		expdate = expDate_;
	}
	void setCwid(std::string pinNum_) {
		pinNum = pinNum_;
	}

	void resetPayment() {
		billingAddress = "";
		name = "";
		pinNum = "";
		cardNum = "";
		expdate = "";
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
		
		std::cout << "Please input pinNum\n";
		while (pinNum == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding pinNum\n";
			}
			else
				pinNum = userInput;
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
		std::cout << "pinNum: " << pinNum << "\n";
		std::cout << "expiration date: " << expdate << "\n";
		std::cout << "Billing address: " << billingAddress << "\n";

	}
};


