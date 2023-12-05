#include "pch.h"
#include "Locker.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "CameraMgr.h"
#include "Core.h"
#include "Texture.h"

Locker::Locker()
	:isOpen(false)
	, isEnter(false)
	, isPost(false)
	, isLocked(false)
{
	m_pOpenTex = ResMgr::GetInst()->TexLoad(L"OpenLocker", L"Texture\\OpenLocker.bmp");
	m_pCloseTex = ResMgr::GetInst()->TexLoad(L"CloseLocker", L"Texture\\CloseLocker.bmp");
	m_pLockedCloseTex = ResMgr::GetInst()->TexLoad(L"LockCloseLocker", L"Texture\\LockedCloseLocker.bmp");
	m_pPostTex = ResMgr::GetInst()->TexLoad(L"Post", L"Texture\\Post.bmp");
	CreateCollider();
}

Locker::~Locker()
{
}

void Locker::EnterCollision()
{
	isEnter = true;
}

void Locker::ExitCollision()
{
	isEnter = false;
}

void Locker::Update()
{
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && isEnter)
	{
		if (isLocked) return;
		isOpen = !isOpen;
	}
	if (KEY_UP(KEY_TYPE::LBUTTON) && isEnter)
	{

	}

}

void Locker::Render(HDC _dc)
{

	Texture* curTex;
	if (isOpen)
		curTex = m_pOpenTex;
	else
	{
		if (isLocked)
			curTex = m_pLockedCloseTex;
		else
			curTex = m_pCloseTex;
	}
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	float multiplier = vScale.x / 400;

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
	if (isOpen)
	{
		vRenderScale = vRenderScale + Vec2(13 * multiplier, 13 * multiplier);
		y -= 13 * multiplier;
	}

	//x *= (int)(vCamScale.x /2);
	//y *= (int)(vCamScale.x /2);  
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, curTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	/*TransparentBlt(_dc
		, vPos.x
		, vPos.y
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));*/
	if (isPost)
	{
		if (isOpen)
		{
			x -= 13 * multiplier;
			int postWidth = m_pPostTex->GetWidth();
			int postHeight = m_pPostTex->GetHeight();
			Vec2 postScale = Vec2(postWidth * multiplier, postHeight * multiplier) * vCamScale;
			Vec2 postPos = Vec2(vRenderPos.x - postScale.x * 0.5f, vRenderPos.y - postScale.y  * 0.5f) ;
			TransparentBlt(_dc
				, postPos.x
				, postPos.y
				, postScale.x, postScale.y, m_pPostTex->GetDC()
				, 0, 0, postWidth, postHeight, RGB(255, 0, 255));
		}
	}
	Component_Render(_dc);
	if (isEnter)
		TextOut(_dc, vRenderPos.x, vRenderPos.y, name.c_str(), name.size());
}
