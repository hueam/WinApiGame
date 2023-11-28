#include "pch.h"
#include "InventoryUI.h"
#include "Texture.h"
#include "Collider.h"

InventoryUI::InventoryUI()
{
}
InventoryUI::InventoryUI(wstring textureName) : UIObject(L"asd", textureName)
{

}

InventoryUI::~InventoryUI()
{
}

void InventoryUI::Update()
{
	//ÆÀÀå ÇØÁà
}

void InventoryUI::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, vScale.x, vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
	// maxItemCnt = 5 (±âº» 5°³ ÀÎº¥Åä¸® Show) // scrollCnt ½ºÅ©·Ñ ÃÑ ¸î ¹ø Çß´ÂÁö ±âº»0
	for (int i = scrollCnt; i < maxItemCnt + scrollCnt; i++) // 0~5 ·»´õ -> scrollCnt + 1 µÆÀ» °æ¿ì 1~6 ·»´õ
	{

	}
}

void InventoryUI::ScrollUp()
{
	//if(scrollCnt) 
	scrollCnt++;
}

void InventoryUI::ScrollDown()
{
	if (scrollCnt > 0) scrollCnt--;
}
void InventoryUI::Component_Render(HDC _dc)
{
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc, true);
}