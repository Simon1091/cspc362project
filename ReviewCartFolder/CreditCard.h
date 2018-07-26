#pragma once
#include <string>
/*
a) Module name or Class name in the Design
b) Date of the code
c) Programmer's name
d) Brief  description of the class / service / function
e)  Any important data structure in class / functions
f)  choice of a specific algorithm within service / function
e.g.choosing quick sort rather than bubble sort etc.
*/
class CreditCard {
private:
	std::string cardNumber;
	int cwid;
	std::string expirationDate;
	std::string cardHolderName;
public:
	void setcardNumber(std::string cardNumber) {
		cardNumber = this->cardNumber;

	}
	void setcwid(int cwid) {
		cwid = this->cwid;

	}
	void setexpirationDate(std::string expirationDate) {
		expirationDate = this->expirationDate;

	}
	void setnameOfOwner(std::string cardHolderName) {
		cardHolderName = this->cardHolderName;
	}

};