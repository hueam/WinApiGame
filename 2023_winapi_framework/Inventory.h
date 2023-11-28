#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

public:
	void SetInventory(int size);

public:
	void SelectItem(const Item& item);
	void UseItem(int idx);
	//void UseItem(const Item& item);

private:
	vector<Item> invenItems; // or using map
	int itemCnt = 0; // current item cnt
};
