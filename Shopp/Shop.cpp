#include "Shop.h"
#include <iostream>

//shop constructor
Shop::Shop(string name,int money)
{
	_name = name;
	_money = money;
}

void Shop::printshop()
{
	cout << "***** welcome to " << _name << " ****" << endl<<endl;
	cout << "Money: " << _money << " GP" << endl << endl;
	list<Item>::iterator it;
	int i = 1;
	for (it = _items.begin(); it != _items.end(); it++) {
		cout << i << "." << (*it).getname() << " X" << (*it).getcount() <<" Price: "<<(*it).getvalue()<<" GP"<< endl;
		i++;
	}
	cout << endl;
}

bool Shop::canafforditem(string name, int money)
{
	list<Item>::iterator it;
	for (it = _items.begin(); it != _items.end(); it++) {
		if ((*it).getname() == name) {
			if ((*it).getvalue() <= money) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

// get item for purchase !
bool Shop::purchaseitem(string name,Item &newitem)
{
	list<Item>::iterator it;
	for (it = _items.begin(); it != _items.end(); it++) {
		if ((*it).getname() == name) {
		    newitem = (*it);
			newitem.setcount(1);

			(*it).removeone();
			if ((*it).getcount() == 0) {
				_items.erase(it);
			}
			return true;
		}
	}
	return false;
}

void Shop::additem(Item newitem)
{
	list<Item>::iterator it;
	for (it = _items.begin(); it != _items.end(); it++) {
		if ((*it).getname() == newitem.getname()) {
			(*it).addone();
			return;
		}
	}
	_items.push_back(newitem);
}

