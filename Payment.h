#pragma once
#include <iostream>
#include <string>
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