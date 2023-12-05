#pragma once
#include "UIObject.h"
#include "Inventory.h"

class Slot;
class Texture;
class Scene;
class InventoryUI :
    public UIObject
{
public:
    InventoryUI();
    InventoryUI(wstring textureName);
    ~InventoryUI();
public:
    void Init(Vec2 pos, Vec2 scale);
    void Update() override;
    void Render(HDC _dc) override;
    void Component_Render(HDC _dc) override;
public:
    void ScrollUp();
    void ScrollDown();
public:
    //void SetItems() { currentItem = Inventory::GetInst()->GetCurrentInventory(); }
private:
    int xPadding = 20;
    int yPadding = 20;
    int maxItemCnt = 3; // max item cnt
    int scrollCnt = 0; // scroll cnt

};

