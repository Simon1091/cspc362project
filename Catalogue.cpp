#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class item {
	public:
		string name;
		string category;
		int quantity;
		int serial;
		double price;

};

void DisplayCatalogue(item catalogue[], int size)
{
	cout << "Name" << setw(15) << "Category" << setw(15) << "Quantity" << setw(15) << "Serial Number" << setw(15) << "Price" << endl;
	for (int i = 0; size > i; i++)
	{
		cout << catalogue[i].name << setw(15);
		cout << setw(15) << catalogue[i].category;
		cout << setw(15) << catalogue[i].quantity;
		cout << setw(15) << catalogue[i].serial;
		cout << setw(15) << catalogue[i].price << endl;
	}
}

item AddItemToCatalogue()
{
	fstream myfile;
	item catalogue;
	cout << endl << "Enter the new item's Name followed by it's Category followed by it's Quantity followed by it's Serial Number followed by it's Price" << endl;
	cin >> catalogue.name;
	cin >> catalogue.category;
	cin >> catalogue.quantity;
	cin >> catalogue.serial;
	cin >> catalogue.price;
	return catalogue;
}

int main() {
	item catalogue[50];
	fstream myfile;
	string line;
	int x = 0;

	myfile.open("Catalogue.txt");
	while (myfile >> line)
	{
		catalogue[x].name = line;
		myfile >> line;
		catalogue[x].category = line;
		myfile >> line;
		catalogue[x].quantity = stoi(line);
		myfile >> line;
		catalogue[x].serial = stoi(line);
		myfile >> line;
		catalogue[x].price = stod(line);
		x++;
	}
	int size = x;
	myfile.close();

	DisplayCatalogue(catalogue, size);
	catalogue[x + 1] = AddItemToCatalogue();
	size++;
	myfile.open("Catalogue.txt", ios::out | ios::app);
	myfile << catalogue[x+1].name << "/t";
	myfile << catalogue[x+1].category << "/t";
	myfile << catalogue[x+1].quantity << "/t";
	myfile << catalogue[x+1].serial << "/t";
	myfile << catalogue[x+1].price << "/t" << "/n";
	myfile.close();
	return 0;
}