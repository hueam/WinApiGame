#pragma once
#include "Object.h"

class Locker;
class Texture;
class WaterBottle :
    public Object
{
public:
    WaterBottle();
    ~WaterBottle();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void SetOwner(Locker* locker) { m_pOwnerLocker = locker; }
public:
    void EnterCollision() override;
    void ExitCollision() override;
private:
    Locker* m_pOwnerLocker;
    bool isEnter;
    Texture* m_pTex;
};

