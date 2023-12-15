#include "pch.h"
#include "Key.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "Inventory.h"
#include "Item.h"
#include "TrashCanPopup.h"
#include "TextMgr.h"

Key::Key(wstring key, wstring textureName, TrashCanPopup* newOwner) : UIObject(key, textureName)
	, isEnter(false)
{
	owner = newOwner;
	CreateCollider();
}

Key::~Key()
{
}

void Key::Update()
{
	SetScale(owner->GetScale());
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		Inventory::GetInst()->SelectItem(new Item(ITEM_TYPE::KEY,m_pTex,L"¿­¼è"));
		EventMgr::GetInst()->DeleteObject(this);
		TextMgr::GetInst()->SetText(L"¾î..? ¿­¼è°¡ ¿Ö ¿©ƒ…Áö..?");
	}
}

void Key::Render(HDC _dc)
{
	if(owner->GetNeedRendering())
		UIObject::Render(_dc);
}

void Key::EnterCollision()
{
	isEnter = true;
}

void Key::ExitCollision()
{
	isEnter = false;
}
