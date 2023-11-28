#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "SelectGDI.h"
#include "CameraMgr.h"
#include "Core.h"

UINT Collider::m_sNextID = 0;
Collider::Collider()
	: m_pOwner(nullptr)
	, m_vScale(Vec2(100.f,100.f))
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
	//Collider a, b;
	//a = b;
}

Collider::Collider(const Collider& _origin)
	: m_pOwner(nullptr)
	, m_vScale(_origin.m_vScale)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
}

Collider::~Collider()
{}

void Collider::Render(HDC _dc, bool isUI)
{
	//Core::GetInst()->GetPen(PEN_TYPE::GREEN);
	//Core::GetInst()->GetBrush(BRUSH_TYPE::HOLLOW);
	//SelectObject();
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_check)
		ePen = PEN_TYPE::RED;
	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);
	Vec2 vPos = m_pOwner->GetPos();
	Vec2 vScale = m_pOwner->GetScale();
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
	if(isUI)
		RECT_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	else
		RECT_RENDER(vRenderPos.x, vRenderPos.y, vRenderScale.x, vRenderScale.y, _dc);
}

void Collider::EnterCollision()
{
 	++m_check;
	m_pOwner->EnterCollision();
}

void Collider::ExitCollision()
{
	--m_check;
	m_pOwner->ExitCollision();
}

void Collider::StayCollision()
{
	m_pOwner->StayCollision();
}

void Collider::FinalUpdate()
{
	// Object위치를 따라가야 하는거야
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vObjPos = m_pOwner->GetPos();
	m_vFinalPos = vObjPos - vCamPos;
}

