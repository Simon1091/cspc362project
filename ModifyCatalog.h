#pragma once
#include <iostream>
#include <string>
#include "ReviewCartFolder/ShoppingCart.h"
#include "Browse.h"
#include <fstream>
using namespace std;

//a) Modify Catalog
//b) 7/29
//c) Burke Masles
//d) Modifies the catalog if admin
//e) addItem, deleteItem
//f)  choice of a specific algorithm within service / function



void addItem(item cat_item)
{
	//Add item to catalog array and to end of doc
	ofstream cat_file;
	cat_file.open("Catalog.txt", ios::app);
	cat_file << '\n'  << '\n' << cat_item.getName() << '\n' << cat_item.getCategory() << '\n' <<
		cat_item.getQuantity() << '\n' << cat_item.getSerial() << '\n' << cat_item.getPrice();
	cat_file.close();
	/*catalogue[numCatalogItems].setName(cat_item.getName());
	catalogue[numCatalogItems].setCatagory(cat_item.getCategory());
	catalogue[numCatalogItems].setQuantity(cat_item.getQuantity());
	catalogue[numCatalogItems].setSerial(cat_item.getSerial());
	catalogue[numCatalogItems].setPrice(cat_item.getPrice());
	numCatalogItems++;*/
	catalog.push_back(cat_item);
}

void deleteItem(string name)
{
	//Search through catalog array and delete item from catalog
	//Search through doc and delete item from doc
	size_t pos;
	item temp;
	fstream cat_file;
	cat_file.open("Catalog.txt");
	string line, file;
	int counter = 0;
	while (getline(cat_file, line))
	{
		if (counter % 6 == 0)
		{
			pos = line.find(name);
			if (pos == string::npos)
				file.append(line + '\n');
			else
			{
				getline(cat_file, line);
				getline(cat_file, line);
				getline(cat_file, line);
				getline(cat_file, line);
				counter += 5;
			}
		}
		else file.append(line + '\n');
		counter++;
	}
	cat_file.close();
	ofstream out_cat_file("Catalog.txt", ios::trunc);
	out_cat_file << file;
	out_cat_file.close();
	cat_file.open("Catalog.txt");

	cat_file.seekg(0, ios::beg);
	catalog.erase(catalog.begin(), catalog.end());
	while (!cat_file.eof()) {
		if (cat_file.eof())
			break;
		getline(cat_file, line);
		if (line.size() == 0) {
			continue;
		}
		else {

			temp.setName(line);
			getline(cat_file, line);
			temp.setCatagory(line);
			getline(cat_file, line);
			temp.setQuantity(stoi(line));
			getline(cat_file, line);
			temp.setSerial(stoi(line));
			getline(cat_file, line);
			temp.setPrice(stod(line));
			catalog.push_back(temp);

		}
	}
	cat_file.close();
}

void modifyCatalog()
{
	//Main function for the modify catalog choice
	string tempS;
	cout << "Please select:\n";
	cout << "0. Add item to catalog\n";
	cout << "1. Delete item from catalog\n";
	cout << "2. Exit to main menu\n";
	int choice = -1;
	cin >> choice;
	if (choice == 0)
	{
		item addition;
		int tempI;
		double tempD;
		cout << "Please enter the name of the item: ";
		cin >> tempS;
		addition.setName(tempS);
		cout << endl << "Please enter the catagory of the item: ";
		cin >> tempS;
		addition.setCatagory(tempS);
		cout << endl << "Please enter the quantity of the item: ";
		cin >> tempI;
		addition.setQuantity(tempI);
		cout << endl << "Please enter the serial number of the item: ";
		cin >> tempI;
		addition.setSerial(tempI);
		cout << endl << "Please enter the price of the item: ";
		cin >> tempD;
		addition.setPrice(tempD);
		addItem(addition);
		cout << "Addition successful! Please make a selection: " << endl;
		cout << "0. Modify catalog" << endl;
		cout << "1. Exit to main menu" << endl;
		cin >> choice;
		if (choice == 0)
		{
			modifyCatalog();
			return;
		}
		else
		{
			cout << "Returning to main menu..." << endl;
			return;
		}
	}
	else if (choice == 1)
	{
		cout << "Please enter the name of the item: ";
		cin >> tempS;
		deleteItem(tempS);
		cout << "Deletion successful! Please make a selection: " << endl;
		cout << "0. Modify catalog" << endl;
		cout << "1. Exit to main menu" << endl;
		cin >> choice;
		if (choice == 0)
		{
			modifyCatalog();
			return;
		}
		else
		{
			cout << "Returning to main menu..." << endl;
			return;
		}
	}
	else
	{
		cout << "Returning to main menu..." << endl;
		return;
	}
}