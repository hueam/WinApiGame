#pragma once
#include "UIObject.h";
class Texture;
class Item
	: public UIObject
{
public:
	Item(ITEM_TYPE type, Texture* texture);
	~Item();
public :
	void EnterCollision() override;
	void ExitCollision() override;
	void Update() override;
	void Render(HDC _dc) override;
public:
	Texture* GetTex() const { return m_pTex; }
	const void SetNeedRender(const bool value);
	const bool GetIsPickUp() { return pickUp; }
protected:
	bool isEnter;
	bool pickUp;
	bool needRender;
	ITEM_TYPE m_itmeType;
};

