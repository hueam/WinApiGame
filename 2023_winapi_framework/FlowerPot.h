#pragma once
#include "Object.h"

class Texture;
class FlowerPot :
    public Object
{
public:
    FlowerPot();
    ~FlowerPot();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void EnterCollision() override;
    void ExitCollision() override;
private:
    bool isEnter;
    Texture* m_pTex;
};

