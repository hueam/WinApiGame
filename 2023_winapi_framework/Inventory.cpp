#include "pch.h"
#include "Inventory.h"
#include "InventoryUI.h"
#include "SceneUi.h"
#include "Core.h"

//Inventory::Inventory()
//{
//}
//
//Inventory::~Inventory()
//{
//	invenItems.clear();
//}

void Inventory::SelectItem(Item* item)
{
	// if() item->itemType != END
	invenItems.push_back(item);
	SceneUI::AddDontDestroyUI(item,UI_RENDER_ORDER::ITEM);
	++itemCnt;
}

void Inventory::UseItem(int idx) // 클릭된 인벤 idx 받아오기
{
	if (idx >= 0 && idx < itemCnt)
	{
		delete invenItems[idx];
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