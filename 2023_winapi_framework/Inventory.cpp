#include "pch.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	invenItems.clear();
}

void Inventory::SetInventory(int size)
{
	//
}

void Inventory::SelectItem(const Item& item)
{
	// if() item->itemType != END
	invenItems.push_back(item);
	SetInventory(++itemCnt);
}

void Inventory::UseItem(int idx) // 클릭된 인벤 idx 받아오기
{
	if (idx >= 0 && idx < itemCnt)
	{
		invenItems.erase(invenItems.begin() + idx);
		SetInventory(--itemCnt);
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