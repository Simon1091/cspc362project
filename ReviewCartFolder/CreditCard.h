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
	std::string expDate;
	std::string cardHolderName;
public:
	CreditCard(std::string cardNumber, int cwid, std::string expDate, std::string cardHolderName) {
		cardNumber = this->cardNumber;
		cwid = this->cwid;
		expDate = this->expDate;
		cardHolderName = this->cardHolderName;
	}
	std::string getcardNumber() {
		return cardNumber;
	}
	std::string getcardHolderName() {
		return cardHolderName;
	}
	std::string getexpDate() {
		return expDate;
	}
	int getcwid() {
		return cwid;
	}
	void setcardNumber(std::string cardNumber) {
		cardNumber = this->cardNumber;

	}
	void setcwid(int cwid) {
		cwid = this->cwid;

	}
	void setexpirationDate(std::string expDate) {
		expDate = this->expDate;

	}
	void setnameOfOwner(std::string cardHolderName) {
		cardHolderName = this->cardHolderName;
	}

};