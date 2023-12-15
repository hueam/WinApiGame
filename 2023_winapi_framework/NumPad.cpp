#include "pch.h"
#include "NumPad.h"
#include "KeyMgr.h"
#include "DoorLock.h"
#include "ResMgr.h"

NumPad::NumPad(int num, DoorLock* owner)
	:isEnter(false)
	, m_iNum(num)
	, m_pOwner(owner)
{
	CreateCollider();
}

NumPad::~NumPad()
{
}

void NumPad::Update()
{
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		if (m_iNum == 11)
			m_pOwner->AddNum(0);
		else
			m_pOwner->AddNum(m_iNum);
		ResMgr::GetInst()->Play(L"NumPad");
	}
}

void NumPad::EnterCollision()
{
	isEnter = true;
}

void NumPad::ExitCollision()
{
	isEnter = false;
}
