#pragma once
#include "UIObject.h";
class Texture;
class Item
	: public UIObject
{
public:
	Item(ITEM_TYPE type, Texture* texture,wstring itemName);
	~Item();
public :
	void EnterCollision() override;
	void ExitCollision() override;
	void Update() override;
	void FinalUpdate() override;
	void Render(HDC _dc) override;
public:
	Texture* GetTex() const { return m_pTex; }
	const void SetNeedRender(const bool value);
	const bool GetIsPickUp() { return pickUp; }
	const ITEM_TYPE GetIsType() { return m_itmeType; }
protected:
	bool isEnter;
	bool pickUp;
	bool needRender;
	wstring name;
	ITEM_TYPE m_itmeType;
};

