#pragma once
#include <iostream>
#include <string>

class Shipping {
private:
	std::string name;
	double cost;
	std::string mailingAddress;
	int shippingChoice;
public:
	Shipping(){}
	void addInfo() {
		std::cout << "Please input your mailing address\n";
		std::cin >> mailingAddress;
		
		std::cout << "Select shipping method:\n1.Standard(7-12 days)\n2.Priority(1-2 days)3.Free(30 days)\n";
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
	void setshippingcost(double cost) {
		cost = this->cost;
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
};