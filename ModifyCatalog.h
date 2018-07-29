#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ReviewCartFolder/ShoppingCart.h"
#include "Catalogue.h"
using namespace std;
class ModifyCatalog
{
public:
	void addItem(item cat_item)
	{
		//Add item to catalog array and to end of doc
		ofstream cat_file;
		cat_file.open("Catalogue.txt", ios::app);
		cat_file << cat_item.getName() << '\t' << cat_item.getCategory() << '\t' <<
			cat_item.getQuantity() << '\t' << cat_item.getSerial() << '\t' << cat_item.getPrice() << '\n';
		cat_file.close();
		catalogue[numCatalogItems].setName(cat_item.getName());
		catalogue[numCatalogItems].setCatagory(cat_item.getCategory());
		catalogue[numCatalogItems].setQuantity(cat_item.getQuantity());
		catalogue[numCatalogItems].setSerial(cat_item.getSerial());
		catalogue[numCatalogItems].setPrice(cat_item.getPrice());
		numCatalogItems++;
	}

	void deleteItem(string name)
	{
		//Search through catalog array and delete item from catalog
		//Search through doc and delete item from doc
		size_t pos;
		fstream cat_file;
		cat_file.open("Catalogue.txt");
		string line, file;
		while (getline(cat_file, line))
		{
			pos = line.find(name);
			if (pos == string::npos)
				file.append(line);
		}
		cat_file << file;
		
		cat_file.seekg(0, ios::beg);
		while (cat_file >> line)
		{
			catalogue[numCatalogItems].setName(line);
			cat_file >> line;
			catalogue[numCatalogItems].setCatagory(line);
			cat_file >> line;
			catalogue[numCatalogItems].setQuantity(stoi(line));
			cat_file >> line;
			catalogue[numCatalogItems].setSerial(stoi(line));
			cat_file >> line;
			catalogue[numCatalogItems].setPrice(stoi(line));
			numCatalogItems++;
		}
		cat_file.close();
	}
};