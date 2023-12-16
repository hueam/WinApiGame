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
public:
    const void SetSun(const bool value)
    {
        sun = value;
    }
    const void SetWater(const bool value)
    {
        water = value;
    }

private:
    bool isEnter;
    bool sun;
    bool water;
    Texture* m_pTex;
    Texture* m_pgGrow_One_Tex;
    Texture* m_pgGrow_Two_Tex;
};

