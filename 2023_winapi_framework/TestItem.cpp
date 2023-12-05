#include "pch.h"
#include "TestItem.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Inventory.h"
#include "EventMgr.h"

TestItem::TestItem()
	: isEnter(false)
	, isZoom(false)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Bullet", L"Texture\\Bullet.bmp");
	CreateCollider();
}

TestItem::~TestItem()
{
}

void TestItem::EnterCollision()
{
	isEnter = true;
}

void TestItem::ExitCollision()
{
	isEnter = false;
}

void TestItem::Update()
{
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && isEnter == true)
	{
		Inventory::GetInst()->SelectItem(new Item(ITEM_TYPE::TEST,m_pTex));
		EventMgr::GetInst()->DeleteObject(this);
	}
	if (KEY_DOWN(KEY_TYPE::E) && isEnter == true)
	{
		CameraMgr::GetInst()->SetPos(m_vPos);
		CameraMgr::GetInst()->SetScale(2);
	}
}

void TestItem::Render(HDC _dc)
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
	vRenderPos = vRenderPos + (vRenderPos - vResolution)*vMinusCamScale;

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
	/*TransparentBlt(_dc
		, vPos.x
		, vPos.y
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));*/

	Component_Render(_dc);
	if (isEnter)
		TextOut(_dc, x, y, name.c_str(), name.size());
}