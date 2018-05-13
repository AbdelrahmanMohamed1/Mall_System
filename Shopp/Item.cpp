#include "Item.h"

//item constructor
Item::Item(string name, int value)
{
	_name = name;
	_value = value;
	_count = 1;
}
void Item::addone() {
	_count++;
}
void Item::removeone() {
	if (_count > 0) {
		_count--;
	}
}
