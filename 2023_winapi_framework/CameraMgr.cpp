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
	}
	isZoom = false;
}

void CameraMgr::SetPos(const Vec2 pos)
{
	m_vCamPos = Vec2(pos.x - Core::GetInst()->GetResolution().x / 2, pos.y - Core::GetInst()->GetResolution().y / 2);
	isZoom = true;
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

