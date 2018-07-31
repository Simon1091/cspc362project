/*CPSC 362 Project - Accounts
by Derek Dorr
7/25/18
Idea: When registering a new user, they are added to an user class*/
#pragma once

#include <iostream>
#include <string>
using namespace std;

const int NUM = 5; //number of users for demo

class UserAccount
{
private:
	string user_name = "";
	string email_address;
	string password;
	string street_address;
	int credit_card_number = 0;
	bool isAdmin = false;

	//admin info
	//un = admin
	//pw = admin

public:
	void setName(string);
	string getName();
	void setEmail(string);
	string getEmail();
	void setPwd(string);
	string getPwd();
	void setStrtAdrs(string);
	string getStrtAdrs();
	void setCardNum(int);
	int getCardNum();
	void setAdmin();
	bool getAdmin();

	void printInfo() {
		cout << "\nName: " << getName() << "\n" << "Email: " << getEmail() << "\n"
			<< "Password: " << getPwd() << "\n" << "Address: " << getStrtAdrs() << "\n"
			<< "Credit Card Number: " << getCardNum() << "\n";
	}
};

void UserAccount::setName(string n) {
	user_name = n;
}

void UserAccount::setEmail(string e) {
	email_address = e;
}

void UserAccount::setPwd(string p) {
	password = p;
}

void UserAccount::setStrtAdrs(string a) {
	street_address = a;
}

void UserAccount::setCardNum(int c) {
	credit_card_number = c;
}

string UserAccount::getName() {
	return user_name;
}

string UserAccount::getEmail() {
	return email_address;
}

string UserAccount::getPwd() {
	return password;
}

string UserAccount::getStrtAdrs() {
	return street_address;
}

int UserAccount::getCardNum() {
	return credit_card_number;
}

void UserAccount::setAdmin() {
	isAdmin = true;
}

bool UserAccount::getAdmin() {
	return isAdmin;
}