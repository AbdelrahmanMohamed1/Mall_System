#pragma once
#include <string>

using namespace std;

class Item
{
public:
	//constructor
	Item(string name,int value);

	void addone();
	void removeone();


	string getname() { return _name; }
	int getvalue() { return _value; }
	int getcount() { return _count; }
	
	void setcount(int count) { _count = count; }

private:
	string _name;
	int _value;
	int _count;
};
