#include "pch.h"
#include "InventoryUI.h"

InventoryUI::~InventoryUI()
{
}

void InventoryUI::Update()
{
	//���� ����
}

void InventoryUI::Render(HDC _dc)
{
	// maxItemCnt = 5 (�⺻ 5�� �κ��丮 Show) // scrollCnt ��ũ�� �� �� �� �ߴ��� �⺻0
	for (int i = scrollCnt; i < maxItemCnt + scrollCnt; i++) // 0~5 ���� -> scrollCnt + 1 ���� ��� 1~6 ����
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
