#include "pch.h"
#include "Blend.h"
#include "TimeMgr.h"
#include "SelectGDI.h"
#include "Core.h"

Blend::Blend(RECT& rect, float start, float end, float time, BLENDFUNCTION* newBlend) :
	curTime(0)
	, running(false)
	, isYoyo(false)
	, isLoop(false)
{
	startValue = start;
	endValue = end;
	this->time = time;
	blend = newBlend;
	blend->SourceConstantAlpha = startValue;
	blendSize = rect;
}

Blend::~Blend()
{
	delete blend;
}

void Blend::Update()
{
	if (running == false)
	{
		//blend->SourceConstantAlpha = 0;
		return;
	}
	if (isYoyo)
	{
		curTime += fDT;
		if (curTime < time * 0.5f)
		{
			blend->SourceConstantAlpha = startValue * (1 - curTime*2 / time) + endValue * curTime*2 / time;
		}
		else 
		{
			if (curTime > time)
			{
				curTime = time;
			}
			blend->SourceConstantAlpha = startValue * (1 - (time - curTime) / (time*0.5f)) + endValue * (time - curTime) / (time * 0.5f);
		}
	}
	else
	{
		curTime += fDT;

		blend->SourceConstantAlpha = startValue * (1 - curTime / time) + endValue * curTime / time;
	}
	if (curTime >= time)
	{
		if (isLoop == false)
		{
			curTime = time;
			running = false;
			if (endEvent != nullptr)
				endEvent();
		}
		else
		{
			curTime = 0;
		}
	}
}

void Blend::Render(HDC _dc)
{
	if (running == false) return;

	Vec2 size = Core::GetInst()->GetResolution();

	HDC hAlphaDC = CreateCompatibleDC(_dc);
	HBITMAP hAlphaBit = CreateCompatibleBitmap(_dc, size.x, size.y);
	SelectObject(hAlphaDC, hAlphaBit);

	BitBlt(hAlphaDC, 0, 0, size.x, size.y, _dc, 0, 0, SRCCOPY);

	HBRUSH hColorBrush = CreateSolidBrush(RGB(0, 0, 0));
	HPEN hColorPen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	SelectObject(hAlphaDC, hColorBrush);
	SelectObject(hAlphaDC, hColorPen);

	Rectangle(hAlphaDC,
		blendSize.left,
		blendSize.top,
		blendSize.right,
		blendSize.bottom);

	AlphaBlend(_dc, 0, 0, size.x, size.y,
		hAlphaDC, 0, 0, size.x, size.y, *blend);
	DeleteObject(hColorBrush);
	DeleteObject(hColorPen);
	DeleteObject(hAlphaBit);
	DeleteDC(hAlphaDC);
}

void Blend::SetEndEvnet(std::function<void()>& func)
{
	endEvent = func;
}

void Blend::StartBlend()
{
	running = true;
	curTime = 0;
	blend->SourceConstantAlpha = startValue;
}
void Blend::CleanEvent()
{
	endEvent = nullptr;
}

void Blend::Reset()
{
	blend->SourceConstantAlpha = 0;
}

void Blend::SetBlend(RECT& newRect)
{
	blendSize = newRect;
}


void Blend::EndBlend()
{
	running = false;
	curTime = time;
	blend->SourceConstantAlpha = endValue;
	if (endEvent != nullptr)
	{
		endEvent();
	}
}
