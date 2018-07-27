#pragma once
#include <iostream>
#include <string>
#include "Payment.h"
#include "CreditCard.h"
#include "ShoppingCart.h"
#include "Shipping.h"
#include "Discount.h"
class ReviewCart {

private:
	ShoppingCart cart;
	Payment payment;
	Shipping shipping;
	Discount discount;
public:
	ReviewCart() {
		
	}

	std::string getPaymentCardNumber() {
		return payment.getcardNum();
	}
	int getPaymentCwid() {
		return payment.getcwid();

	}
	std::string getPaymentAddress() {
		return payment.getBillingAddress();
	}
	void deleteItem() {

	}
	void checkout() {
		int orderChoice;

		do {
			std::cout << "Please fill out order\n1.Payment\n2.Shipping\n3.Discount\n4.Confirm";
			std::cin >> orderChoice;
			switch (orderChoice) {
			case 1://Payment
				payment.addInfo();
				break;
			case 2://Shipping
				shipping.addInfo();
				break;
			case 3://Discount
				discount.addPromoCode();
				break;
			case 4://Confirm
				break;
			}

		} while (orderChoice != 4);
	}
};