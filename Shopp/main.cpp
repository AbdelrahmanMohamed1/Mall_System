#include <iostream>
#include <string>
#include "Player.h"
#include "Shop.h"
using namespace std;
void initshops(list<Shop>&shops);
void initplayer(Player &player);
void entershop(Player &player, Shop &shop);
int main()
{
	list<Shop> shops;
	list<Shop>::iterator it;
	Player player;
	string shopname;
	char input;

	initplayer(player);
	initshops(shops);

	bool done = 1;
	while (done)
	{
		cout << "Shops: " << endl;
		int i = 1;
		for (it = shops.begin(); it != shops.end(); it++) {
			cout <<i<<". "<< (*it).getname() << endl;
			i++;
		}
		cout << "What shop would you like to enter? ";
		
		cin.ignore(64, '\n');
		cin.clear();
		getline(cin, shopname);
		cout << endl;


		bool validshop = 0;

		for (it = shops.begin(); it != shops.end(); it++) {
			if ((*it).getname() == shopname) {
				entershop(player, (*it));
				validshop = 1;
			}
		}
		if (validshop == 0) {
			cout << "Invalid shop! " << endl;
			system("PAUSE");
		}

	}


	cout << endl;
	system("PAUSE");
	return 0;
}

void initshops(list<Shop>&shops)
{
	shops.push_back(Shop("Bills leather shop", 500));
	shops.back().additem(Item("Leather Boots", 50));
	shops.back().additem(Item("Leather Hat", 50));
	shops.back().additem(Item("Leather Gloves", 50));
	shops.back().additem(Item("Leather Gauntlets", 50));
	shops.back().additem(Item("Leather chestpiece", 50));
	/************/
	shops.push_back(Shop("The Blacksmith", 1500));
	shops.back().additem(Item("Iron Boots", 100));
	shops.back().additem(Item("Iron Hat", 100));
	shops.back().additem(Item("Iron Gloves", 100));
	shops.back().additem(Item("Iron Gauntlets", 100));
	shops.back().additem(Item("Iron chestpiece", 200));
	shops.back().additem(Item("Iron sword", 150));
	shops.back().additem(Item("Iron shield", 150));
	/***************/
	shops.push_back(Shop("Beverly fruity shop",250));
	shops.back().additem(Item("Grapes", 5));
	shops.back().additem(Item("Apples", 5));
	shops.back().additem(Item("Oranges", 5));
	shops.back().additem(Item("Watermelon", 10));
	shops.back().additem(Item("tomato", 3));
}

void initplayer(Player &player)
{
	cout << "Enter the name sir knight: ";
	string name;
	cin >> name;
	player.init(name, 100);
	player.additem(Item("Bronze sword", 5));
}

void entershop(Player &player, Shop &shop)
{
	bool done = 1;
	char input;
	string itemname;
	Item newitem("NOITEM",0);

	while (done)
	{
		shop.printshop();
		player.printinvintory();
		cout << " would you like to buy or sell? Q to quit (B/S): ";
		cin >> input;
		cin.ignore(64, '\n');
		cin.clear();
		if (input == 'Q' || input == 'q')return;

		if (input == 'B' || input == 'b') {//buy
			cout << "Enter the item you wish to buy: ";
			getline(cin, itemname);
			if (shop.canafforditem(itemname, player.getmoney())){
				if (shop.purchaseitem(itemname, newitem) == true) {
					player.addmoney(-newitem.getvalue());
					player.additem(newitem);
					shop.addmoney(newitem.getvalue());
				}
				else {
					cout << "This is an invalid item! " << endl;
					system("PAUSE");
				}
			}
			else
			{
				cout << "You dont have enough money! "<<endl;
				system("PAUSE");
			}

		}
		else {// sell
			cout << "Enter the item you wish to sell: ";
			getline(cin, itemname);
			if (player.canafforditem(itemname, shop.getmoney())) {
				if (player.removeitem(itemname, newitem) == true) {
					shop.addmoney(-newitem.getvalue());
					shop.additem(newitem);
					player.addmoney(newitem.getvalue());
				}
				else
				{
					cout << "This is an invalid item! ";
					system("PAUSE");
				}
			}
			else
			{
				cout << "the shop doesnt have enough money! " << endl;
				system("PAUSE");
			}

		}
	}
}

