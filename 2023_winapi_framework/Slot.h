#pragma once
#include "UIObject.h"

class Texture;
class Slot :
    public UIObject
{
public:
    Slot();
    ~Slot();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void EnterCollision() override;
    void ExitCollision() override;
private :
    bool isEnter;
    Texture* SlotTexture;
    Texture* SelectSlotTexture;
};

