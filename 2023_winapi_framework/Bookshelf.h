#pragma once
#include "Object.h"
class Texture;
class Bookshelf :
    public Object
{
	const wstring name = L"å��";
public:
	Bookshelf();
	~Bookshelf();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

