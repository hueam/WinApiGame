#include "pch.h"
#include "Inventory.h"
#include "InventoryUI.h"
#include "SceneUi.h"
#include "Core.h"
#include "EventMgr.h"

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
	SceneUI::AddDontDestroyUI(item, UI_RENDER_ORDER::ITEM);
	++itemCnt;
}

void Inventory::DeleteItem(Item* item) // 클릭된 인벤 idx 받아오기
{
	for (int i = 0; i < invenItems.size(); i++)
	{
		if (invenItems[i] == item)
		{
			EventMgr::GetInst()->DeleteObject(invenItems[i]);
			invenItems.erase(invenItems.begin() + i);
			--itemCnt;
		}
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