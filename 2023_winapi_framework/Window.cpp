#include "pch.h"
#include "Window.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"

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
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && isEnter)
	{
		if (isLight) return;
		isOpen = !isOpen;
	}
}

void Window::Render(HDC _dc)
{
	Texture* curTex = nullptr;
	
	if (isLight) curTex = m_pCloseLightTex;
	else if (isOpen && !isLight) curTex = m_pOpenTex;
	else if(!isOpen && !isLight) curTex = m_pCloseTex;

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
