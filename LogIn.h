/*this is the log in page. To use, call logInMenu()
By: Derek Dorr
This IS the updated version*/
#include <iostream>
#include <string>
#include "Accounts.h"
using namespace std;

int logInMenu(UserAccount[]);
int logIntoExisting(UserAccount[]);
void registerNewUser(UserAccount[]);
void printDataBase(UserAccount[]);

//Global Vars
bool loggedIn = false;
UserAccount accountArray[NUM];//global account class, so it doesnt get re defined with each call-to from the homepage (just in case)


int logInMenu(UserAccount accountArray[]) {
	int menu_choice;
	int accountNumber;//this number gets passed to the body of the program since it identify's the logged in user

	 //initialize admin
	string adminUN = "admin";
	string adminPW = "admin";
	accountArray[0].setEmail(adminUN);
	accountArray[0].setPwd(adminPW);

	//Log in/out or Register Menu
	do {
		cout << "Do you already have an account?\n\t1) Log In\n"
			<< "If you do not have an account,\n\t2) Register\n";
		cin >> menu_choice;
		switch (menu_choice) {
		case 1:
			accountNumber = logIntoExisting(accountArray);
			break;
		case 2:
			registerNewUser(accountArray);
			break;
		default:
			cout << "\nInvalid Input\n";
		}
	} while (loggedIn == false);
	return accountNumber;
}

 //Log in to existing account
int logIntoExisting(UserAccount accountArray[]) {
	string user_email;
	string user_pwd;
	bool login_matches = false;
	char adminChoice;

	//Asking for log in info
	cout << "Log into existing account: \nAre you an admin? (y/n)\n";
	cin >> adminChoice;
	if (adminChoice == 'y') {
		cout << "Enter the admin username:\t";
		cin >> user_email;
		cout << "\nEnter the admin password:\t";
		cin >> user_pwd;
		cout << endl;
	}
	else {
		cout << "Enter your email address:\t";
		cin >> user_email;
		cout << "\nEnter your password:\t";
		cin >> user_pwd;
		cout << endl;
	}

	//Verifying Log in info
	int j = 0;
	do {
		if (accountArray[j].getEmail() == user_email  && accountArray[j].getPwd() == user_pwd) {
			login_matches = true;
			cout << "\nLogging In!\n";
		}
		else {
			j++;
		}
	} while (login_matches != true || j > NUM);
	if (login_matches == false) {
		cout << "Your email and password did not match any existing accounts.\n";
	}
	loggedIn = true;
	return j;//returning the account's position in the array.
}

//registers new users
void registerNewUser(UserAccount accountArray[]) {
	int array_pos = 0; // needs to be incremented to empty slot
	int myInt;
	string myString;
	char choice = 'a';

	while (accountArray[array_pos].getName() != "") { // finds an empty spot in the array
		array_pos++;
	}

	cout << "(1/5) Enter Name: ";
	cin >> ws;//consumes white space
	getline(cin, myString);
	accountArray[array_pos].setName(myString);
	cout << "\n(2/5) Enter Email: ";
	cin >> myString;
	accountArray[array_pos].setEmail(myString);
	cout << "\n(3/5) Enter Password: ";
	cin >> myString;
	accountArray[array_pos].setPwd(myString);
	cout << "\n(4/5) Enter your shipping address: ";
	cin >> ws;//consumes white space
	getline(cin, myString);
	accountArray[array_pos].setStrtAdrs(myString);
	cout << "\n(5/5) Enter your credit card number: ";
	cin >> myInt;
	accountArray[array_pos].setCardNum(myInt);

	cout << "\nYou have registered as user # " << array_pos + 1 << endl;
}

void printDataBase(UserAccount accountArray[]) {
	bool printOut = false;
	char printChoice;
	cout << "\nWould you like to display the user database? (y/n)\n";
	cin >> printChoice;

	if (printChoice == 'y') {
		//prints out each account info
		for (int i = 0; i < NUM; i++) {
			cout << "Account # " << i;
			accountArray[i].printInfo();
		}
	}
}