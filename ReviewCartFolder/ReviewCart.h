#pragma once
/*
a) Review Cart
b) 7 / 28 / 2018
c) Simon Lee
d) Deletes a single item or checkouts from cart
e)  none
f)  none
*/
#include <iostream>
#include <string>
#include "Payment.h"
#include "CreditCard.h"
#include "ShoppingCart.h"
#include "Shipping.h"
#include "Discount.h"
class ReviewCart {

private:
	int reviewChoice;
	//ShoppingCart cart;
	Payment payment;
	Shipping shipping;
	Discount discount;
	int deleteChoice; //for deleting item from cart
	int orderChoice;	//for payment, shipping, discount or confirm 
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
	void review(ShoppingCart& cart_) {
		do {
			std::cout << "Select:\n1.Delete item from cart\n2.Checkout cart\n";
			std::cin >> reviewChoice;
			switch (reviewChoice) {
			case 1:
				
				cart_.displayItems();
				std::cout << "Which item do you want to delete from cart\n";
				std::cin >> deleteChoice;
				cart_.deleteItem(deleteChoice);
				std::cout << "Cart updated\n";
				cart_.displayItems();
				break;
			case 2:
				do {
					std::cout << "Please fill out order\n1.Payment\n2.Shipping\n3.Discount\n4.Confirm\n5.Cancel";
					std::cin >> orderChoice;
					switch (orderChoice) {
					case 1://Payment
						payment.addInfo();
						break;
					case 2://Shipping
						shipping.addInfo();
						shipping.addShippingToPrice(cart_);
						std::cout << "updatedprice " << cart_.getTotalPrice();
						break;
					case 3://Discount
						discount.addPromoCode(cart_);
						break;
					case 4://Confirm
						//std::cout << "Price = " << cart_.getTotalPrice();
						//payment.displayPayment();
						//shipping.display();
						std::cout << "An order confirmation has been sent to your email\n";
						cart_.empty();
						reviewChoice = 0;
						break;
					case 5://Cancel
						reviewChoice = 0;
						break;
					}

				} while (orderChoice != 4 && orderChoice != 5);
			}
		} while (reviewChoice != 0);
	}
	
	
};