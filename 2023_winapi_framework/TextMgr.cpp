#include "pch.h"
#include "TextMgr.h"
#include "KeyMgr.h"
#include "Blend.h"
#include "Core.h"
#include "SelectGDI.h"

void TextMgr::Init()
{
	Vec2 winSize = Core::GetInst()->GetGamgeScreen();
	RECT rt{ 0,winSize.y - 200, winSize.x, winSize.y };
	background = new Blend(rt, 200, 255, 2.f, new BLENDFUNCTION());
	background->SetLoop(true);
	background->SetYoyo(true);
	RECT m_rt{ 15,winSize.y - 185, winSize.x - 15, winSize.y - 15 };
	rect = m_rt;
}

void TextMgr::Update()
{
	if (isEnable)
	{
		background->Update();
		if (KEY_DOWN(KEY_TYPE::LBUTTON))
		{
			txt.pop();
			if (txt.empty())
			{
				isEnable = false;
				background->EndBlend();
			}
		}
	}
}

void TextMgr::Render(HDC _dc)
{
	isEnable = !txt.empty();
	if (isEnable == false) return;

	wstring str = txt.front();

	background->Render(_dc);
	SetTextColor(_dc, RGB(255, 255, 255));
	DrawText(_dc, str.c_str(), str.length(), &rect, DT_LEFT);
	SetTextColor(_dc, RGB(0, 0, 0));
}

void TextMgr::SetText(wstring newTxt)
{
	if (isEnable) return;
	txt.push(newTxt);
	if (isEnable == false)
	{
		background->StartBlend();
	}
}

void TextMgr::SetRect(RECT& newRect)
{
	rect = newRect;
	background->SetBlend(newRect);
}
