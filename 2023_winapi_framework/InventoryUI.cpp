#include "pch.h"
#include "InventoryUI.h"
#include "Texture.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Scene.h"
#include "Slot.h"
#include "SceneUI.h"
#include "Item.h"
#include "Object.h"
#include "UIObject.h"

InventoryUI::InventoryUI()
{
}
InventoryUI::InventoryUI(wstring textureName) : UIObject(L"asd", textureName)
{


}

InventoryUI::~InventoryUI()
{
}

void InventoryUI::Init(Vec2 pos, Vec2 scale)
{
	SetPos(pos);
	SetScale(scale);

	Vec2 startPos = Vec2((int)(pos.x - scale.x / 2), (int)(pos.y - scale.y / 2));
	Vec2 endPos = Vec2((int)(pos.x + scale.x / 2), (int)(pos.y + scale.y / 2));

	for (int i = 0; i < maxItemCnt; i++)
	{
		Slot* slot = new Slot();

		int texSize = endPos.x - startPos.x - xPadding * 2;
		yPadding = (endPos.y - (texSize * 3)) / 4;

		Vec2 scale(texSize + 10, texSize + 10);
		slot->SetPos(Vec2({ pos.x, yPadding + ((texSize + yPadding) * i) + texSize * 0.5f }));
		slot->SetScale(scale);
		SceneUI::AddDontDestroyUI(slot, UI_RENDER_ORDER::SLOT);
	}
}

void InventoryUI::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	Vec2 startPos = Vec2((int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2));
	Vec2 endPos = Vec2((int)(vPos.x + vScale.x / 2), (int)(vPos.y + vScale.y / 2));

	int texSize = endPos.x - startPos.x - xPadding * 2;
	float  y = yPadding;


	vector<Item*> inven = Inventory::GetInst()->GetItemVector();
	for (int i = 0; i < inven.size(); i++)
	{
		bool needRender = i >= scrollCnt && i < scrollCnt + maxItemCnt;
		inven[i]->SetNeedRender(needRender);
		if (needRender)
		{
			if (!inven[i]->GetIsPickUp())
			{
				inven[i]->SetPos(Vec2({ vPos.x,y + texSize * 0.5f }));
				inven[i]->SetScale(Vec2(texSize, texSize));
			}
			y += texSize + yPadding;
		}
	}
}

void InventoryUI::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	Vec2 startPos = Vec2((int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2));
	Vec2 endPos = Vec2((int)(vPos.x + vScale.x / 2), (int)(vPos.y + vScale.y / 2));
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, startPos.x
		, startPos.y
		, vScale.x, vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
	//vector<Item*> inven = Inventory::GetInst()->GetItemVector();
	//// maxItemCnt = 5 (기본 5개 인벤토리 Show) // scrollCnt 스크롤 총 몇 번 했는지 기본0
	//int texSize = endPos.x - startPos.x - xPadding * 2;

	//int y = yPadding;
	//for (int i = scrollCnt; i < maxItemCnt + scrollCnt; i++) // 0~5 렌더 -> scrollCnt + 1 됐을 경우 1~6 렌더
	//{
	//	if (i > inven.size() || inven.size() == 0) break;

	//	Texture* itemTex = inven[i]->GetTex();
	//	TransparentBlt(_dc
	//		, startPos.x + xPadding
	//		, y
	//		, texSize, texSize, itemTex->GetDC()
	//		, 0, 0, itemTex->GetWidth(), itemTex->GetHeight(), RGB(255, 0, 255));
	//	y += texSize + yPadding;
	//}
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