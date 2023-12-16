#include "pch.h"
#include "TouchTextObject.h"
#include "KeyMgr.h"
#include "TextMgr.h"

TouchTextObject::TouchTextObject(vector<wstring>& texts, bool hint): canHint(false)
{
	textList = texts;
	CreateCollider();
	isHint = hint;
}

TouchTextObject::~TouchTextObject()
{
	textList.clear();
	vector<wstring>().swap(textList);
}

void TouchTextObject::Update()
{
	if (canHint && !TextMgr::GetInst()->GetLookHint())
	{
		return;
	}
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		for (auto item: textList)
		{
			TextMgr::GetInst()->SetText(item);
		}
		TextMgr::GetInst()-> SetLookHint(true);
	}
}

void TouchTextObject::EnterCollision()
{
	isEnter = true;
}

void TouchTextObject::ExitCollision()
{
	isEnter = false;
}
