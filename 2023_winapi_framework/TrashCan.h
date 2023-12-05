#pragma once
#include "Object.h"
class Texture;
class TrashCan :
    public Object
{
public:
    TrashCan();
    ~TrashCan();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void EnterCollision() override;
    void ExitCollision() override;
public:
    bool isEnter;
    Texture* m_pTex;
};

