#pragma once
#include "Object.h"
class Texture;
class Board :
    public Object
{
	const wstring name = L"화이트보드";
public:
	Board();
	~Board();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

