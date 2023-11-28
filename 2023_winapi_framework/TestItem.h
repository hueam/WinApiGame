#pragma once
#include "Item.h"
#include "Object.h"

class TestItem
	: public Object
{
	const wstring name = L"Test";
public:
	TestItem();
	~TestItem();
public:
	void EnterCollision() override;
	void ExitCollision() override;
	void Update() override;
	void Render(HDC _dc) override;
private:
	bool isEnter;
	bool isZoom;
	Texture* m_pTex;
};

