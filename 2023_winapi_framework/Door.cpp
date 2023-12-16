#include "pch.h"
#include "Door.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Texture.h"
#include "DoorLock.h"
#include "Door.h"
#include "DoorLock.h"
#include "Collider.h"
#include "SceneMgr.h"
#include "TextMgr.h"
#include "SceneUI.h"
#include <functional>

Door::Door() :isOpen(false), isEnter(false), m_pDoorLock(nullptr)
{
	m_pOpenTex = ResMgr::GetInst()->TexLoad(L"CloseDoor", L"Texture\\door_open.bmp");
	m_pCloseTex = ResMgr::GetInst()->TexLoad(L"OpenDoor", L"Texture\\door_close.bmp");
	CreateCollider();
}

Door::~Door()
{
}

void Door::EnterCollision()
{
	isEnter = true;
}

void Door::ExitCollision()
{
	isEnter = false;
}

void Door::Update()
{
	GetCollider()->SetEnable(CameraMgr::GetInst()->GetFocusingObj() != m_pDoorLock);

	if (isEnter)
	{
		if (KeyMgr::GetInst()->GetCurHIghObject() == this)
		{
			if (KEY_DOWN(KEY_TYPE::LBUTTON))
			{
				if (m_pDoorLock->GetOpen())
				{
					isOpen = true;
					m_pDoorLock->SetPos(m_vPos - Vec2({ 40.f,0.f }));
					ResMgr::GetInst()->Play(L"door_open");
					std::function<void()> func;
					func = std::bind(&Door::End, this);
					SceneMgr::GetInst()->FadeIn(func);
					//m_pDoorLock->SetDoorOpen(isOpen);
				}
				else
				{
					TextMgr::GetInst()->SetText(L"잠겨있네");
					TextMgr::GetInst()->SetText(L"비밀번호가 뭐였더라");
					TextMgr::GetInst()->SetText(L"칠판 게시물에 힌트가 있었지");
				}
			}
		}
	}
}

void Door::Render(HDC _dc)
{

	Texture* curTex;

	if (isOpen) curTex = m_pOpenTex;
	else curTex = m_pCloseTex;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Vec2 vRenderPos = CameraMgr::GetInst()->AdjustPos(vPos);
	Vec2 vRenderScale = CameraMgr::GetInst()->AdjustScale(vScale);


	int Width = curTex->GetWidth();
	int Height = curTex->GetHeight();

	float x = (int)(vRenderPos.x - vRenderScale.x / 2);
	float y = (int)(vRenderPos.y - vRenderScale.y / 2);

	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, curTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
	if (isEnter)
		TextOut(_dc, vRenderPos.x, vRenderPos.y, name.c_str(), name.size());
}

void Door::End()
{
	SceneMgr::GetInst()->LoadScene(L"End_Scene");
	SceneUI::ClearDontDestroyUI();
}
