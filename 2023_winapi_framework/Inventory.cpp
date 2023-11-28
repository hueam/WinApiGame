#include "pch.h"
#include "Inventory.h"

void Inventory::SelectItem(const Item& item)
{
	// if() item->itemType != END
	invenItems.push_back(item);
	++itemCnt;
}

void Inventory::UseItem(int idx) // add item in the inven Index
{
	if (idx >= 0 && idx < itemCnt)
	{
		invenItems.erase(invenItems.begin() + idx);
		--itemCnt;
	}
}

//void Inventory::UseItem(const Item& item)
//{
//	auto iter = std::find(items.begin(), items.end(), item); //find item
//	if (iter != items.end())
//	{
//		items.erase(iter); // erase
//	}
//}