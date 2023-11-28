#include "pch.h"
#include "CameraMgr.h"
#include "Core.h"

void CameraMgr::Init()
{
	m_vCamPos = Vec2(0, 0);
	m_vCamScale = Vec2(1, 1);
}

void CameraMgr::SetPos(const Vec2 pos)
{
	m_vCamPos = Vec2(pos.x - Core::GetInst()->GetResolution().x / 2, 0.f);
	//m_vCamPos = pos;
}

void CameraMgr::AddPos(const int x, const int y)
{
	m_vCamPos.x += x;
	m_vCamPos.y += y;
}

