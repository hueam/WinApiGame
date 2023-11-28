#include "pch.h"
#include "InventoryUI.h"

InventoryUI::~InventoryUI()
{
}

void InventoryUI::Update()
{
	//ÆÀÀå ÇØÁà
}

void InventoryUI::Render(HDC _dc)
{
	// maxItemCnt = 5 (±âº» 5°³ ÀÎº¥Åä¸® Show) // scrollCnt ½ºÅ©·Ñ ÃÑ ¸î ¹ø Çß´ÂÁö ±âº»0
	for (int i = scrollCnt; i < maxItemCnt + scrollCnt; i++) // 0~5 ·»´õ -> scrollCnt + 1 µÆÀ» °æ¿ì 1~6 ·»´õ
	{
		// vecitem[i] != null -> Render vecitem[i]
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
