#pragma once
#include "Object.h";
class Texture;
class Item :
	public Object
{
public:
	Item();
	~Item();
public:
	void Update() override;
	void Render(HDC _dc) override;
protected:
	Texture* m_pTex;
	ITEM_TYPE m_itmeType;
};

