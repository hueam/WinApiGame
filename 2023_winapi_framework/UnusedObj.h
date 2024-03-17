#pragma once
#include "Object.h"
class Texture;
class UnusedObj :
    public Object
{
    wstring objName = L"";
public:
    UnusedObj(wstring name);
    ~UnusedObj();

public:
    void EnterCollision() override;
    void ExitCollision() override;
    void Render(HDC _dc) override;

private:
    bool isEnter;
    Texture* m_pTex;
};

