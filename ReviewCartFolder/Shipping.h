#pragma once
/*
a) Shipping
b) 7 / 28 / 2018
c) Simon Lee
d) Add Shipping Information and display it
e)  none
f)  none
*/
#include <iostream>
#include <string>

class Shipping {
private:
	std::string name;
	double cost;
	std::string mailingAddress;
	int shippingChoice;
public:
	Shipping(){
		mailingAddress = "";
	}
	void addInfo() {
		std::string userInput;
		std::cout << "Please input your mailing address\n";
		while (mailingAddress == "") {
			std::cin.ignore();
			std::getline(std::cin, userInput);
			if (userInput == "") {
				std::cout << "Retry adding name\n";
			}
			else
				mailingAddress = userInput;
		}
		
		std::cout << "Select shipping method:\n1.Standard(7-12 days)\n2.Priority(1-2 days)\n3.Free(30 days)\n";
		std::cin >> shippingChoice;
		switch (shippingChoice) {
		case 1://Standard shipping: add shipping cost to total price
			name = "Standard Shipping(7-12 days)";
			cost = 5.00;
			break;
		case 2:
			name = "Priority Shipping(1-2 days)";
			cost = 9.00;
			break;
		case 3:
			name = "Free Shipping(30 days)";
			cost = 0.00;
			break;

		}
	
	}
	void addShippingToPrice(ShoppingCart& cart_) {
		std::cout << "cost : " << cost << "\n";
		double updatedPrice = cart_.getTotalPrice() + cost;
		cart_.setTotalPrice(updatedPrice);
	}
	void display() {
		std::cout << name << "\n";
		std::cout << "Mailing Address: " << mailingAddress << "\n";
	}
	void setshippingcost(double cost_) {
		cost = cost_;
	}
	double getshippingcost() {
		return cost;
	}
	std::string getShippingName() {
		return name;
	}
	std::string getmailingAddress() {
		return mailingAddress;
	}
	void reset() {
		mailingAddress = "";
	}
};