#pragma once
#include <iostream>
#include <string>
#include "Payment.h"
#include "CreditCard.h"
#include "ShoppingCart.h"
class ReviewCart {

private:
	ShoppingCart cart;
	Payment payment;
public:
	void deleteItem() {

	}
	void checkout() {
		int orderChoice;

		do {
			std::cout << "Please fill out order\n1.Payment\n2.Shipping\n3.Discount\n4.Confirm";
			switch (orderChoice) {
			case 1://Payment
				payment.addInfo();



				break;
			case 2://Shipping
				break;
			case 3://Discount
				break;
			case 4://Confirm

			}

		} while (orderChoice != 4);
	}
};