#pragma once
#include "Object.h"

class Texture;
class BackGround :
    public Object
{
public:
    BackGround(wstring key, wstring name);
    ~BackGround();
public :
    void Render(HDC _dc) override;
private:
    Texture* m_pTex;
};

