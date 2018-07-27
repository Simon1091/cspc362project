#pragma once
#include <iostream>
#include <string>
#include <vector>
class item {
private:
	std::string name;
	std::string category;
	int quantity;
	int serial;
	double price;
public:
	item() {}
	
	std::string getName() {
		return name;
	}
	std::string getcategory() {
		return category;
	}
	int getQuantity() {
		return quantity;
	}
	int getSerial() {
		return serial;
	}
	double getPrice() {
		price *= quantity;
		return price;
	}
};
class ShoppingCart {
private:
	double totalPrice;
	std::vector<item> items;
public:
	ShoppingCart(){}
	void addItem(item item) {
		items.push_back(item);
		totalPrice += item.getPrice();
	}
	double getTotalPrice() {
		
		return totalPrice;
	}
	void deleteItem(int i) {
		int n = i - 1;
		items.erase(items.begin() + n);
	
	}
	void displayItems() {
		for (item i : items) {
			std::cout << i.getName() << "\n";
			std::cout << i.getPrice() << "\n";
			std::cout << i.getQuantity() << "\n";
			std::cout << i.getSerial() << "\n";

		}
	}
};