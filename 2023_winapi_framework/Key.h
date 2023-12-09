#pragma once
#include "UIObject.h"

class TrashCanPopup;
class Key :
    public UIObject
{
public:
    Key(wstring key, wstring textureName, TrashCanPopup* newOwner);
    ~Key();
public :
    void Update() override;
    void Render(HDC _dc) override;
    void EnterCollision() override;
    void ExitCollision() override;
private :
    bool isEnter;
    TrashCanPopup* owner;
};

