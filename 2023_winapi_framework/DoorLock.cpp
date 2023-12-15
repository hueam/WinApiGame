#include "pch.h"
#include "DoorLock.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"
#include "CameraMgr.h"
#include "KeyMgr.h"
#include "Collider.h"
#include "Door.h"
#include "NumPad.h"
#include "Scene.h"
#include "SelectGDI.h"
#include "TextMgr.h"

DoorLock::DoorLock(Vec2 pos, Vec2 scale, Scene* curScene) : isEnter(false), inputNum(L"    "), size(0), open(false)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"DoorLock", L"Texture\\doorlock.bmp");
	CreateCollider();

	float padXScale = (scale.x - 10 * 2) / 3;
	Vec2 padPos = Vec2({ (pos.x - scale.x * 0.5f) + 13,(pos.y - scale.y * 0.5f) + 27 });

	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num++;
			NumPad* pad = new NumPad(num, this);
			pad->SetPos(padPos + Vec2({ (padXScale * j) + 2 * j, (padXScale * i) + 2 * i }));
			pad->SetScale({ padXScale,padXScale });
			pads[num - 1] = pad;
			curScene->AddObject(pad, RENDER_ORDER::THREE);
		}
	}
	SetPos(pos);
	SetScale(scale);
}

DoorLock::~DoorLock()
{
}

void DoorLock::Update()
{
	GetCollider()->SetEnable(!open);
	if (CameraMgr::GetInst()->GetFocusingObj() == this)
	{
		for (int i = 0; i < 12; i++)
		{
			pads[i]->GetCollider()->SetEnable(true);
		}
	}
	else
	{
		for (int i = 0; i < 12; i++)
		{
			pads[i]->GetCollider()->SetEnable(false);
		}
	}
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		CameraMgr::GetInst()->SetPos(m_vPos);
		CameraMgr::GetInst()->SetScale(5);
		CameraMgr::GetInst()->SetFocusingObj(this);
	}
}

void DoorLock::Render(HDC _dc)
{
	Vec2 textPos;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	Vec2 vRenderPos = vPos - vCamPos;
	Vec2 vRenderScale = vScale * vCamScale;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);

	if (CameraMgr::GetInst()->GetFocusingObj() == this)
	{
		HFONT hFont = CreateFont(60, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS
			, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FIXED_PITCH, TEXT("DungGeunMo"));
		SelectGDI font(_dc, hFont);
		SetTextColor(_dc, RGB(255, 255, 255));

		TextOut(_dc, x + 65, y + 45, inputNum.c_str(), 4);
	}
	SetTextColor(_dc, RGB(0, 0, 0));
}

void DoorLock::AddNum(int num)
{
	if (num < 10)
	{
		if (size < 4)
		{
			inputNum.at(size) = std::to_wstring(num)[0];
			size++;
		}
	}
	else if (num == 10)
	{
		if (size > 0)
		{
			inputNum.at(size - 1) = L' ';
			size--;
		}
	}
	else if (num == 12)
	{
		if (inputNum == L"5379")
		{
			open = true;
			CameraMgr::GetInst()->Init();
			TextMgr::GetInst()->SetText(L"맞았다!");
		}
		else
		{
			inputNum = L"    ";
			size = 0;
			TextMgr::GetInst()->SetText(L"틀렸네...");
		}
	}
}

void DoorLock::EnterCollision()
{
	isEnter = true;
}

void DoorLock::ExitCollision()
{
	isEnter = false;
}
