#pragma once
/*
a)DIscount 
b) 7 / 28 / 2018
c) Simon Lee
d) Add discount and apply it to total price
e)  none
f)  none
*/
#include <iostream>
#include <string>

class Discount {
private:
	std::string promocodes[3] = { "20%OFF", "50%OFF", "70%OFF" };
	std::string promocodeInput;
	double priceDeduction;
public:
	Discount() { promocodeInput = "";
	}
	void addPromoCode(ShoppingCart& cart_) {
		std::string userInput;
		std::cout << "Enter promocode\n";
		std::cin >> promocodeInput;
		if (promocodeInput == promocodes[0]) {
			priceDeduction = .2;
		}
		else if (promocodeInput == promocodes[1]) {
			priceDeduction = .5;
		}
		else if (promocodeInput == promocodes[2]) {
			priceDeduction = .7;
		}
		else {
			priceDeduction = 0;
		}
		cart_.setTotalPrice(cart_.getTotalPrice() - (cart_.getTotalPrice() * priceDeduction));
	}
	double getPriceDeduction() {
		return priceDeduction;
	}
	void reset() {
		promocodeInput = "";
	}
};