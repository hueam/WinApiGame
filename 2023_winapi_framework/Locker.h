#pragma once
#include "Object.h"
class Texture;
class Locker :
    public Object
{
	const wstring name = L"¶ôÄ¿";
public:
	Locker();
	~Locker();
public:
	void EnterCollision() override;
	void ExitCollision() override;
	void FinalUpdate() override;
	void Render(HDC _dc) override;
public:
	void SetIsPost(bool value) { isPost = value; }
	void SetIsLocked(bool value) { isLocked = value; }
	const bool GetIsOpen() { return isOpen; }
private:
	bool isEnter;
	bool isOpen;
	bool isPost;
	bool isLocked;

	Texture* m_pCloseTex;
	Texture* m_pLockedCloseTex;
	Texture* m_pOpenTex;
};

