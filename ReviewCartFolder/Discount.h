#pragma once
#include <iostream>
#include <string>

class Discount {
private:
	std::string promocodes[3] = { "20%OFF", "50%OFF", "70%OFF" };
	std::string promocodeInput;
	double priceDeduction;
public:
	Discount() {}
	void addPromoCode() {
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
	}
	double getPriceDeduction() {
		return priceDeduction;
	}
};