#include "pch.h"
#include "Item.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "CameraMgr.h"

Item::Item(ITEM_TYPE type, Texture* texture)
	:needRender(false)
	,isEnter(false)
	,pickUp(false)
{
	m_itmeType = type;
	m_pTex = texture;
	CreateCollider();
}

Item::~Item()
{
}

void Item::EnterCollision()
{
	isEnter = true;
}

void Item::ExitCollision()
{
	isEnter = false;
}

void Item::Update()
{
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		KeyMgr::GetInst()->SetPickUpItem(this);
		pickUp = true;
	}
}

void Item::FinalUpdate()
{
	UIObject::FinalUpdate();
	if (KEY_UP(KEY_TYPE::LBUTTON))
	{
		KeyMgr::GetInst()->SetPickUpItem(nullptr);
		pickUp = false;
	}
}


void Item::Render(HDC _dc)
{
	if (needRender == false) return;
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	float x = (int)(m_vPos.x - m_vScale.x / 2);
	float y = (int)(m_vPos.y - m_vScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, m_vScale.x, m_vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);

	if (isEnter)
	{
		TextOut(_dc,m_vPos.x, m_vPos.y,L"HI",3);
	}

}

const void Item::SetNeedRender(const bool value)
{
	needRender = value;
}