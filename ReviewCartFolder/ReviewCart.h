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
#include "ShoppingCart.h"
#include <iomanip>
#include <limits>

#include "Shipping.h"
#include "Discount.h"
class ReviewCart {

private:
	bool isCartEmpty;
	bool isIncomplete;
	int reviewChoice;
	bool paymentDone;
	bool shippingDone;
	Payment payment;
	Shipping shipping;
	Discount discount;
	int deleteChoice; //for deleting item from cart
	int orderChoice;	//for payment, shipping, discount or confirm 
public:
	ReviewCart() {
		isCartEmpty = true;
		isIncomplete = true;
		paymentDone = false;
		shippingDone = false;
	}
	void review(ShoppingCart& cart_) {
		if (cart_.getCartSize() == 0) {
			isCartEmpty = true;
		}
		else
			isCartEmpty = false;
		//is there items in the cart? if not then go back to main screen
		if (isCartEmpty == true) {
			std::cout << "Cart is empty please go back and add an item\n";
		}
		else {
			do {
				std::cout << "\n----------------Review Cart-----------------\n";
				std::cout << "Total Price : $"  << cart_.getTotalPrice() << "\n";
				std::cout << "Select:\n1.Delete item from cart\n2.Checkout cart";
				std::cout << "\n---------------------------------------------\n Enter: ";
				std::cin >> reviewChoice;
				switch (reviewChoice) {
				case 1:
						std::cout << "\n----------------Deletion-----------------\n";
						cart_.displayItems();
						std::cout << "\n-----------------------------------------\n";
						std::cout << "Which item do you want to delete from cart\nEnter: ";
						std::cin >> deleteChoice;
						cart_.deleteItem(deleteChoice);
						std::cout << "Cart updated\n";
						cart_.displayItems();
						reviewChoice = 0;
						
					break;
				case 2:
						do {
							std::cout << "\n----------------Checkout-----------------\n";
							std::cout << "Choose from 1-5:\n1.Payment\n2.Shipping\n3.Discount\n4.Confirm\n5.Cancel";
							std::cout << "\n-----------------------------------------\n Enter: ";
							std::cin >> orderChoice;
							switch (orderChoice) {
							case 1://Payment
								payment.addInfo();
								paymentDone = true;
								break;
							case 2://Shipping
								shipping.addInfo();
								shipping.addShippingToPrice(cart_);
								std::cout << "updatedprice " << cart_.getTotalPrice() << "\n";
								shippingDone = true;
								break;
							case 3://Discount
								discount.addPromoCode(cart_);
								break;
							case 4://Confirm
								if (paymentDone == false) {
									std::cout << "\n ERROR: Please finish payment\n";
									isIncomplete = true;
								}
								if (shippingDone == false) {
									std::cout << "\n ERROR: Please finish shipping\n";
									isIncomplete = true;
							
								}
								else {
									isIncomplete = false;
									std::cout << "Total Price = $" << cart_.getTotalPrice() << "\n";
									payment.displayPayment();
									shipping.display();
									std::cout << "An order confirmation has been sent to your email\n";
									cart_.empty();
									payment.resetPayment();
									paymentDone = false;
									shippingDone = false;
									shipping.reset();
									discount.reset();
									reviewChoice = 0;
								}
								std::cout << "\n------------------------------------------\n";
								break;
							case 5://Cancel
								paymentDone = false;
								shippingDone = false;
								isIncomplete = false;
								reviewChoice = 0;
								payment.resetPayment();
								shipping.reset();
								discount.reset();
								break;
							}

						} while (orderChoice != 4 && orderChoice != 5 || isIncomplete != false);
					
				}
			} while (reviewChoice != 0);
			
		}
	}
	
};