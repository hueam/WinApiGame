#include "pch.h"
#include "TestItem.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Collider.h"

TestItem::TestItem()
	: isEnter(false)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Bullet", L"Texture\\Bullet.bmp");
	m_itmeType = ITEM_TYPE::TEST;
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
}

void TestItem::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	int x = (int)(vPos.x - vScale.x / 2);
	int y = (int)(vPos.y - vScale.y / 2);
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vScale.x, vScale.y, m_pTex->GetDC()
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