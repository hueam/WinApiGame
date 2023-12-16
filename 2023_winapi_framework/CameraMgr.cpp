#include "pch.h"
#include "CameraMgr.h"
#include "Core.h"

void CameraMgr::Init()
{
	if (--windowCnt < 0)
	{
		windowCnt = 0;
		m_vCamPos = Vec2(0, 0);
		m_vCamScale = Vec2(1, 1);
		m_pFocusingObj = nullptr;
		isZoom = false;
	}
}

void CameraMgr::SetScale(const int scale)
{
	m_vCamScale = Vec2(scale, scale);
	isZoom = !(scale <= 1);
}

void CameraMgr::SetPos(const Vec2 pos)
{
	m_vCamPos = Vec2(pos.x - Core::GetInst()->GetResolution().x / 2, pos.y - Core::GetInst()->GetResolution().y / 2);
	//m_vCamPos = pos;
}

void CameraMgr::SetFocusingObj(Object* obj)
{
	m_pFocusingObj = obj;
}

void CameraMgr::AddPos(const int x, const int y)
{
	m_vCamPos.x += x;
	m_vCamPos.y += y;
}


Vec2& CameraMgr::AdjustPos(Vec2& pos)
{
	Vec2 vMinusCamScale = m_vCamScale;
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	//float multiplier = vScale.x / 400;

	Vec2 vRenderPos = pos - m_vCamPos;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

	return vRenderPos;
}

Vec2& CameraMgr::AdjustScale(Vec2& scale)
{
	//float multiplier = vScale.x / 400;

	Vec2 vRenderScale = scale * m_vCamScale;
	return vRenderScale;
}

