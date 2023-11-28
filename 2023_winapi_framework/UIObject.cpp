#include "pch.h"
#include "UIObject.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Collider.h"

UIObject::UIObject()
	:m_pTex(nullptr)
{

}

UIObject::UIObject(const wstring& key,const wstring& textureName)
{
	wstring path = L"Texture\\UI\\" + textureName + L".bmp";
	m_pTex = ResMgr::GetInst()->TexLoad(key, path);
}

UIObject::~UIObject()
{

}

void UIObject::Update()
{
}

void UIObject::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, vScale.x, vScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void UIObject::Component_Render(HDC _dc)
{

	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc, true);
}
