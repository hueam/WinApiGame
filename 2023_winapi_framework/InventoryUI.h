#pragma once
#include "UIObject.h"
#include "Inventory.h"
class UIObject;
class InventoryUI :
    public UIObject
{
public:
    InventoryUI();
    InventoryUI(wstring textureName);
    ~InventoryUI();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void Component_Render(HDC _dc) override;
public:
    void ScrollUp();
    void ScrollDown();
public:
    //void SetItems() { currentItem = Inventory::GetInst()->GetCurrentInventory(); }

private:
    vector<UIObject> vItem;

private:
    int maxItemCnt = 5; // max item cnt
    int scrollCnt = 0; // scroll cnt
};

