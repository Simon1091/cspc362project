#pragma once
#include <iostream>
#include <string>
#include "CreditCard.h"
#include "ShoppingCart.h"
class Payment {
private:
	ShoppingCart cart;
	CreditCard card;
	std::string billingAddress;
	std::string country;
	int zipcode;
public:

};


