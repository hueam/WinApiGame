#include "pch.h"
#include "PopUpTexture.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "CameraMgr.h"

PopUpTexture::PopUpTexture(Vec2 scale, wstring key, wstring textureName) 
	: UIObject(key, textureName)
	,needRendering(false)
	,isEnter(false)
{
	popupSclae = scale;
	SetScale(Vec2(0, 0));
	CreateCollider();
}

PopUpTexture::~PopUpTexture()
{

}

void PopUpTexture::Update()
{
	if (KEY_DOWN(KEY_TYPE::LBUTTON)&& !isEnter)
	{
		Close();
	}
}

void PopUpTexture::Render(HDC _dc)
{
	if (needRendering == false) return;
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	float x = (int)(m_vPos.x - m_vScale.x / 2);
	float y = (int)(m_vPos.y - m_vScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, m_vScale.x, m_vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void PopUpTexture::EnterCollision()
{
	isEnter = true;
}

void PopUpTexture::ExitCollision()
{
	isEnter = false;
}

void PopUpTexture::Open()
{
	CameraMgr::GetInst()->AddWindoeCnt();
	needRendering = true;
	SetScale(popupSclae);
}

void PopUpTexture::Close()
{
	needRendering = false;
	SetScale(Vec2(0, 0));

}