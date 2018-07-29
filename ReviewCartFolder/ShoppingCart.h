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
	double priceTimesQuantity;
public:
	item(std::string name_,std::string category_,int quantity_,int serial_,double price_) {
		name = name_;
		category = category_;
		quantity = quantity_;
		serial = serial_;
		price = price_;
		priceTimesQuantity = price * quantity;
	}
	
	std::string getName() {
		return name;
	}
	std::string getCategory() {
		return category;
	}
	int getQuantity() {
		return quantity;
	}
	int getSerial() {
		return serial;
	}
	double getPrice() {
		
		return priceTimesQuantity;
	}
	void setName(std::string name_)
	{
		name = name_;
	}
	void setCatagory(std::string catagory_)
	{
		category = catagory_;
	}
	void setQuantity(int quantity_)
	{
		quantity = quantity_;
	}
	void setSerial(int serial_)
	{
		serial = serial_;
	}
	void setPrice(double price_)
	{
		price = price_;
	}
};
class ShoppingCart {
private:
	double totalPrice;
	std::vector<item> items;
public:
	ShoppingCart(){
		totalPrice = 0;
	}
	int getCartSize() {
		return (int)items.size();
	}
	void addItem(item item) {
		items.push_back(item);
		totalPrice += item.getPrice();
	}
	double getTotalPrice() {
		
		return totalPrice;
	}
	void setTotalPrice(double updatedPrice) {
		totalPrice = updatedPrice;
	}
	void deleteItem(int i) {
		int n = i - 1;
		totalPrice -= items[n].getPrice();
		items.erase(items.begin() + n);
		
	}
	void empty() {
		for (int a = 0; a < items.size();a++) {
			items.pop_back();
		}
		totalPrice = 0;
	}
	void displayItems() {
		int count = 1;
		for (item i : items) {
			std::cout << count << ". ";
			std::cout << i.getName() << " ";
			std::cout << i.getPrice() << "";
			std::cout << i.getQuantity() << "";
			std::cout << i.getSerial() << "\n";

		}
	}
};