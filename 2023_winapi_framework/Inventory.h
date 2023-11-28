#pragma once
#include "Item.h"

class Inventory
{
	SINGLE(Inventory);

public:
	vector<Item> GetCurrentInventory() { return invenItems; }

public:
	void SelectItem(const Item& item);
	void UseItem(int idx);
	//void UseItem(const Item& item);

private:
	vector<Item> invenItems; // or using map
	int itemCnt = 0; // current item cnt
};
