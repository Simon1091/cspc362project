#pragma once
#pragma once
#include <iostream>
#include <string>
#include "ReviewCartFolder\ShoppingCart.h"
#include <fstream>
void browseCatalog(ShoppingCart& cart_) {
	item temp;
	std::vector<item> catalog;
	int itemChoice;
	int quantityChoice;
	int browseChoice;
ifstream file;
ofstream outputFile;
	
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
						catalog.push_back(temp);
						
					}
				}
				for (item i : catalog) {
					cout <<  i.getSerial() << ". " << "name: " << i.getName() << endl;
					cout << "category: " << i.getCategory() << endl;
					cout << "quantity: " << i.getQuantity() << endl;
					cout << "price: " << i.getPrice() << endl;
					cout << endl;
				}
			}
			file.close();
			break;
		case 2:
			std::cout << "Enter the item number to add item to cart\n";
			std::cin >> itemChoice;

			std::cout << "Select quantity?";
			std::cin >> quantityChoice;
			if (quantityChoice > catalog[itemChoice - 1].getQuantity()) {
				std::cout << "too much\n";
			}
			else if (quantityChoice == 0) {
				std::cout << "please input an number higher than zero";
			}
			else {
				outputFile.open("Catalog.txt", ios::trunc);
				item chosenItem = catalog[itemChoice - 1];
				chosenItem.setQuantity(quantityChoice);
				cart_.addItem(chosenItem);
				int updatedQuantity = catalog[itemChoice - 1].getQuantity() - quantityChoice;
				if (updatedQuantity == 0) {
					
					catalog.erase(catalog.begin() + (itemChoice- 1));
					for (item i : catalog) {
						
							outputFile << i.getName() << "\n";
							outputFile << i.getCategory() << "\n";
							outputFile << to_string(i.getQuantity()) << "\n";
							outputFile << to_string(i.getSerial()) << "\n";
							outputFile << to_string(i.getPrice()) << "\n";
							outputFile << "\n";
						
					}
					
				}
				else {
					catalog[itemChoice - 1].setQuantity(updatedQuantity);
				

					for (item i : catalog) {
						outputFile << i.getName() << "\n";
						outputFile << i.getCategory() << "\n";
						outputFile << to_string(i.getQuantity()) << "\n";
						outputFile << to_string(i.getSerial()) << "\n";
						outputFile << to_string(i.getPrice()) << "\n";
						outputFile << "\n";
					}
					
				}
			}
			break;
		case 3:
			break;
		}
	} while (browseChoice != 3);


}

