#include "pch.h"
#include "WaterBottle.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Inventory.h"
#include "EventMgr.h"
#include "Texture.h"
#include "CameraMgr.h"
#include "Locker.h"
#include "Collider.h"

WaterBottle::WaterBottle()
	:isEnter(false)
	,m_pOwnerLocker(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Water", L"Texture\\Water.bmp");
	CreateCollider();
}

WaterBottle::~WaterBottle()
{
}

void WaterBottle::Update()
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->SetEnable(m_pOwnerLocker->GetIsOpen());
	}

	if (!m_pOwnerLocker->GetIsOpen()) return;
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		Inventory::GetInst()->SelectItem(new Item(ITEM_TYPE::WATER, m_pTex,L"��"));
		EventMgr::GetInst()->DeleteObject(this);
	}
}

void WaterBottle::Render(HDC _dc)
{
	if (!m_pOwnerLocker->GetIsOpen()) return;
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Vec2 vRenderPos = CameraMgr::GetInst()->AdjustPos(vPos);
	Vec2 vRenderScale = CameraMgr::GetInst()->AdjustScale(vScale);

	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	//x *= (int)(vCamScale.x /2);
	//y *= (int)(vCamScale.x /2);  
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void WaterBottle::EnterCollision()
{
	isEnter = true;
}

void WaterBottle::ExitCollision()
{
	isEnter = false;
}
