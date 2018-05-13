#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Shop
{
public:
	Shop(string name,int money);
	void printshop();
	bool canafforditem(string name, int money);

	bool purchaseitem(string name, Item &newitem);
	void additem(Item newitem);

	void addmoney(int money) { _money += money; }
	int getmoney() { return _money; }
	string getname() { return _name; }

private:
	string _name;
	list<Item> _items;
	int _money;
};
