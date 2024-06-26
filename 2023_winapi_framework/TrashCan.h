#pragma once
#include "Object.h"

class TrashCanPopup;
class Texture;
class TrashCan :
    public Object
{
public:
    TrashCan();
    ~TrashCan();
public:
    void FinalUpdate() override;
    void Render(HDC _dc) override;
    void EnterCollision() override;
    void ExitCollision() override;
private:
    bool isEnter;
    Texture* m_pTex;
    TrashCanPopup* m_pTrashCanPopup;
};

