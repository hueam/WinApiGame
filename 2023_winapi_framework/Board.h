#pragma once
#include "Object.h"
class Texture;
class Board :
    public Object
{
	const wstring name = L"ȭ��Ʈ����";
public:
	Board();
	~Board();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

