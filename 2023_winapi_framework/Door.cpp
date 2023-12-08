#include "pch.h"
#include "Door.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"

Door::Door() : isOpen(false), isEnter(false)
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
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && isEnter)
	{
		isOpen = !isOpen;
	}
}

void Door::Render(HDC _dc)
{

	Texture* curTex;

	if (isOpen) curTex = m_pOpenTex;
	else curTex = m_pCloseTex;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	//float multiplier = vScale.x / 400;

	Vec2 vRenderPos = vPos - vCamPos;
	Vec2 vRenderScale = vScale * vCamScale;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

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
