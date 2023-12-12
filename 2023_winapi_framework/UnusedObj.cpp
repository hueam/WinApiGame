#include "pch.h"
#include "UnusedObj.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"
#include "Collider.h"
#include "Item.h"
#include "Inventory.h"

UnusedObj::UnusedObj(wstring name) :isEnter(false)
{
	objName = name;
	wstring path = L"Texture\\" + name + L".bmp";

	m_pTex = ResMgr::GetInst()->TexLoad(name, path);
}

UnusedObj::~UnusedObj()
{
}

void UnusedObj::EnterCollision()
{
	isEnter = true;
}

void UnusedObj::ExitCollision()
{
	isEnter = false;
}

void UnusedObj::Render(HDC _dc)
{

	Texture* curTex = m_pTex;

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
}
