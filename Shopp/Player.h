#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Player
{
public:
	Player();

	void init(string name, int money);

	void printinvintory();
	bool canafforditem(string name, int money);

	bool removeitem(string name, Item &newitem);
	void additem(Item newitem);
	
	void addmoney(int money) { _money += money; }
	int getmoney() { return _money; }
	void subtractmoney(int amount) { _money -= amount; }
	
private:
	string _name;
	int _money;
	list<Item> _items;
};
