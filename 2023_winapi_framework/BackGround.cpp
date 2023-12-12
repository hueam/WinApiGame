#include "pch.h"
#include "BackGround.h"
#include "ResMgr.h"
#include "Texture.h"
#include "CameraMgr.h"
#include "Core.h"

BackGround::BackGround(wstring key, wstring name)
{
	wstring path = L"Texture\\" + name + L".bmp";
	m_pTex = ResMgr::GetInst()->TexLoad(key, path);
}

BackGround::~BackGround()
{

}

void BackGround::Render(HDC _dc)
{
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
	//x *= (int)(vCamScale.x /2);
	//y *= (int)(vCamScale.x /2);  
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	/*TransparentBlt(_dc
		, vPos.x
		, vPos.y
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));*/

	Component_Render(_dc);
}
