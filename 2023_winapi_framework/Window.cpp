#include "pch.h"
#include "Window.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Item.h"
#include "Inventory.h"
#include "FlowerPot.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "TextMgr.h"

Window::Window(bool is)
	: isOpen(false), isEnter(false), isLight(false)
{
	isLight = is;
	m_pOpenTex = ResMgr::GetInst()->TexLoad(L"CloseWindow", L"Texture\\window_password_opened.bmp");
	m_pCloseTex = ResMgr::GetInst()->TexLoad(L"OpenWindow", L"Texture\\window_password.bmp");
	m_pCloseLightTex = ResMgr::GetInst()->TexLoad(L"LightWindow", L"Texture\\lighted_window.bmp");
	CreateCollider();
}

Window::~Window()
{
}

void Window::EnterCollision()
{
	isEnter = true;
}

void Window::ExitCollision()
{
	isEnter = false;
}

void Window::Update()
{
	if (isEnter && KEY_DOWN(KEY_TYPE::LBUTTON))
	{
		if (isLight) return;
		if (!isOpen)
		{
			isOpen = true;
			ResMgr::GetInst()->Play(L"window");
		}
		else
		{
			if (!TextMgr::GetInst()->GetLookHint())
				return;
			TextMgr::GetInst()->SetText(L"무슨 모양이 있는데?");
		}
	}
	if (KEY_UP(KEY_TYPE::LBUTTON) && isEnter && isLight)
	{
		Item* item = KeyMgr::GetInst()->GetPickUpItem();
		if (item != nullptr && item->GetIsType() == ITEM_TYPE::POT)
		{
			Inventory::GetInst()->DeleteItem(item);
			//화분 생성
			FlowerPot* pot = new FlowerPot();
			pot->SetPos(m_vPos + Vec2({ (-m_vPos.x * 0.25f) - 20,82.f }));
			pot->SetScale({ 50.f,100.f });
			pot->SetSun(true);
			SceneMgr::GetInst()->GetCurScene()->AddObject(pot, RENDER_ORDER::TWO);
		}
	}
}

void Window::Render(HDC _dc)
{
	Texture* curTex = nullptr;

	if (isLight) curTex = m_pCloseLightTex;
	else if (isOpen && !isLight) curTex = m_pOpenTex;
	else if (!isOpen && !isLight) curTex = m_pCloseTex;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	//float multiplier = vScale.x / 400;

	Vec2 vRenderPos = vPos - vCamPos;
	Vec2 vRenderScale = vScale * vCamScale;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

	int Width = curTex->GetWidth();
	int Height = curTex->GetHeight();

	float x = (int)(vRenderPos.x - vRenderScale.x / 2);
	float y = (int)(vRenderPos.y - vRenderScale.y / 2);

	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, curTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
	if (isEnter)
		TextOut(_dc, vRenderPos.x, vRenderPos.y, name.c_str(), name.size());
}
