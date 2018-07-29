#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "ReviewCartFolder/ShoppingCart.h"
using namespace std;
item catalogue[50];
int numCatalogItems = 0;

void DisplayCatalogue(item catalogue[], int size)
{
	cout << "Name" << setw(15) << "Category" << setw(15) << "Quantity" << setw(15) << "Serial Number" << setw(15) << "Price" << endl;
	for (int i = 0; size > i; i++)
	{
		cout << catalogue[i].getName() << setw(15);
		cout << setw(15) << catalogue[i].getCategory();
		cout << setw(15) << catalogue[i].getQuantity();
		cout << setw(15) << catalogue[i].getSerial();
		cout << setw(15) << catalogue[i].getPrice() << endl;
	}
}

item AddItemToCatalogue()
{
	item catalogue;
	string temp;
	int itemp;
	double dtemp;
	cout << endl << "Enter the new item's Name followed by it's Category followed by it's Quantity followed by it's Serial Number followed by it's Price" << endl;
	cin >> temp;
	catalogue.setName(temp);
	cin >> temp;
	catalogue.setCatagory(temp);
	cin >> itemp;
	catalogue.setPrice(itemp);
	cin >> itemp;
	catalogue.setQuantity(itemp);
	cin >> dtemp;
	catalogue.setSerial(dtemp);
	return catalogue;
}