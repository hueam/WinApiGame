#include "pch.h"
#include "FlowerPot.h"
#include "CameraMgr.h"
#include "ResMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Inventory.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "TextMgr.h"

FlowerPot::FlowerPot() :isEnter(false), sun(false), water(false)
{

	m_pTex = ResMgr::GetInst()->TexLoad(L"pot", L"Texture\\plants.bmp");
	m_pgGrow_One_Tex = ResMgr::GetInst()->TexLoad(L"plants_grow_1", L"Texture\\plants_grow_1.bmp");
	m_pgGrow_Two_Tex = ResMgr::GetInst()->TexLoad(L"plants_grow_2", L"Texture\\plants_grow_2.bmp");

	CreateCollider();
}

FlowerPot::~FlowerPot()
{
}

void FlowerPot::Update()
{
	if (isEnter && sun)
	{
		if (water && KEY_DOWN(KEY_TYPE::LBUTTON))
		{
			if (!TextMgr::GetInst()->GetLookHint())
				return;
			TextMgr::GetInst()->SetText(L"(삼각형 문양이 그려진 화분에 꽃이 피었다)");
			TextMgr::GetInst()->SetText(L"빨간 삼각형..?");
			TextMgr::GetInst()->SetText(L"삼각형이 화분의 문양과 다르게 뒤집혀 있는데?");
		}
		else if (KEY_UP(KEY_TYPE::LBUTTON))
		{
			Item* item = KeyMgr::GetInst()->GetPickUpItem();
			if (item != nullptr && item->GetIsType() == ITEM_TYPE::WATER)
			{
				SetWater(true);
				Inventory::GetInst()->DeleteItem(item);
				ResMgr::GetInst()->Play(L"water");
			}
		}
	}
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON) && (!sun && !water))
	{
		Inventory::GetInst()->SelectItem(new Item(ITEM_TYPE::POT, m_pTex,L"화분"));
		EventMgr::GetInst()->DeleteObject(this);
	}
}

void FlowerPot::Render(HDC _dc)
{
	Texture* curTex = nullptr;
	if (sun || water)
	{
		if (sun && water)
			curTex = m_pgGrow_Two_Tex;
		else
			curTex = m_pgGrow_One_Tex;
	}
	else
		curTex = m_pTex;

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

	int Width = curTex->GetWidth();
	int Height = curTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, curTex->GetDC()
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
