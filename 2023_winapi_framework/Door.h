#pragma once
#include "Object.h"

class Texture;
class DoorLock;
class Door :
	public Object
{
	const wstring name = L"¹®";
public:
	Door();
	~Door();
public:
	void EnterCollision() override;
	void ExitCollision() override;
	void Update() override;
	void Render(HDC _dc) override;
public:
	void SetDoorLock(DoorLock* lock) { m_pDoorLock = lock; }
private:
	void End();
private:
	bool isEnter;
	bool isOpen;

	DoorLock* m_pDoorLock;
	Texture* m_pCloseTex;
	Texture* m_pOpenTex;
};

