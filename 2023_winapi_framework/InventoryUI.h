#pragma once
#include "UIObject.h"
#include "Inventory.h"
class Item;
class InventoryUI :
    public UIObject
{
private:
    InventoryUI();
    ~InventoryUI();
public:
    void Update() override;
    void Render(HDC _dc) override;

public:
    void ScrollUp();
    void ScrollDown();

public:
    void SetItems() { currentItem = Inventory::GetInst()->GetCurrentInventory(); }

private:
    vector<Item> currentItem;

private:
    int maxItemCnt = 5; // max item cnt
    int scrollCnt = 0; // scroll cnt
};

