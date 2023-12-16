#pragma once
#include "Object.h"
class DoorLock;
class NumPad
	:public Object
{
public:
	NumPad(int num, DoorLock* owner);
	~NumPad();
public:
	void Update() override;
	void EnterCollision() override;
	void ExitCollision() override;

private:
	bool isEnter;
	int m_iNum;
	DoorLock* m_pOwner;
};

