#pragma once
#include <iostream>
#include <string>
#include "Payment.h"

void checkout() {
	int orderChoice;
	do {
		std::cout << "Please fill out order\n1.Payment\n2.Shipping\n3.Discount\n4.Confirm";
		switch (orderChoice) {
		case 1://Payment
			break;
		case 2://Shipping
			break;
		case 3://Discount
			break;
		case 4://Confirm

		}

	} while (orderChoice != 4);
}
//Payment
void printMessage() {
	std::cout << "Please add credit/debit card Info";
}
//Shipping
//Discount
//OrderConfirmation