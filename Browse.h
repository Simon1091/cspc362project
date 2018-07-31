#pragma once
#pragma once
#include <iostream>
#include <string>
#include "ReviewCartFolder\ShoppingCart.h"
#include "ModifyCatalog.h"
#include <fstream>
void browseCatalog(ShoppingCart& cart_) {
	item temp;
	//ModifyCatalog mc;
	int itemChoice;
	int quantityChoice;
	int browseChoice;
	ifstream file;
	string line;
	do {
		std::cout << "Select from 1-3:\n1. View Catalog\n2.Add Item\n3.Go back to Home Page\n";
		std::cin >> browseChoice;
		switch (browseChoice) {
		case 1:
			file.open("Catalog.txt",ios::in); 
			if (!file.is_open()) {
				cout << "Unable to open file\n";
			}
			else {
				cout << "reading file input" << endl;
				while (!file.eof()) {
					if (file.eof())
						break;
					getline(file, line);
					if (line.size() == 0) {
						continue;
					}
					else {
						
						temp.setName(line);
						getline(file, line);
						temp.setCatagory(line);
						getline(file, line);
						temp.setQuantity(stoi(line));
						getline(file, line);
						temp.setSerial(stoi(line));
						getline(file, line);
						temp.setPrice(stod(line));
						catalogue.push_back(temp);
						
					}
				}
				for (item i : catalogue) {
					cout <<  i.getSerial() << ". " << "name: " << i.getName() << endl;
					cout << "category: " << i.getCategory() << endl;
					cout << "quantity: " << i.getQuantity() << endl;
					cout << "price: " << i.getPrice() << endl;
					cout << endl;
				}
			}
			
			break;
		case 2:
			std::cout << "Enter the item number to add item to cart\n";
			std::cin >> itemChoice;

			std::cout << "Select quantity?";
			std::cin >> quantityChoice;
			if (quantityChoice > catalogue[itemChoice - 1].getQuantity()) {
				std::cout << "too much\n";
			}
			else if (quantityChoice == 0) {
				std::cout << "please input an number higher than zero";
			}
			else {
				item chosenItem = catalogue[itemChoice - 1];
				chosenItem.setQuantity(quantityChoice);
				cart_.addItem(chosenItem);
				int updatedQuantity = catalogue[itemChoice].getQuantity() - quantityChoice;
				if (updatedQuantity == 0) {
					//mc.deleteItem(catalogue[itemChoice].getName());
				}
				else {
					catalogue[itemChoice].setQuantity(updatedQuantity);
				}
			}
			break;
		case 3:
			break;
		}
	} while (browseChoice != 3);


}

