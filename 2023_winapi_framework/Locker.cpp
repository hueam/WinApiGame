#include "pch.h"
#include "Locker.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Collider.h"
#include "Item.h"
#include "Inventory.h"
#include "TextMgr.h"

Locker::Locker()
	:isOpen(false)
	, isEnter(false)
	, isPost(false)
	, isLocked(false)
{
	m_pOpenTex = ResMgr::GetInst()->TexLoad(L"OpenLocker", L"Texture\\OpenLocker.bmp");
	m_pCloseTex = ResMgr::GetInst()->TexLoad(L"CloseLocker", L"Texture\\CloseLocker.bmp");
	m_pLockedCloseTex = ResMgr::GetInst()->TexLoad(L"LockCloseLocker", L"Texture\\LockedCloseLocker.bmp");
	CreateCollider();
}

Locker::~Locker()
{
}

void Locker::EnterCollision()
{
	isEnter = true;
}

void Locker::ExitCollision()
{
	isEnter = false;
}

void Locker::FinalUpdate()
{
	if (isEnter && KEY_UP(KEY_TYPE::LBUTTON) && isLocked)
	{
		Item* item = KeyMgr::GetInst()->GetPickUpItem();
		if (item != nullptr && item->GetIsType() == ITEM_TYPE::KEY)
		{
			isLocked = false;
			Inventory::GetInst()->DeleteItem(item);
		}
		ResMgr::GetInst()->Play(L"locker_open");
	}
	if (isEnter && KeyMgr::GetInst()->GetCurHIghObject() == this)
	{
		if (KEY_DOWN(KEY_TYPE::LBUTTON))
		{
			if (isLocked)
			{
				TextMgr::GetInst()->SetText(L"잠겨있네..?");
				TextMgr::GetInst()->SetText(L"이거 내 사물함인데..?");
				TextMgr::GetInst()->SetText(L"열쇠가 어딨을까");
				return;
			}
			isOpen = !isOpen;
			ResMgr::GetInst()->Play(L"locker_close");
		}
	}
	if (m_pCollider != nullptr)
		m_pCollider->FinalUpdate(false);
}

void Locker::Render(HDC _dc)
{

	Texture* curTex;
	if (isOpen)
		curTex = m_pOpenTex;
	else
	{
		if (isLocked)
			curTex = m_pLockedCloseTex;
		else
			curTex = m_pCloseTex;
	}
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	float multiplier = vScale.x / 400;

	Vec2 vRenderPos = CameraMgr::GetInst()->AdjustPos(vPos);
	Vec2 vRenderScale = CameraMgr::GetInst()->AdjustScale(vScale);

	int Width = curTex->GetWidth();
	int Height = curTex->GetHeight();

	float x = (int)(vRenderPos.x - vRenderScale.x / 2);
	float y = (int)(vRenderPos.y - vRenderScale.y / 2);
	if (isOpen)
	{
		vRenderScale = vRenderScale + Vec2(13 * multiplier, 13 * multiplier);
		y -= 13 * multiplier;
	}

	//x *= (int)(vCamScale.x /2);
	//y *= (int)(vCamScale.x /2);  
		//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, curTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	/*TransparentBlt(_dc
		, vPos.x
		, vPos.y
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));*/
	Component_Render(_dc);
	if (isEnter)
		TextOut(_dc, vRenderPos.x, vRenderPos.y, name.c_str(), name.size());
}
