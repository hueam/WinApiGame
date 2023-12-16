#pragma once
#include "Object.h"
class Texture;
class Door;
class NumPad;
class Scene;
class DoorLock :
	public Object
{
public:
	DoorLock(Vec2 pos, Vec2 scale, Scene* curScene);
	~DoorLock();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void AddNum(int num);
public:
	void EnterCollision() override;
	void ExitCollision() override;
public:
	const bool &GetOpen() const { return open; }
private:
	bool isEnter;
	bool open;
	int size = 0;
	Texture* m_pTex;
	wstring inputNum;
	NumPad* pads[12];
};