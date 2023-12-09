#pragma once
#include "Item.h"

class InventoryUI;
class Inventory
{
	SINGLE(Inventory)
public:
	void SelectItem(Item* item);
	void DeleteItem(Item* item);
	vector<Item*> GetItemVector()
	{
		return invenItems;
	}
	//void UseItem(const Item& item);

private:
	vector<Item*> invenItems; // or using map
	int itemCnt = 0; // current item cnt
};

