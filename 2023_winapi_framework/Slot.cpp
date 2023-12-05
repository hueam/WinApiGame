#include "pch.h"
#include "Slot.h"
#include "ResMgr.h"
#include "Texture.h"

Slot::Slot()
	:isEnter(false)
	, SlotTexture(nullptr)
	, SelectSlotTexture(nullptr)
{
	SlotTexture = ResMgr::GetInst()->TexLoad(L"Slot", L"Texture\\UI\\Slot.bmp");
	SelectSlotTexture = ResMgr::GetInst()->TexLoad(L"SelectSlot", L"Texture\\UI\\SlotSelect.bmp");
	CreateCollider();
}

Slot::~Slot()
{
}

void Slot::Update()
{
}

void Slot::Render(HDC _dc)
{
	Texture* curTex;
	if (isEnter)
		curTex = SelectSlotTexture;
	else
		curTex = SlotTexture;

	int Width = curTex->GetWidth();
	int Height = curTex->GetHeight();

	float x = (int)(m_vPos.x - m_vScale.x / 2);
	float y = (int)(m_vPos.y - m_vScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, m_vScale.x, m_vScale.y, curTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void Slot::EnterCollision()
{
	isEnter = true;
}

void Slot::ExitCollision()
{
	isEnter = false;
}
