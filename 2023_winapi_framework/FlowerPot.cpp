#include "pch.h"
#include "FlowerPot.h"
#include "CameraMgr.h"
#include "ResMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Inventory.h"
#include "KeyMgr.h"
#include "EventMgr.h"

FlowerPot::FlowerPot() :isEnter(false)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"pot", L"Texture\\plants.bmp");

	CreateCollider();
}

FlowerPot::~FlowerPot()
{
}

void FlowerPot::Update()
{
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		Inventory::GetInst()->SelectItem(new Item(ITEM_TYPE::POT, m_pTex));
		EventMgr::GetInst()->DeleteObject(this);
	}
}

void FlowerPot::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	Vec2 vRenderPos = vPos - vCamPos;
	Vec2 vRenderScale = vScale * vCamScale;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void FlowerPot::EnterCollision()
{
	isEnter = true;
}

void FlowerPot::ExitCollision()
{
	isEnter = false;
}
