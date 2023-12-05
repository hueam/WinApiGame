#pragma once
#include "Object.h"

class Texture;
class Window :
    public Object
{
	const wstring name = L"â��";
public:
	Window();
	~Window();
public:
	void EnterCollision() override;
	void ExitCollision() override;
	void Update() override;
	void Render(HDC _dc) override;
public:
	void SetIsOpened(bool value) { isOpen = value; }
private:
	bool isEnter;
	bool isOpen;

	Texture* m_pCloseTex;
	Texture* m_pOpenTex;
};

